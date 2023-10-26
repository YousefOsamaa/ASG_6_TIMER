// #include "../../LIB/STD.h"
// #include "../../LIB/ErrorStates.h"

// #include "Timers_Private.h" 
// #include "Timers_Config.h"

// extern u8 Timers_u8_Count;
// extern Timers_t Timers_astr_TimerList [];

// static void (* apfun_ISRpointers[TIMER_ISR_COUNT])(void*)= { NULL};
// static void* apvid_ISRParameters[TIMER_ISR_COUNT] = {NULL};

// //APIs' implementations
// extern ErrorState_t Timers_enu_Initialization(void)
// {
//     ErrorState_t Local_u8_ErrorFlag = ES_OK;
//     u8 Local_au8_ErrorStates [4] ={0};
//     u8 Local_u8_Counter = 0;
//     u8 Local_u8_Counter2 = 0;

//     for(Local_u8_Counter = 0; Local_u8_Counter < Timers_u8_Count; Local_u8_Counter++)
//     {
//         //Setting Clock Selection
//         Local_au8_ErrorStates[0] =  enu_SetClockSelection(Timers_astr_TimerList[Local_u8_Counter].TimerNumber, Timers_astr_TimerList[Local_u8_Counter].ClockSelection);

//         //Setting Waveform generation Mode
//         Local_au8_ErrorStates[1] =  enu_SetWaveformGenerationMode(Timers_astr_TimerList[Local_u8_Counter].TimerNumber, Timers_astr_TimerList[Local_u8_Counter].WaveformGenerationMode);

//         //Setting Compare Match Output Mode (Ocx Behavior) 
//         Local_au8_ErrorStates[2] = enu_SetOCxPinBehavior(Timers_astr_TimerList[Local_u8_Counter].TimerNumber, Timers_astr_TimerList[Local_u8_Counter].CompareMatchOutputMode);

//         //Setting Interrupt Mode
//         Local_au8_ErrorStates[3] = enu_SetInterruptMode(Timers_astr_TimerList[Local_u8_Counter].TimerNumber, Timers_astr_TimerList[Local_u8_Counter].WaveformGenerationMode, Timers_astr_TimerList[Local_u8_Counter].InterruptMode);

//       for (Local_u8_Counter2 = 0; Local_u8_Counter < 4; Local_u8_Counter2++ )
//       {
//         if(Local_au8_ErrorStates[Local_u8_Counter2] == ES_NOK)
//         {
//             Local_u8_ErrorFlag = ES_NOK;
//         }
//       }
    
//     }



//     return Local_u8_ErrorFlag;
// }

// extern ErrorState_t Timers_enu_SetCallBack (u8 Copy_u8_TimerNumber, u8 Copy_u8_WaveformMode, void (* Copy_pfun_AppFunction)(void*), void* Copy_pvid_Parameters)
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;

//     if(Copy_pfun_AppFunction)
//     {
//         switch (Copy_u8_TimerNumber)
//         {
//             case TIMERS_0:
//             {
//                 if(Copy_u8_WaveformMode == TIMERS_OVERFLOW_MODE)
//                 {
//                     apfun_ISRpointers[TIMERS_0_OVERFLOW_ISR] = Copy_pfun_AppFunction;

//                     apvid_ISRParameters[TIMERS_0_OVERFLOW_ISR] = Copy_pvid_Parameters;

//                     Local_u8_ErrorFlag = ES_OK;
//                 }
//                 else if (Copy_u8_WaveformMode == TIMERS_CTC_MODE)
//                 {
//                     apfun_ISRpointers[TIMERS_0_CTC_ISR] = Copy_pfun_AppFunction;

//                     apvid_ISRParameters[TIMERS_0_CTC_ISR] = Copy_pvid_Parameters;

//                     Local_u8_ErrorFlag = ES_OK;                    
//                 }
//                 else
//                 {
//                     Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//                 }
                
//                 break;
//             }
//             case TIMERS_1:
//             {
                
//                 break;
//             }
//             case TIMERS_2:
//             {
//                 if(Copy_u8_TimerNumber == TIMERS_OVERFLOW_MODE)
//                 {
//                     apfun_ISRpointers[TIMERS_2_OVERFLOW_ISR] = Copy_pfun_AppFunction;

//                     apvid_ISRParameters[TIMERS_2_OVERFLOW_ISR] = Copy_pvid_Parameters;

//                     Local_u8_ErrorFlag = ES_OK;
//                 }
//                 else if (Copy_u8_WaveformMode == TIMERS_CTC_MODE)
//                 {
//                     apfun_ISRpointers[TIMERS_2_CTC_ISR] = Copy_pfun_AppFunction;

//                     apvid_ISRParameters[TIMERS_2_CTC_ISR] = Copy_pvid_Parameters;

//                     Local_u8_ErrorFlag = ES_OK;                    
//                 }
//                 else
//                 {
//                     Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//                 }
                
                
//                 break;
//             }
            
//             default:
//             {
//                 Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//                 break;
//             }
//         }
//     }   
//     else
//     {
//         Local_u8_ErrorFlag = ES_NULL_POINTER;
//     }

//     return Local_u8_ErrorFlag;
// }


// //ISR
// void __vector_4(void)__attribute__((signal));
// void __vector_5(void)__attribute__((signal));
// void __vector_10(void)__attribute__((signal));
// void __vector_11(void)__attribute__((signal));

// void __vector_4 (void)
// {
//     if(apfun_ISRpointers[TIMERS_2_CTC_ISR])
//     {
//         apfun_ISRpointers[TIMERS_2_CTC_ISR](apvid_ISRParameters[TIMERS_2_CTC_ISR]);
//     }
// }

// void __vector_5 (void)
// {
//     if(apfun_ISRpointers[TIMERS_2_OVERFLOW_ISR])
//     {
//         apfun_ISRpointers[TIMERS_2_OVERFLOW_ISR](apvid_ISRParameters[TIMERS_2_OVERFLOW_ISR]);
//     }
// }

// void __vector_10 (void)
// {
//     if(apfun_ISRpointers[TIMERS_0_CTC_ISR])
//     {
//         apfun_ISRpointers[TIMERS_0_CTC_ISR](apvid_ISRParameters[TIMERS_0_CTC_ISR]);
//     }
// }
// void __vector_11 (void)
// {
//     if(apfun_ISRpointers[TIMERS_0_OVERFLOW_ISR])
//     {
//         apfun_ISRpointers[TIMERS_0_OVERFLOW_ISR](apvid_ISRParameters[TIMERS_0_OVERFLOW_ISR]);
//     }
// }

// //Local functions implementations
// static ErrorState_t enu_SetClockSelection (u8 Copy_u8_TimerNumber, u8 Copy_ClockSelection)
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;

//     switch (Copy_u8_TimerNumber)
//     {
//         case TIMERS_0: 
//         {
//             // Clearing all bits (CS02 CS01 CS00) 
//             TCCR0 &= 0xF8;

//             switch(Copy_ClockSelection)
//             {
//                case TIMERS_V_GND:
//                 {
//                     //Bits aleady contain 000

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_1:
//                 {
//                     //Bits contain 001
//                     TCCR0 |= (1 << TCCR0_CS00);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_8:
//                 {
//                     //Bits contain 010
//                     TCCR0 |= (1 << TCCR0_CS01);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_64:
//                 {
//                     //Bits contain 011
//                     TCCR0 |= (3 << TCCR0_CS00);


//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_256:
//                 {
//                     //Bits contain 100
//                     TCCR0 |= (1 << TCCR0_CS02);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_1024:
//                 {
//                     //Bits contain 101
//                     TCCR0 |= (5 << TCCR0_CS00);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_FALLING_EDGE:
//                 {

//                     //Bits contain 110
//                     TCCR0 |= (3 << TCCR0_CS01);

//                     Local_u8_ErrorFlag = ES_OK;

//                     break;
//                 }
//                case TIMERS_RISING_EDGE:
//                 {
//                     //Bits contain 111
//                     TCCR0 |= (7 << TCCR0_CS00);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }

//                 default:
//                 {
//                     Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//                     break;
//                 }
//             }  

//           break;
//         }

//         case TIMERS_1:
//         {

//           break;
//         }
        
//         case TIMERS_2: 
//         {
//             //Choosing I/O clock each time 
//             //Bit contains 0
//             ASSR &= ~( 1 << ASSR_AS2);

//             // Clearing all bits (CS22 CS21 CS20s
//             TCCR2 &= 0xF8;

//             switch(Copy_ClockSelection)
//             {
//                case TIMERS_V_GND:
//                 {
//                     //Bits aleady contain 000

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_1:
//                 {
//                     //Bits contain 001
//                     TCCR2 |= (1 << TCCR2_CS20);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_8:
//                 {
//                     //Bits contain 010
//                     TCCR2 |= (1 << TCCR2_CS21);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_32:
//                 {
//                     //Bits contain 011
//                     TCCR2 |= (3 << TCCR2_CS20);


//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_64:
//                 {
//                     //Bits contain 100
//                     TCCR2 |= (1 << TCCR2_CS22);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_128:
//                 {
//                     //Bits contain 101
//                     TCCR2 |= (5 << TCCR2_CS20);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }
//                case TIMERS_PS_256:
//                 {

//                     //Bits contain 110
//                     TCCR2 |= (3 << TCCR2_CS21);

//                     Local_u8_ErrorFlag = ES_OK;

//                     break;
//                 }
//                case TIMERS_PS_1024:
//                 {
//                     //Bits contain 111
//                     TCCR2 |= (7 << TCCR2_CS20);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }

//                 default:
//                 {
//                     Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//                     break;
//                 }
//             }  

//           break;
//         }
    
//         default:
//         {
//             Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             break;
//         }
//     }

//     return Local_u8_ErrorFlag;
// }

// static ErrorState_t enu_SetWaveformGenerationMode (u8 Copy_u8_TimerNumber, u8 Copy_u8_WaveformMode)
// {    u8 Local_u8_ErrorFlag = ES_NOK;
//     switch (Copy_u8_TimerNumber)
//     {
//         case TIMERS_0:
//         {
//             //Clearing all bits (WGM01 WGM00)
//             TCCR0 &= ~ ( 1 << TCCR0_WGM00);
//             TCCR0 &= ~ ( 1 << TCCR0_WGMO1);

//             if( Copy_u8_WaveformMode == TIMERS_OVERFLOW_MODE)
//             {
//                 //Bits alread contain 00

//                 Local_u8_ErrorFlag = ES_OK;
//                 break;
//             }
//             else if(Copy_u8_WaveformMode == TIMERS_CTC_MODE)
//             {
//                 //Bits contain 10
//                 TCCR0 |= (1 << TCCR0_WGMO1);
                
//                 Local_u8_ErrorFlag = ES_OK;
//                 break;
//             }
//             else
//             {
//                 Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             }
        
             
//             break;
//         }

//         case TIMERS_1:
//         {
            
//             break;
//         }

//         case TIMERS_2:
//         {
//             //Clearing all bits (WGM01 WGM00)
//             TCCR2 &= ~ ( 1 << TCCR2_WGM20);
//             TCCR2 &= ~ ( 1 << TCCR2_WGM21);

//             if( Copy_u8_WaveformMode == TIMERS_OVERFLOW_MODE)
//             {
//                 //Bits alread contain 00

//                 Local_u8_ErrorFlag = ES_OK;
//                 break;
//             }
//             else if(Copy_u8_WaveformMode == TIMERS_CTC_MODE)
//             {
//                 //Bits contain 10
//                 TCCR0 |= (1 << TCCR2_WGM21);
                
//                 Local_u8_ErrorFlag = ES_OK;
//                 break;
//             }
//             else
//             {
//                 Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             }

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

// static ErrorState_t enu_SetOCxPinBehavior (u8 Copy_u8_TimerNumber, u8 Copy_u8_OCxBehavior)
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;

//     switch (Copy_u8_TimerNumber)
//     {
//         case TIMERS_0:
//         {
//             //Clearing all bits (COM01  COM00)
//             TCCR0 &= 0xCF;
            
//             switch (Copy_u8_OCxBehavior)
//             {

//                 case TIMERS_DISCONNECT_OCX:
//                 {
//                     //Bits already contain 00

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }

//                 case TIMERS_TOGGLE_OCX:
//                 {
//                     //Bits contain 01
//                     TCCR0 |= (1 << TCCR0_COM00);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }

//                 case TIMERS_CLEAR_OCX:
//                 {
//                     //Bits contain 10
//                     TCCR0 |= (1 << TCCR0_COM01);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }

//                 case TIMERS_SET_OCX:
//                 {
//                     //Bits contain 11
//                     TCCR0 |= (3 << TCCR0_COM00);

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

//         case TIMERS_1:
//         {

//             break;
//         }

//         case TIMERS_2:
//         {
//             //Clearing all bits (COM21  COM20)
//             TCCR2 &= 0xCF;

//             switch (Copy_u8_OCxBehavior)
//             {
//                 case TIMERS_DISCONNECT_OCX:
//                 {
//                     //Bits already contain 00

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }

//                 case TIMERS_TOGGLE_OCX:
//                 {
//                     //Bits contain 01
//                     TCCR2 |= (1 << TCCR2_COM20);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }

//                 case TIMERS_CLEAR_OCX:
//                 {
//                     //Bits contain 10
//                     TCCR2 |= (1 << TCCR2_COM21);

//                     Local_u8_ErrorFlag = ES_OK;
//                     break;
//                 }

//                 case TIMERS_SET_OCX:
//                 {
//                     //Bits contain 11
//                     TCCR2 |= (3 << TCCR2_COM20);

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
        
//         default:
//         {
//             Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             break;
//         }
//     }


//     return Local_u8_ErrorFlag;
// }

// static ErrorState_t enu_SetInterruptMode(u8 Copy_u8_TimerNumber, u8 Copy_u8_WaveformMode, u8 Copy_u8_InterruptMode)
// {
//     u8 Local_u8_ErrorFlag = ES_NOK;

//     switch (Copy_u8_TimerNumber)
//     {
 
            
//         case TIMERS_0:
//         {
//             //Clearing bits (OIE0  TOIE0)
//             TIMSK &= 0xFC;

//             if(Copy_u8_WaveformMode == TIMERS_OVERFLOW_MODE)
//             {
//                 //Bits contain 01 --> interrupt = 1
//                 //             00 --> interrupt = 0

//                 TIMSK |= (Copy_u8_InterruptMode << TIMSK_TOIE0);

//                 Local_u8_ErrorFlag = ES_OK;
//             }
//             else if (Copy_u8_WaveformMode == TIMERS_CTC_MODE)
//             {
//                 //Bits contain 10 --> interrupt = 1
//                 //             00 --> interrupt = 0

//                 TIMSK |= (Copy_u8_InterruptMode << TIMSK_OCIE0);

//                 Local_u8_ErrorFlag = ES_OK;
//             }
//             else
//             {
//                 Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             }

//             break;
//         }
//         case TIMERS_1:
//         {
//             break;
//         }

//         case TIMERS_2:
//         {
//             //Clearing bits (OIE2  TOIE2)
//             TIMSK &= 0x3F;

//             if(Copy_u8_WaveformMode == TIMERS_OVERFLOW_MODE)
//             {
//                 //Bits contain 01 --> interrupt = 1
//                 //             00 --> interrupt = 0

//                 TIMSK |= (Copy_u8_InterruptMode << TIMSK_TOIE2);

//                 Local_u8_ErrorFlag = ES_OK;
//             }
//             else if (Copy_u8_WaveformMode == TIMERS_CTC_MODE)
//             {
//                 //Bits contain 10 --> interrupt = 1
//                 //             00 --> interrupt = 0

//                 TIMSK |= (Copy_u8_InterruptMode << TIMSK_OCIE2);

//                 Local_u8_ErrorFlag = ES_OK;
//             }
//             else
//             {
//                 Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
//             }            
            
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