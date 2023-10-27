#include "../LIB/STD.h"
#include "../LIB/ErrorStates.h"

#include "../HAL/L293D/L293D_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"

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
    u16 Local_u16_Vout = 0 ;
    f32 Local_f32_SpeedPercentage = 0;
    u8 Local_u8_Counter = 0;


    while(1)
    {
        //Reading quantized values
        ADC_enu_ReadPolling(ADC_ADC0, &Local_u16_Vout);

        //Converting Quantizied values into physical values
        enu_ConvertVoltageToDuty(Local_u16_Vout, &Local_f32_SpeedPercentage );

        //Setting Rotation Speed
        L293D_enu_SetRotationSpeed(L293D_H1, Local_f32_SpeedPercentage);

    }

}



//Local functions' implementations
static ErrorState_t enu_ConvertVoltageToDuty (u16 Copy_u16_ReadVoltage, f32* Copy_pf32_DutyValue)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    f32 Local_f32_Vin;

    if(Copy_pf32_DutyValue)
    {
        //The variable now contains the actual voltage on the ADC pin
        Local_f32_Vin = Copy_u16_ReadVoltage*(MOTOR_CONTROL_ADC_CONSTANT);\

        *Copy_pf32_DutyValue = (Local_f32_Vin/ MOTOR_CONTROL_POT_CONSTANT); 

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }

    return Local_u8_ErrorFlag;
}