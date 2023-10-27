#include "../LIB/STD.h"
#include "../LIB/ErrorStates.h"

#include "MotorControl_Interface.h"


void main (void)
{
    //Initialization
    MotorControl_enu_Initialization();

    //Running the system
    MotorControl_enu_OperateSystem();


}