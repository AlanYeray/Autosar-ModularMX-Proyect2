#include "Scheduler_Cfg.h"
#include "scheduler.h"
#include <stddef.h>


extern void Os_10ms_Task(void);
extern void Os_Task_leds(void);
extern void callback_timer(void);


const Timer_ConfigType TimerConfig[SCHEDULER_MAX_TIMERS] =
{
    {
        .InitTimeout = SCHEDULER_300MS_TIMER,
        .InitFlag= false,
        .callbackFunc = NULL_PTR
    },
};

const Task_ConfigType TaskConfig[SCHEDULER_MAX_TASKS] =
{
    {
        .Initperiod = SCHEDULER_10MS_TASK_PERIOD,
        .InitFlag= true,
        .taskFunc = Os_10ms_Task
    },
    {
        .Initperiod = SCHEDULER_20MS_TASK2_PERIOD,
        .InitFlag = true,
        .taskFunc = Os_Task_leds
    }

};

const Scheduler_ConfigType Scheduler_Config =
{
    .tick = SCHEDULER_TICK,
    .tasks = SCHEDULER_MAX_TASKS,
    .taskPtr = TaskConfig,
    .timers = SCHEDULER_MAX_TIMERS,
    .timerPtr = TimerConfig
};