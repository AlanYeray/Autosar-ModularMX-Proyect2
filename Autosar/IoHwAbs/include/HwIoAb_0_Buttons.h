#ifndef _HWIOAB_0_BUTTONS_H_
#define _HWIOAB_0_BUTTONS_H_

#include "StandardTypes.h"
#include "HwIoAb_Buttons_Cfg.h"
#include "Dio.h"

typedef enum
{

    HWIOAB_BTN_STATE_IDLE,         /*none activation had happedn yet*/
    HWIOAB_BTN_STATE_SINGLE_CLICK, /*single click*/
    HWIOAB_BTN_STATE_DOUBLE_CLICK, /*double click*/
    HWIOAB_BTN_STATE_HOLD_CLICK,   /*hold click*/
    HWIOAB_BTN_STATE_RELEASE       /*release*/

} ButtonEvents;

typedef enum
{

    HWIOAB_BTN_ACTIVE_LOW,         /*button is active low*/
    HWIOAB_BTN_ACTIVE_HIGH         /*button is active high*/

} ButtonActive;

//initial config AUTOSAR
typedef struct _HwIoAb_Buttons_Config
{
    Dio_ChannelType Button;     /*designated DIO channel where the button is connected*/
    uint8 Active;               /*if the button is active low or high*/
    uint32 Timeout;             /*timeout for the button press in ms*/
               
} HwIoAb_Buttons_Config;

//control struct for functions
typedef struct _ControlGeneral
{
    uint8 Event;
    uint32 Counter;
}ControlGeneral;

//control struct for btns
typedef struct _BtnsCtrl
{
    uint8_t Button; /*Dio channel where the button is connected*/
    uint8_t State;  /*state of the button state machine*/
    uint32_t Timer;  /*300ms timer ID*/
    uint8_t Active; /*if the button is active low or high*/
    uint8_t Led; //led reference
    uint8_t Pot;
    uint8_t flag;
} BtnsCtrl;


#include "HwIoAb_Buttons_Cfg.h"

/*external refrence to configuration structure array*/
extern const HwIoAb_Buttons_Config ButtonsCfg;//config autosar
extern BtnsCtrl stBtnMachine[HWIOAB_BUTTONS_MAX];


void HwIoAb_Buttons_Init( const HwIoAb_Buttons_Config *Buttons_Config );
uint8 HwIoAb_Buttons_GetEvent( uint8 Button );
void HwIoAb_Buttons_MainFunction( void );


#endif // _HWIOAB_BUTTONS_H_