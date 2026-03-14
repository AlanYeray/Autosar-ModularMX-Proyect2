#include "HwIoAb_1_Leds.h"
#include "Dio.h"

void HwIoAb_Leds_TurnOn( uint8 Led )
{
    Dio_WriteChannel(Led, STD_ON);
}
void HwIoAb_Leds_TurnOff( uint8 Led )
{
    Dio_WriteChannel(Led, STD_OFF);
}
void HwIoAb_Leds_TurnToggle( uint8 Led )
{
    Dio_FlipChannel(Led);
}