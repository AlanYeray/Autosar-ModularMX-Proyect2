#include "HwIoAb_3_Buzzer.h"

#include "Pwm.h"

const Buzzer_Config *Pwm_ConfigPtr = NULL_PTR;
Buzzer_Config BuzzerControl[HWIOAB_BUTTONS_MAX];


void HwIoAb_Buzzer_Init(const Buzzer_Config *Config)
{   
    BuzzerControl[0].tone = CustomPeriod_5khz;
    BuzzerControl[1].tone = Custom1Period;

    Pwm_ConfigPtr = Config;
}

void HwIoAb_Buzzer_Beep(uint16 Tone)
{
    Pwm_SetPeriodAndDuty(Buzzer, Tone, DutyCyle_50);
}

void HwIoAb_Buzzer_Stop(void)
{
    /*Disable the PWM or set to IDLE*/
    Pwm_SetOutputToIdle(Buzzer);
}