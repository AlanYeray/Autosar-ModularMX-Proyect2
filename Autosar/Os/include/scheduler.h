#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdint.h>
#include <stdbool.h> 
#include "StandardTypes.h" //Std_ReturnType


typedef uint32 TickType; /*!< type for the tick counter */
typedef uint8 TaskType;  /*!< type for the number of task */
typedef uint8 TimerType; /*!< type for the number of software timers */


typedef struct _Task_ConfigType
{
    uint32 Initperiod;    /*How often the task shopud run in ms*/
    uint8 InitFlag;       /*flag to run task*/
    void (*taskFunc)(void); /*pointer to task function*/

} Task_ConfigType;

typedef struct _Schedched_Timer
{
    uint32 InitTimeout;       /*!< timer timeout to decrement and reload when the timer is re-started */
    uint8 InitFlag;           /*!< flag to start timer count */
    void (*callbackFunc)(void); /*!< pointer to callback function function */
} Timer_ConfigType;

/**
 * @brief structure to contain everything to run a scheduler
 *
 */
typedef struct _Scheduler_ConfigType
{
    TickType tick;                    /*the time base in ms*/
    TaskType tasks;                   /*number of task to handle*/
    const Task_ConfigType *taskPtr;   /*Pointer to buffer for the TCB tasks*/
    TimerType timers;                 /*number of software timer to use*/
    const Timer_ConfigType *timerPtr; /*Pointer to buffer timer array*/

} Scheduler_ConfigType;

extern uint32 taskBitField;
extern uint32 timerBitField;

#include "Scheduler_Cfg.h"

/**
 * @brief init al elements of the structure to zero
 *
 * @param scheduler [in] structure
 */
void Scheduler_Init(const Scheduler_ConfigType *scheduler);

/**
 * @brief function to runs all the tasks and the timers
 *
 *      main function of the scheduler
 *
 * @param scheduler [in] structure
 */
void Scheduler_MainFunction(void);



/**
 * @brief stop the task, prevents the scheduler from processing it
 *
 * @param scheduler [in] structure
 * @param task [in] the number of the task previusly registered
 * @retval uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_StopTask( TaskType task);

/**
 * @brief start the task,  the scheduler can processing it
 *
 *          set the flag
 *
 * @param scheduler [in] structure
 * @param task [in] the number of the task previusly registered
 * @retval uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_StartTask( TaskType task);

/**
 * @brief realod the period of the task and set the flag in 1
 *
 * @param scheduler [in] structure
 * @param task [in] the number of the task previusly registered
 * @param period [in] the time to start to processing it
 * @retval uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_periodTask( TaskType task, uint32_t period);

/**
 * @brief  return the count of the timer
 *
 * @param scheduler [in] structure
 * @param timer [in] the function to run when the timeout is out
 * @retval uint32_t return the milliseconds// count
 */
uint32_t Scheduler_GetTimer( TimerType timer);

/**
 * @brief change the value for the timeout and set flag in 1
 *
 * @param scheduler [in] structure
 * @param timer [in]s the number of the task previusly registered
 * @param timeout [in] the max count to wait
 * @retval uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_ReloadTimer( TimerType timer, uint32_t new_timeout);

/**
 * @brief start timer, set flag in 1 and reaload the timeout
 *
 * @param scheduler [in] structure
 * @param timer [in] the number of the task previusly registered
 * @return  uint8_t if it was succeeded or failed
 */
Std_ReturnType Scheduler_StartTimer( TimerType timer);

/**
 * @brief stop the timer and clear the flag
 *
 * @param scheduler [in] structure
 * @param timer [in] the number of the task previusly registered
 * @return uint8_t if it was succeeded or failed
 */
Std_ReturnType  Scheduler_StopTimer( TimerType timer);

#endif