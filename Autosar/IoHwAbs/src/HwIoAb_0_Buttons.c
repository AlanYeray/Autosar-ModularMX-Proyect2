#include "HwIoAb_0_Buttons.h"

static const HwIoAb_Buttons_Config *HwIoAb_Ptr = NULL_PTR;
ControlGeneral GeneralControl[HWIOAB_BUTTONS_MAX];
BtnsCtrl stBtnMachine[HWIOAB_BUTTONS_MAX];

// static HwIoAb_Buttons_Config ButtonLocalControl; // copy to control for Buttons_Config

void HwIoAb_Buttons_Init(const HwIoAb_Buttons_Config *Buttons_Config)
{

    // config BtnsCtrl stBtnMachine
    for (uint8 i = 0; i < HWIOAB_BUTTONS_MAX; i++)
    {
        stBtnMachine[i].State = HWIOAB_BTN_STATE_IDLE;
        stBtnMachine[i].Active = HWIOAB_BTN_ACTIVE_LOW;

        GeneralControl[i].Event = HWIOAB_BTN_STATE_IDLE;

        GeneralControl[i].Counter = 0; // to start to count up to  HWIOAB_BUTTONS_1_TIMEOUT
    }

    stBtnMachine[0].Button = HWIOAB_BUTTONS_1_CHANNEL;
    stBtnMachine[1].Button = HWIOAB_BUTTONS_2_CHANNEL;

    stBtnMachine[0].Timer = HWIOAB_BUTTONS_1_TIMEOUT;
    stBtnMachine[1].Timer = HWIOAB_BUTTONS_2_TIMEOUT;

    stBtnMachine[0].Led = DioConf_DioChannel_C8_LED;
    stBtnMachine[1].Led = DioConf_DioChannel_C9_LED;

    // config puntero global a struc config
    HwIoAb_Ptr = Buttons_Config; // ptr a struct
}

uint8 HwIoAb_Buttons_GetEvent(uint8 Button)
{
    uint8 aux_event;
    uint8 aux;
    if (Button == HWIOAB_BUTTONS_1_CHANNEL)
    {
        aux = 0;
    }
    else if (Button == HWIOAB_BUTTONS_2_CHANNEL)
    {
        aux = 1;
    }
    else if (Button == HWIOAB_BUTTONS_3_CHANNEL)
    {
        aux = 2;
    }

    aux_event = GeneralControl[aux].Event;
    GeneralControl[aux].Event = HWIOAB_BTN_STATE_IDLE;
  
    return aux_event;
}

void HwIoAb_Buttons_MainFunction(void)
{
    for (uint8_t i = 0; i < HWIOAB_BUTTONS_MAX; i++)
    {

        switch (stBtnMachine[i].State)
        {
        case HWIOAB_BTN_STATE_IDLE:
            // query for the first time the button is press
            if (Dio_ReadChannel(stBtnMachine[i].Button) == STD_LOW)
            {
                stBtnMachine[i].State = HWIOAB_BTN_STATE_SINGLE_CLICK;
                GeneralControl[i].Event = HWIOAB_BTN_STATE_SINGLE_CLICK;

                // GeneralControl[i].Counter += HWIOAB_BUTTONS_PERIOD;
                GeneralControl[i].Counter = 0;
             
            }
            break;

        case HWIOAB_BTN_STATE_SINGLE_CLICK: // here is single release
            GeneralControl[i].Counter += HWIOAB_BUTTONS_PERIOD;
            if (GeneralControl[i].Counter >= stBtnMachine[i].Timer)
            {
                stBtnMachine[i].State = HWIOAB_BTN_STATE_HOLD_CLICK;
                GeneralControl[i].Event = HWIOAB_BTN_STATE_HOLD_CLICK;
                // GeneralControl[i].Counter = 0; // start again
            }
            else if (Dio_ReadChannel(stBtnMachine[i].Button) == STD_HIGH)
            {
                stBtnMachine[i].State = HWIOAB_BTN_STATE_RELEASE;
                GeneralControl[i].Event = HWIOAB_BTN_STATE_RELEASE;
                // GeneralControl[i].Counter += HWIOAB_BUTTONS_PERIOD;

            } // query ifs there is a timeout
            break;
        case HWIOAB_BTN_STATE_RELEASE:

            GeneralControl[i].Counter += HWIOAB_BUTTONS_PERIOD;
            // Checking count timeout.
            if (GeneralControl[i].Counter >= stBtnMachine[i].Timer) // no button pressed and timer end
            {
                GeneralControl[i].Event = HWIOAB_BTN_STATE_IDLE;
                stBtnMachine[i].State = HWIOAB_BTN_STATE_IDLE;
            }
            else if (Dio_ReadChannel(stBtnMachine[i].Button) == STD_LOW)
            {
                // GeneralControl[i].Counter += HWIOAB_BUTTONS_PERIOD;

                stBtnMachine[i].State = HWIOAB_BTN_STATE_DOUBLE_CLICK;
                GeneralControl[i].Event = HWIOAB_BTN_STATE_DOUBLE_CLICK;
      
            }
            break;

        case HWIOAB_BTN_STATE_DOUBLE_CLICK:
            // query if release
            // if release is a duble click
            // query if timeout
            GeneralControl[i].Counter += HWIOAB_BUTTONS_PERIOD;
            if (GeneralControl[i].Counter >= stBtnMachine[i].Timer)
            {
                // here is HOLD
                stBtnMachine[i].State = HWIOAB_BTN_STATE_HOLD_CLICK;
                GeneralControl[i].Event = HWIOAB_BTN_STATE_HOLD_CLICK;
            }
            else if (Dio_ReadChannel(stBtnMachine[i].Button) == STD_LOW)
            {
                // here is IDLE
                GeneralControl[i].Event = HWIOAB_BTN_STATE_DOUBLE_CLICK;
                stBtnMachine[i].State = HWIOAB_BTN_STATE_IDLE;
            }
            break;

        case HWIOAB_BTN_STATE_HOLD_CLICK:
            // if state jumps here is a hold click
            // wait until botton is released and go back to IDLE
            if (Dio_ReadChannel(stBtnMachine[i].Button) == STD_HIGH)
            {
                GeneralControl[i].Event = HWIOAB_BTN_STATE_IDLE;
                stBtnMachine[i].State = HWIOAB_BTN_STATE_IDLE;
                HwIoAb_Buzzer_Stop();
            }
            break;

        default:
            // if jump here is a error
            GeneralControl[i].Event = HWIOAB_BTN_STATE_IDLE;
            stBtnMachine[i].State = HWIOAB_BTN_STATE_IDLE;

            break;
        }
    }
}