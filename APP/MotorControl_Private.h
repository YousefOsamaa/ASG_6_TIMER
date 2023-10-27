#ifndef MOTORCONTROL_PRRIVATE_FILE
#define MOTORCONTROL_PRRIVATE_FILE


#define MOTOR_CONTROL_ADC_CONSTANT   (5.0f/1024)

#define MOTOR_CONTROL_POT_CONSTANT   (5UL)



//Local functions' prototypes
static ErrorState_t enu_ConvertVoltageToDuty (u16 Local_u16_ReadVoltage, f32* Local_pf32_DutyValue);

#endif