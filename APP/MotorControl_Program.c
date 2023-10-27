#include "../LIB/STD.h"
#include "../LIB/ErrorStates.h"

#include "../HAL/L293D/L293D_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"

#include "MotorControl_Private.h"
#include "MotorControl_Config.h"



//APIs implementations
extern ErrorState_t MotorControl_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    //Initializes Timer and H-Bridge Modules
    L293D_enu_Initialization();

    //Initializes ADC
    ADC_enu_Initialization();

    return Local_u8_ErrorFlag;
}

extern ErrorState_t MotorControl_enu_OperateSystem(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    while(1)
    {

    }

    return Local_u8_ErrorFlag;

}



//Local functions' implementations