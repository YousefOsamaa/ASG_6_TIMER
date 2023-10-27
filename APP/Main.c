#include "../LIB/STD.h"
#include "../LIB/ErrorStates.h"

#include "../HAL/L293D/L293D_Interface.h"
#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"


void main (void)
{
    // Initializing L293D IC
	L293D_enu_Initialization();

    // L293D_enu_SetRotationDirection(L293D_H1, L293D_CCW);
    DIO_enu_SetPinDiretion(0,0,0);

    u32 Counter = 0;
    u8 flag = 0;
    
    while (1)
    {
        DIO_enu_GetPinValue(0, 0, &flag);

        if(flag)
        {
            L293D_enu_TurnOnMotor(L293D_H1, .5);
        }


    }



}