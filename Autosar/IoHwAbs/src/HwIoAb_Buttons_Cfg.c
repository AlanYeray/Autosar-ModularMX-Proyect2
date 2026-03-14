
#include "HwIoAb_Buttons_Cfg.h"
#include "HwIoAb_0_Buttons.h"
#include "Dio.h"

//----------------------------------------------Autosar-*
const HwIoAb_Buttons_Config ButtonsCfg =
{
        .Button = HWIOAB_BUTTONS_1_CHANNEL, /*designated DIO channel where the button is connected*/
        .Active = HWIOAB_BTN_ACTIVE_LOW,    /*if the button is active low or high*/
        .Timeout = HWIOAB_BUTTONS_1_TIMEOUT /*timeout for the button press in ms*/
};
