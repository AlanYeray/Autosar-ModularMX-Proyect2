/**
 * @file main.c
 * @author Alan Yeray Olivas
 * @brief here we used all the interfaces
 * @version 0.1
 * @date 2024-05-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdint.h>
#include <stdbool.h>

#include "scheduler.h"
#include "SEGGER_RTT.h"
#include "Det.h"
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Osif.h"
#include "Gpt.h"
#include "Platform.h"
#include "Adc.h"
#include "Pwm.h"
#include "IoHwAb.h"

#include "HwIoAb_0_Buttons.h"
#include "HwIoAb_1_Leds.h"
#include "HwIoAb_2_Pots.h"
#include "HwIoAb_3_Buzzer.h"

void EcuM_Init(void);
void callback_timer(void);
void Delay(uint32 ms);

// 300ms -> (0.300 * 48Mhz)/128 preescaler = 112500

int main(void)
{
    EcuM_Init();
    SEGGER_RTT_Init();
    Scheduler_Init(&Scheduler_Config); // tick = 10ms

    Port_Init(NULL_PTR);

    Scheduler_MainFunction();

    while (1)
    {
    }

    return 0;
}

void EcuM_Init(void)
{
    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuClockSettingConfig_0);
    // Mcu_DistributePllClock();
    // while( Mcu_GetPllStatus() != MCU_PLL_LOCKED );
    Mcu_SetMode(McuModeSettingConf_0);
    Platform_Init(NULL_PTR);
    Gpt_Init(&Gpt_Config);
    OsIf_Init(NULL_PTR); /*Init the internal tick reference Systick Timer*/
    Port_Init(&Port_Config);
    Adc_Init(&Adc_Config);
    Pwm_Init(&Pwm_Config);
    IoHwAb_Init0(NULL_PTR);
}

void Os_10ms_Task(void)
{
    HwIoAb_Buttons_MainFunction();
}
void Os_Task_leds(void)
{
    for (uint8 i = 0; i < HWIOAB_BUTTONS_MAX; i++)
    {
        uint8 buttonEvent = HwIoAb_Buttons_GetEvent(stBtnMachine[i].Button);

        if (buttonEvent == HWIOAB_BTN_STATE_RELEASE)
        {
            HwIoAb_Leds_TurnToggle(stBtnMachine[i].Led);
        }
        else if (buttonEvent == HWIOAB_BTN_STATE_DOUBLE_CLICK)
        {
            uint16 dataAdc[2];
            uint16 dataAdc1;
            if (stBtnMachine[i].Button == HWIOAB_BUTTONS_1_CHANNEL)
            {
                HwIoAb_Pots_GetValue(&dataAdc);
                SEGGER_RTT_printf(0, "Adc0 value: %d \n", dataAdc[1]);
            }
            else if (stBtnMachine[i].Button == HWIOAB_BUTTONS_2_CHANNEL)
            {
                HwIoAb_Pots_GetAltValue(&dataAdc1);
                SEGGER_RTT_printf(0, "Adc1 value: %d \n", dataAdc1);
            }
        }
        else if (buttonEvent == HWIOAB_BTN_STATE_HOLD_CLICK)
        {

            if (Dio_ReadChannel(stBtnMachine[i].Button) == HWIOAB_BTN_ACTIVE_HIGH)
            {
                HwIoAb_Buzzer_Stop();
            }
            else
            {
                HwIoAb_Buzzer_Beep(BuzzerControl[i].tone);
            }
        }
    }
}

void callback_timer(void)
{
    SEGGER_RTT_printf(0, "timer 300ms done \n");
}
void Delay(uint32 ms)
{
    uint32 Timeout = OsIf_MicrosToTicks(ms * 1000u, OSIF_COUNTER_SYSTEM);
    uint32 SeedTick = OsIf_GetCounter(OSIF_COUNTER_SYSTEM);
    uint32 ElapsedTime = 0u;
    do
    {
        ElapsedTime += OsIf_GetElapsed(&SeedTick, OSIF_COUNTER_SYSTEM);
    } while (ElapsedTime < Timeout);
}