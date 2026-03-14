#include "HwIoAb_2_Pots.h"
#include "SEGGER_RTT.h"

static const Pots_Config *HwIoAb_Adc_Ptr = NULL_PTR;
extern void Delay(uint32 ms);

// ADC0 -> Pot0
Adc_CalibrationStatusType CalibStatus;
Adc_ValueGroupType ResultBuffer[3];

// ADC1 -> Pot1
Adc_CalibrationStatusType CalibStatus1;
Adc_ValueGroupType ResultBuffer1[3];

void HwIoAb_Pots_Init(const Pots_Config *Config)
{
    // ADC0 -> Pot0
    Port_Ci_Port_Ip_SetMuxModeSel(IP_PORTB, 13, PORT_MUX_ADC_INTERLEAVE);
    /*calibrate ADC module*/
    Adc_Calibrate(AdcHwUnit_0_hwio, &CalibStatus);
    /*Set the memeory buffer to store convertions*/
    Adc_SetupResultBuffer(AdcGroup_0_hwio, ResultBuffer);

    // ADC1 -> Pot1
    /*calibrate ADC module*/
    Adc_Calibrate(AdcHwUnit_1_hwio, &CalibStatus1);
    /*Set the memeory buffer to store convertions*/
    Adc_SetupResultBuffer(Adc1Group_0_hwio, ResultBuffer1);
    // config puntero global a struc config
    HwIoAb_Adc_Ptr = Config;
}
void HwIoAb_Pots_GetValue(uint16 *Pots)
{
    /*Software trigger convertion*/
    Adc_StartGroupConversion(AdcGroup_0_hwio);
    /*wait until the convertion is done*/
    while (Adc_GetGroupStatus(AdcGroup_0_hwio) == ADC_BUSY)
        ;
    /*Read ready convertion*/
    Adc_ReadGroup(AdcGroup_0_hwio, (uint16 *)Pots);
}

void HwIoAb_Pots_GetAltValue(uint16 *AltPots)
{
    // ADC1
    Adc_StartGroupConversion(Adc1Group_0_hwio);
    /*wait until the convertion is done*/
    while (Adc_GetGroupStatus(Adc1Group_0_hwio) == ADC_BUSY)
        ;
    /*Read ready convertion*/
    Adc_ReadGroup(Adc1Group_0_hwio, (uint16 *)AltPots);
}