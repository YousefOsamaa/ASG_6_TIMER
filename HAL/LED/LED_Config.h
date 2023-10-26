#ifndef LED_CONFIG_FILE
#define LED_CONFIG_FILE




#include "../../MCAL/DIO/DIO_Interface.h"

//Number of LEDS
#define LED_COUNT      3

//LEDs Groups and Pins
#define LED_0_GROUP        DIO_PIN_GROUP_A
#define LED_0_PIN          DIO_PIN_7

#define LED_1_GROUP        DIO_PIN_GROUP_A 
#define LED_1_PIN          DIO_PIN_6

#define LED_2_GROUP        DIO_PIN_GROUP_A
#define LED_2_PIN          DIO_PIN_5


//LED struct
typedef struct 
{
    u8 LED_Group;
    u8 LED_Pin;
    
}LED_t;


#endif
