

#ifndef SCHEDULER_CFG_H_
#define SCHEDULER_CFG_H_


#include "scheduler.h"

#define SCHEDULER_TICK 10

#define SCHEDULER_MAX_TASKS 2
#define SCHEDULER_MAX_TIMERS 0

#define SCHEDULER_300MS_TIMER 300

#define SCHEDULER_10MS_TASK         0
#define SCHEDULER_10MS_TASK2        1

#define SCHEDULER_10MS_TASK_PERIOD    10
#define SCHEDULER_20MS_TASK2_PERIOD   20

extern const Scheduler_ConfigType Scheduler_Config;


#endif 