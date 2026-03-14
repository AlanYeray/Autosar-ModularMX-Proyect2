#ifndef HWIOAB_3_BUZZER_H
#define HWIOAB_3_BUZZER_H

#include "StandardTypes.h"
#include "HwIoAb_2_Pots.h"
#include "HwIoAb_0_Buttons.h"
#include "Pwm.h"

typedef struct _Buzzer_Config
{
    uint8 tone;
    uint16 period;
    uint16 dutyCycle;
} Buzzer_Config;


extern Buzzer_Config BuzzerControl[HWIOAB_BUTTONS_MAX];

#define Buzzer PwmChannel_0

#define DutyCyle_25 0x2000
#define DutyCyle_50 0x4000
#define DutyCyle_75 0x6000
#define DutyCyle_100 0x8000

#define CustomPeriod_5khz 200
#define Custom1Period 100
#define Custom2Period 300

#define Period_100 37500
#define Period_50 18750

void HwIoAb_Buzzer_Init(const Buzzer_Config *Config);
void HwIoAb_Buzzer_Beep(uint16 Tone);
void HwIoAb_Buzzer_Stop(void);

#endif
