// #include "../../LIB/STD.h"
// #include "../../LIB/ErrorStates.h"

// #include "PWM_Private.h"
// #include "PWM_Config.h"

// extern u8 PWM_u8_PWMCount;

// extern PWM_t PWM_astr_PWMList[];

// //APIs' implementations
// extern ErrorState_t PWM_enu_Initialization(void)
// {
//     u8 Local_u8_ErrorFlag = ES_OK;
//     u8 Local_u8_Counter = 0;
//     u8 Local_u8_Counter2 = 0;
//     u8 Local_au8_ErrorStatesArray[4] = {ES_NOK};

//     for(Local_u8_Counter = 0; Local_u8_Counter < PWM_u8_PWMCount; Local_u8_Counter++)
//     {

//         //Clock Selection Handling
//         enu_SetClockSelection(PWM_astr_PWMList[Local_u8_Counter].PwmNumber, PWM_astr_PWMList[Local_u8_Counter].ClockSelection);
        
//         //Waveformgeneraion Mode Handling
//         enu_SetWaveformGenerationMode(PWM_astr_PWMList[Local_u8_Counter].PwmNumber, PWM_astr_PWMList[Local_u8_Counter].WaveformGenerationMode);

//         //Compare Match Output Mode Handline
//         enu_SetOCxBehavior(PWM_astr_PWMList[Local_u8_Counter].PwmNumber, PWM_astr_PWMList[Local_u8_Counter].CompareMatchOutputMode);

//         //Handling Duty Cycle
//         enu_SetDutyCycle( PWM_astr_PWMList[Local_u8_Counter].PwmNumber, PWM_astr_PWMList[Local_u8_Counter].WaveformGenerationMode, PWM_astr_PWMList[Local_u8_Counter].CompareMatchOutputMode, PWM_astr_PWMList[Local_u8_Counter].DutyCycle);

//         //Error State Handling
//         for(Local_u8_Counter2 = 0; Local_u8_Counter2 < 4; Local_u8_Counter2++)
//         {
//             if(Local_au8_ErrorStatesArray[Local_u8_Counter2] != ES_OK)
//             {
//                 Local_u8_ErrorFlag = ES_NOK;
//             }
//         }


//     }



//     return Local_u8_ErrorFlag;
// }




// //Local functions' implementaions
// static ErrorState_t enu_SetClockSelection(u8 Copy_u8_PWMNumber, u8 Copy_u8_ClockSelection)
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;

//     switch (Copy_u8_PWMNumber)
//     {
//         case PWM_0:
//         {
//             //Clearing bits (CS02 CS01  CS00)
//             TCCR0 &= (0xF8);
            
//             switch (Copy_u8_ClockSelection)
//             {   

//                 case PWM_V_GND:
//                 {
//                     //bits already contain 000

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 } 
//                 case PWM_PS_1:
//                 {
//                     //Bits contain 001
//                     TCCR0 |= ( 1 << TCCR0_CS00);
                 
//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 } 
//                 case PWM_PS_8:
//                 {
//                     //Bits contain 010
//                     TCCR0 |= ( 1 << TCCR0_CS01);
                 
//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 } 
//                 case PWM_PS_64:
//                 {
//                     //Bits contain 011
//                     TCCR0 |= ( 3 << TCCR0_CS00);
                 
//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 } 
//                 case PWM_PS_256:
//                 {
//                     //Bits contain 100
//                     TCCR0 |= ( 1 << TCCR0_CS02);
                 
//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 } 
//                 case PWM_PS_1024:
//                 {
//                     //Bits contain 101
//                     TCCR0 |= ( 5 << TCCR0_CS00);
                 
//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 } 
                
//                 default:
//                 {
//                     Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//                     break;
//                 }
//             }
            
//             break;
//         }

//         case PWM_1:
//         {

//             break;
//         }

//         case PWM_2:
//         {

//             break;
//         }
        
//         default:
//         {
//             Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             break;
//         }
//     }

//     return Local_u8_ErrorFlag;   
// }

// static ErrorState_t enu_SetWaveformGenerationMode(u8 Copy_u8_PWMNumber, u8 Copy_u8_WaveformMode)
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;

//     switch (Copy_u8_PWMNumber)
//     {
//         case PWM_0:
//         {
//             //Clearing bits (WGM01 WGM00)
//             TCCR0 &= ~(1<< TCCR0_WGM00);
//             TCCR0 &= ~(1<< TCCR0_WGM01);

//             if(Copy_u8_WaveformMode == PWM_PHASE_MODE)
//             {
//                 //Bits contain 01
//                 TCCR0 |= (1 << TCCR0_WGM00);

//                 Local_u8_ErrorFlag = ES_OK;
//             }
//             else if(Copy_u8_WaveformMode == PWM_FAST_MODE)
//             {
//                 //Bits contain 11
//                 TCCR0 |= (3 << TCCR0_WGM00);

//                 Local_u8_ErrorFlag = ES_OK;
//             }
//             else
//             {
//                 Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             }
//             break;
//         }

//         case PWM_1:
//         {
            
//             break;
//         }
//         case PWM_2:
//         {
            
//             break;
//         }
        
//         default:
//         {
//             Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             break;
//         }
//     }

//     return Local_u8_ErrorFlag;   
// }

// static ErrorState_t enu_SetOCxBehavior (u8 Copy_u8_PWMNumber, u8 Copy_u8_OCxBehavior)
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;

//     switch (Copy_u8_PWMNumber)
//     {
//         case PWM_0:
//         {
//             //Clearing bits (COM01 COM00)
//             TCCR0 &= (0xCF);

//             if(Copy_u8_OCxBehavior == PWM_NON_INVERTING)
//             {
//                 //Bits contain 10
//                 TCCR0 |= (1 << TCCR0_COM01);

//                 Local_u8_ErrorFlag = ES_OK;
//             }
            
//             else if(Copy_u8_OCxBehavior == PWM_INVERTING)
//             {
//                 //Bits contain 11
//                 TCCR0 |= (3 << TCCR0_COM00);
                
//                 Local_u8_ErrorFlag = ES_OK;
//             }
//             else
//             {
//                 Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             }
            
//             break;
//         }

//         case PWM_1:
//         {

            
//             break;
//         }

//         case PWM_2:
//         {

            
//             break;
//         }
        
//         default:
//         {
//             Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             break;
//         }
//     }


//     return Local_u8_ErrorFlag;   
// }

// static ErrorState_t enu_SetDutyCycle (u8 Copy_u8_PWMNumber,u8 Copy_u8_WaveformMode, u8 Copy_u8_OcxBehavior, u8 Copy_f32_DutyCyclePercentage)
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;

//     switch (Copy_u8_PWMNumber)
//     {
//         case PWM_0:
//         {
//             if( Copy_f32_DutyCyclePercentage >= PWM_DUTY_CYCLE_0 && Copy_f32_DutyCyclePercentage <= PWM_DUTY_CYCLE_100)
//             {
//                 switch (Copy_u8_WaveformMode)
//                 {
//                     case    PWM_PHASE_MODE:
//                     {
//                         //Clearing bits
//                         OCR0 &= 0x00;

//                         if(Copy_u8_OcxBehavior == PWM_NON_INVERTING)
//                         {
//                             //Using Duty Cycle Rule for non-inverting fast PWM mode
//                             OCR0 = Copy_f32_DutyCyclePercentage*PWM_TCNT0_TOP;
                            
//                             Local_u8_ErrorFlag = ES_OK;
//                         }
//                         else if(Copy_u8_OcxBehavior == PWM_INVERTING)
//                         {
//                             //Using Duty Cycle Rule for non inverting fast PWM mode
//                             OCR0 = PWM_TCNT0_TOP* (1 - Copy_f32_DutyCyclePercentage );

//                             Local_u8_ErrorFlag = ES_OK;
//                         }
//                         else
//                         {
//                             Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//                         }

//                         break;
//                     }

//                     case    PWM_FAST_MODE:
//                     {
//                         if(Copy_u8_OcxBehavior == PWM_NON_INVERTING)
//                         {
//                             //Using Duty Cycle Rule for non-inverting fast PWM mode
//                             OCR0 = ((Copy_f32_DutyCyclePercentage)*(PWM_TCNT0_TOP + 1)) - 1;

//                             Local_u8_ErrorFlag = ES_OK;
//                         }
//                         else if(Copy_u8_OcxBehavior == PWM_INVERTING)
//                         {
//                             //Using Duty Cycle Rule for non inverting fast PWM mode
//                             OCR0 = PWM_TCNT0_TOP - ((Copy_f32_DutyCyclePercentage)*(PWM_TCNT0_TOP + 1));

//                             Local_u8_ErrorFlag = ES_OK;
//                         }
//                         else
//                         {
//                             Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//                         }

//                         break;
//                     }
                    
//                     default:
//                     {
//                         Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//                         break;
//                     }
//                 }
               
//             }
//             else
//             {
//                 Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             }
            
//             break;
//         }

//         case PWM_1:
//         {

//             break;
//         }

//         case PWM_2:
//         {

//             break;
//         }
        
//         default:
//         {
//             Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             break;
//         }
//     }

//     return Local_u8_ErrorFlag;   
// }
