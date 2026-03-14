#ifndef _HWIOAB_2_POTS_H_
#define _HWIOAB_2_POTS_H_

#include "StandardTypes.h"
#include "Adc.h"
#include "Adc_Types.h"
#include "Port_Ci_Port_Ip.h"
#include "Adc_Ipw_CfgDefines.h"
#include "Adc_Ip_Types.h"
#include "Adc_Ipw_Types.h"
#include "Pdb_Adc_Ip_Types.h"
#include "Adc_CfgDefines.h"
#include "Port_Cfg.h"

//ADC0
#define AdcHwUnit_0_hwio    AdcHwUnit_0
#define AdcChannel_0_hwio   AdcChannel_0
#define AdcChannel_1_hwio   AdcChannel_1
#define AdcGroup_1_hwio     Adc1Group_0
#define AdcGroup_0_hwio     AdcGroup_0

//ADC1
#define AdcHwUnit_1_hwio        AdcHwUnit_1
#define Adc1Channel_0_hwio      Adc1Channel_0
#define Adc1Channel_1_hwio      Adc1Channel_1
#define Adc1Group_0_hwio        Adc1Group_0_Adc1Channel_0

//pot1
#define Pot1Port_CH5    PortConf_PortPin_ADC_CH5

//pot2
#define Pot2Port_CH8    PortConf_PortPin_ADC_CH8

//BUZZER port pin
#define BuzzerPort      PortConf_PortPin_A13_PIN
 
 

typedef struct _Pots_Config
{
    uint16 *PotPtr;
    uint16 *BuzzerPtr;
} Pots_Config;

void HwIoAb_Pots_Init(const Pots_Config *Config);
void HwIoAb_Pots_GetValue(uint16 *Pots);
void HwIoAb_Pots_GetAltValue(uint16 *AltPots);

#endif