#include "../LIB/STD.h"
#include "../LIB/ErrorStates.h"

#include "../HAL/L293D/L293D_Interface.h"
#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"


void main (void)
{
    // Initializing L293D IC
	L293D_enu_Initialization();


}