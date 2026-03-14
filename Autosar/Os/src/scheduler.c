/**
 * @file scheduler.c
 * @author Alan Yeray Olivas
 * @brief funtions to work on manage the scheduler
 * @version 0.1
 * @date 2024-05-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdint.h>
#include <stdbool.h>
#include "scheduler.h"
#include "Osif.h"
#include "Bfx.h"
#include "Scheduler_Cfg.h"

typedef struct _SchedulerCtrl
{
    uint32_t TaskElapsed[SCHEDULER_MAX_TASKS];
    uint32_t TaskPeriod[SCHEDULER_MAX_TASKS];
    uint32_t TimerCount[SCHEDULER_MAX_TIMERS];
    uint32_t TimerTimeout[SCHEDULER_MAX_TIMERS];
    // uint32_t TaskFlags;
    // uint32_t TimerFlags;
    uint32_t elapsedTime;
    TimerType timersCount;
    uint32_t timeoutMicros;
    uint32_t SeedTick;
} SchedulerCtrl;

uint32_t taskBitField;
uint32_t timerBitField;

/**
 * @defgroup <1 AND 0> macro to define 1s and 0s inside of conditionals
 *
 */
#define SET 1
#define CLEAR 0
#define TIMEOUT_FACTOR 1000

static const Scheduler_ConfigType *SchedulerLocal = NULL_PTR;
static SchedulerCtrl SchedulerControl;

/**
 * @brief init al elements of the structure to zero
 *
 * @param scheduler [in] structure
 */
void Scheduler_Init(const Scheduler_ConfigType *scheduler)
{
    /*  Save configuration pointer in global variable */
    SchedulerLocal = scheduler;

    // bitfield flags for task and timers
    taskBitField = 0;
    timerBitField = 0;

    // vaciar InitTimeot a timeout de la estructura de control del scheduler
    for (uint8_t i = 0; i < SCHEDULER_MAX_TIMERS; i++)
    {
        SchedulerControl.TimerTimeout[i] = SchedulerLocal->timerPtr[i].InitTimeout;
        SchedulerControl.TimerCount[i] = SchedulerLocal->timerPtr[i].InitTimeout;
    }

    // vacir InitFlag de timers en variable de control

    if (SCHEDULER_MAX_TIMERS <= 1)
    {
        for (uint8_t i = 0; i < SCHEDULER_MAX_TIMERS; i++)
        {
            Bfx_SetBit_u32u8(&timerBitField, i);
        }
    }

    // vacir InitFlag en Tasks en variable de control
    for (uint8_t i = 0; i < SCHEDULER_MAX_TASKS; i++)
    {
        Bfx_SetBit_u32u8(&taskBitField, i);
    }

    // reference clock
    SchedulerControl.SeedTick = OsIf_GetCounter(OSIF_COUNTER_SYSTEM);
}

/**
 * @brief function to runs all the tasks and the timers
 *
 *      main function of the scheduler
 *
 * @param scheduler [in] structure
 */
void Scheduler_MainFunction(void)
{
    // This is the function in charge of running the task init functions one single time and actual run each registered task according to their periodicity in an infinite loop, the function
    // will never return at least something wrong happens, but this will be considered a malfunction. A timer will need to accomplish this purpose, for practical reasons,

    // set reference timeout
    SchedulerControl.timeoutMicros = OsIf_MicrosToTicks(SCHEDULER_TICK * TIMEOUT_FACTOR, OSIF_COUNTER_SYSTEM);

    // start scheduler
    while (1)
    {

        SchedulerControl.elapsedTime += OsIf_GetElapsed(&SchedulerControl.SeedTick, OSIF_COUNTER_SYSTEM);

        if (SchedulerControl.elapsedTime >= SchedulerControl.timeoutMicros)
        {

            // Handle timers
            for (uint8_t i = 0; i < SCHEDULER_MAX_TIMERS; i++) // Handle timers
            {
                // if (SchedulerLocal->timerPtr[i].InitFlag == 1)
                if (Bfx_GetBit_u32u8_u8(timerBitField, i) == 1) // startFlag
                {
                    SchedulerControl.TimerCount[i] -= SchedulerLocal->tick;

                    if (SchedulerControl.TimerCount[i] == 0)
                    {

                        SchedulerLocal->timerPtr[i].callbackFunc();

                        // clear flag timer because count end
                        Bfx_ClrBit_u32u8(&timerBitField, i);
                    }
                }
            }

            // Heart of the scheduler code
            for (uint8_t i = 0; i < SCHEDULER_MAX_TASKS; i++)
            {
                SchedulerControl.TaskElapsed[i] += SchedulerLocal->tick;

                // if (SchedulerLocal->taskPtr[i].InitFlag == 1)
                if (Bfx_GetBit_u32u8_u8(taskBitField, i) == 1)
                {
                    if (SchedulerControl.TaskElapsed[i] >= SchedulerLocal->taskPtr[i].Initperiod) // scheduler->taskPtr[i].period
                    {

                        SchedulerLocal->taskPtr[i].taskFunc();
                        SchedulerControl.TaskElapsed[i] = 0;
                    }
                    SchedulerControl.elapsedTime = 0; // restart timeout
                }
            }
        }
    }
}

/**
 * @brief stop the task, prevents the scheduler from processing it
 *
 *          clear the flag
 *
 * @param scheduler [in] structure
 * @param task [in] the number of the task previusly registered
 * @retval uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_StopTask(TaskType task)
{

    if (Bfx_GetBit_u32u8_u8(taskBitField, task) == SET) // scheduler->taskPtr[task - 1].startFlag
    {
        Bfx_ClrBit_u32u8(&taskBitField, task); // scheduler->taskPtr[task - 1].startFlag = CLEAR;

        return true;
    }

    return false;
}

/**
 * @brief start the task,  the scheduler can processing it
 *
 *          set the flag
 *
 * @param scheduler [in] structure
 * @param task [in] the number of the task previusly registered
 * @retval uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_StartTask(TaskType task)
{

    if (Bfx_GetBit_u32u8_u8(taskBitField, task) == 0)
    {
        Bfx_SetBit_u32u8(&taskBitField, task);

        return true; // set to start
    }

    return false;
    // Once a task is stopped using the function Scheduler_StopTask, it can be active again using this function. The second parameter indicates the task to be started, which is a
    // number from 1 to n task registered. Number zero is forbidden. the function will return a TRUE if the task was stopped otherwise returns FALSE
}

/**
 * @brief realod the period of the task and set the flag in 1
 *
 * @param scheduler [in] structure
 * @param task [in] the number of the task previusly registered
 * @param period [in] the time to start to processing it
 * @retval uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_periodTask(TaskType task, uint32_t period)
{
    // The new periodicity shall be a multiple of the tick value otherwise won’t be affected by the new period. The second parameter indicates the task to be started, which is a number
    // from 1 to n task registered. Number zero is forbidden. the function will return a TRUE if the task was stopped otherwise returns FALSE.

    if (period >= SchedulerLocal->tick && period % SchedulerLocal->tick == 0)
    {
        SchedulerControl.TaskPeriod[task - 1] = period;
        // scheduler->taskPtr[task - 1].period = period; // always be multiple
        return true;
    }

    return false;
}

/**
 * @brief  return the count of the timer
 *
 * @param scheduler [in] structure
 * @param timer [in] the number of the task previusly registered
 * @retval uint32_t return the milliseconds// count
 */
uint32_t Scheduler_GetTimer(TimerType timer)
{

    if (Bfx_GetBit_u32u8_u8(timerBitField, timer - 1) == 1) // check timer is registered
    {
        return SchedulerControl.TimerCount[timer - 1]; // scheduler->timerPtr[timer - 1].count;
    }

    return 0; // timer does not been registered the function returns a zero value
}

/**
 * @brief change the value for the timeout and set flag in 1
 *
 * @param scheduler [in] structure
 * @param timer [in] the number of the task previusly registered
 * @param timeout [in] the max count to wait
 * @retval uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_ReloadTimer(TimerType timer, uint32_t new_timeout)
{
    // The timer will be reloaded with a new value in milliseconds it will also start the timer
    SchedulerControl.TimerCount[timer - 1] = new_timeout;
    SchedulerControl.TimerTimeout[timer - 1] = new_timeout;

    Bfx_SetBit_u32u8(&timerBitField, timer); // startFlag = 1;
    return 1;                                // succeed
}

/**
 * @brief start timer, set flag in 1 and reaload the timeout
 *
 * @param scheduler [in] structure
 * @param timer [in] the number of the task previusly registered
 * @return  uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_StartTimer(TimerType timer)
{
    // check timer is registered
    if ((timer <= SCHEDULER_MAX_TIMERS))
    {
        // reset flag  to 1
        Bfx_SetBit_u32u8(&timerBitField, timer - 1);

        // restart the timer
        SchedulerControl.TimerCount[timer - 1] = SchedulerControl.TimerTimeout[timer - 1];

        return 1; // succeed
    }

    return 0; // timer to start has not been registered no action will be taken and it will return a zero
}

/**
 * @brief stop the timer and clear the flag
 *
 * @param scheduler [in] structure
 * @param timer [in] the number of the task previusly registered
 * @return uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_StopTimer(TimerType timer)
{

    if (timer <= SCHEDULER_MAX_TIMERS) // check timer is registered
    {
        Bfx_ClrBit_u32u8(&timerBitField, timer - 1); // startflag = 0
        return 1;                                    // succeed
    }
    return 0; // timer to start has not been registered no action will be taken and it will return a zero
}
