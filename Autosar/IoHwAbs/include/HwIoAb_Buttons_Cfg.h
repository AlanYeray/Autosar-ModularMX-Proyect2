


#ifndef _HWIOAB_BUTTONS_CFG_H_
#define _HWIOAB_BUTTONS_CFG_H_

#include "Dio.h"
#include "Scheduler_Cfg.h"


// 300ms -> (0.300 * 48Mhz)/128 preescaler = 112500
#define TIME_300MS 300

#define HWIOAB_BUTTONS_MAX 2        /*max number of buttons to manage*/

#if (SCHEDULER_TICK == 10)
    #define HWIOAB_BUTTONS_PERIOD   SCHEDULER_TICK     /*periodicity for the main function in milliseonds*/
#else   
    #define HWIOAB_BUTTONS_PERIOD   10
#endif 

#define HWIOAB_BUTTONS_1_TIMEOUT    TIME_300MS    /*timeout for the button press in ms*/
#define HWIOAB_BUTTONS_1_CHANNEL    DioConf_DioChannel_E12_BTN0  /*designated DIO channel where the button is connected*/

#define HWIOAB_BUTTONS_2_TIMEOUT    TIME_300MS    /*timeout for the button press in ms*/
#define HWIOAB_BUTTONS_2_CHANNEL    DioConf_DioChannel_D17_BTN1 /*designated DIO channel where the button is connected*/

#define HWIOAB_BUTTONS_3_TIMEOUT    TIME_300MS    /*timeout for the button press in ms*/
#define HWIOAB_BUTTONS_3_CHANNEL    DioConf_DioChannel_A12_BTN2  /*designated DIO channel where the button is connected*/








#endif // _HWIOAB_BUTTONS_CFG_H_
