// #ifndef PWM_PRIVATE_FILE
// #define PWM_PRIVATE_FILE


// #include "../../LIB/STD.h"
// #include "../../LIB/ErrorStates.h"


// //Timer/Counter Control Register 0
// #define TCCR0 *(volatile u8*)0x53
// typedef enum
// {
//     TCCR0_CS00 , //Bit 0 of Clock Selection for Timer/Counter 0
//     TCCR0_CS01 , //Bit 1 of Clock Selection for Timer/Counter 0
//     TCCR0_CS02 , //Bit 2 of Clock Selection for Timer/Counter 0
//     TCCR0_WGM01, //Bit 1 of Waveform Generation Mode for Timer/Counter 0
//     TCCR0_COM00, //Bit 0 of Compare Match Output Mode for Timer/Counter 0 
//     TCCR0_COM01, //Bit 1 of Compare Match Output Mode for Timer/Counter 0
//     TCCR0_WGM00, //Bit 0 of Waveform Generation Mode for Timer/Counter 0
//     TCCR0_FOC0 , //Force Output Compare Match for Timer/Counter 0

// }TCCR0_t;

// //Timer/Counter 0 Register 
// #define TCNT0  *(volatile u8*)0x52
// typedef enum
// {
//     TCNT0_B0, //Bit 0 in Timer/Counter 0 Register
//     TCNT0_B1, //Bit 1 in Timer/Counter 0 Register
//     TCNT0_B2, //Bit 2 in Timer/Counter 0 Register
//     TCNT0_B3, //Bit 3 in Timer/Counter 0 Register
//     TCNT0_B4, //Bit 4 in Timer/Counter 0 Register
//     TCNT0_B5, //Bit 5 in Timer/Counter 0 Register
//     TCNT0_B6, //Bit 6 in Timer/Counter 0 Register
//     TCNT0_B7, //Bit 7 in Timer/Counter 0 Register

// }TCNT0_t;

// //Timer/Counter 0 Output Compare Register
// #define OCR0 *(volatile u8*)0x5C
// typedef enum
// {
//     OCR0_B0, //Bit 0 in Timer/Counter 0 Output Compare Register
//     OCR0_B1, //Bit 1 in Timer/Counter 0 Output Compare Register
//     OCR0_B2, //Bit 2 in Timer/Counter 0 Output Compare Register
//     OCR0_B3, //Bit 3 in Timer/Counter 0 Output Compare Register
//     OCR0_B4, //Bit 4 in Timer/Counter 0 Output Compare Register
//     OCR0_B5, //Bit 5 in Timer/Counter 0 Output Compare Register
//     OCR0_B6, //Bit 6 in Timer/Counter 0 Output Compare Register
//     OCR0_B7, //Bit 7 in Timer/Counter 0 Output Compare Register

// }OCR0_t;

// //Timer/Counter Control Register 2
// #define TCCR2 *(volatile u8*)0x45
// typedef enum
// {
//     TCCR2_CS20 , //Bit 0 of Clock Selection for Timer/Counter 2
//     TCCR2_CS21 , //Bit 1 of Clock Selection for Timer/Counter 2
//     TCCR2_CS22 , //Bit 2 of Clock Selection for Timer/Counter 2
//     TCCR2_WGM21, //Bit 1 of Waveform Generation Mode for Timer/Counter 2
//     TCCR2_COM20, //Bit 0 of Compare Match Output Mode for Timer/Counter 2
//     TCCR2_COM21, //Bit 1 of Compare Match Output Mode for Timer/Counter 2
//     TCCR2_WGM20, //Bit 0 of Waveform Generation Mode for Timer/Counter 2
//     TCCR2_FOC2 , //Force Output Compare Match for Timer/Counter 2

// }TCCR2_t;

// //Timer/Counter 2 Register 
// #define TCNT2  *(volatile u8*)0x44
// typedef enum
// {
//     TCNT2_B0, //Bit 0 in Timer/Counter 2 Register
//     TCNT2_B1, //Bit 1 in Timer/Counter 2 Register
//     TCNT2_B2, //Bit 2 in Timer/Counter 2 Register
//     TCNT2_B3, //Bit 3 in Timer/Counter 2 Register
//     TCNT2_B4, //Bit 4 in Timer/Counter 2 Register
//     TCNT2_B5, //Bit 5 in Timer/Counter 2 Register
//     TCNT2_B6, //Bit 6 in Timer/Counter 2 Register
//     TCNT2_B7, //Bit 7 in Timer/Counter 2 Register

// }TCNT2_t;

// //Timer/Counter 2 Output Compare Register
// #define OCR2 *(volatile u8*)0x43
// typedef enum
// {
//     OCR2_B0, //Bit 0 in Timer/Counter 2 Output Compare Register 
//     OCR2_B1, //Bit 1 in Timer/Counter 2 Output Compare Register
//     OCR2_B2, //Bit 2 in Timer/Counter 2 Output Compare Register
//     OCR2_B3, //Bit 3 in Timer/Counter 2 Output Compare Register
//     OCR2_B4, //Bit 4 in Timer/Counter 2 Output Compare Register
//     OCR2_B5, //Bit 5 in Timer/Counter 2 Output Compare Register
//     OCR2_B6, //Bit 6 in Timer/Counter 2 Output Compare Register
//     OCR2_B7, //Bit 7 in Timer/Counter 2 Output Compare Register

// }OCR2_t;

// //Timer/Counter Interrupt Mask Register
// #define TIMSK *(volatile u8*)0x59
// typedef enum
// {
//     TIMSK_TOIE0, //Timer/Counter 0 Overflow Interrupt Enable 
//     TIMSK_OCIE0, //Output Match Compare Interrupt Enable for Timer/Counter 0
//     TIMSK_TOIE1, //Timer/Counter 1 Overflow Interrupt Enable 
//     TIMSK_OCIE1B, //Output Compare Match B Interrupt Enable for Timer/Counter 1
//     TIMSK_OCIE1A, //Output Compare Match A Interrupt Enable for Timer/Counter 1 
//     TIMSK_TICIE1, //Timer/Counter 1 Input Capture Interrupt Enable
//     TIMSK_TOIE2, //Timer/Counter 2 Overflow Interrupt Enable 
//     TIMSK_OCIE2, //Output Match Compare Interrupt Enable for Timer/Counter 2

// }TIMSK_t;

// //Timer/Counter Interrupt Flag Register
// #define TIFR *(volatile u8*)0x58
// typedef enum
// {
//     TIFR_TOV0,  //Overflow Flag for Timer/Counter 0
//     TIFR_OCF0,  //Output Compare Match Flag for Timer/Counter 0
//     TIFR_TOV1,  //Overflow Flag for Timer/Counter 1
//     TIFR_OCF1B, //Output Compare Match B Flag for Timer/Counter 1
//     TIFR_OCF1A, //Output Compare Match A Flag for Timer/Counter 1
//     TIFR_ICF1,  //Timer/Counter 1 Input Capture Flag  
//     TIFR_TOV2,  //Overflow Flag for Timer/Counter 2
//     TIFR_OCF2,  //Output Compare Match Flag for Timer/Counter 2
    
// }TIFR_t;


// //Special Functio IO Register
// #define SFIOR *(volatile u8*)50;
// typedef enum
// {
//     SFIOR_PSR10, //Prescaler Reset for Timer/Counter 0 and 1
//     SFIOR_PSR2 , //Prescaler Reset for Timer/Counter 2

// }SFIOR_t;

// //Asynchronous Status Register – ASSR
// #define ASSR  *(volatile u8*)0x42
// typedef enum
// {
//  ASSR_TCR2UB, //Timer/Counter Control Register2 Update Busy
//  ASSR_OCR2UB, //Output Compare Register 2 Update Busy
//  ASSR_TCN2UB, //Timer/Counter 2 Update Busy
//  ASSR_AS2 ,  //Asynchronous Timer/Counter2

// }ASSR_t;


// //PWM Numbers
// #define PWM_0   0
// #define PWM_1   1
// #define PWM_2   2

// //Clock Selection options                   
// //                    TIMER0    TIMER1    TIMER2
// //PWM_V_GND         YES       YES       YES
// //PWM_PS_1          YES       YES       YES
// //PWM_PS_8          YES       YES       YES
// //PWM_PS_32         NO        NO        YES
// //PWM_PS_64         YES       YES       YES
// //PWM_PS_128        NO        NO        YES
// //PWM_PS_256        YES       YES       YES
// //PWM_PS_1024       YES       YES       YES
// #define PWM_V_GND           0   
// #define PWM_PS_1            1 
// #define PWM_PS_8            2 
// #define PWM_PS_32           3 
// #define PWM_PS_64           4 
// #define PWM_PS_128          5 
// #define PWM_PS_256          6 
// #define PWM_PS_1024         7 


// //Timer/Counter Waveform generation options        
// //                     TIMER0    TIMER1    TIMER2
// //PWM_PHASE_MODE       YES       NO       YES
// //PWM_FAST_MODE        YES       NO       YES
// #define PWM_PHASE_MODE           0            
// #define PWM_FAST_MODE            1

// //Timer/Counter Compare Match Output Mode     
// //                       TIMER0    TIMER1    TIMER2
// //PWM_DISCONNECT_OCX     YES       NO       YES
// //PWM_NON_INVERTING      YES       NO       YES
// //PWM_INVERTING          YES       NO       YES    
// #define PWM_DISCONNECT_OCX       0                 
// #define PWM_NON_INVERTING        2 
// #define PWM_INVERTING            3


// //Duty Cycle ranges 
// #define PWM_DUTY_CYCLE_100  1
// #define PWM_DUTY_CYCLE_0    0

// //TCTN0 Register values
// #define PWM_TCNT0_TOP      0xFF
// #define PWM_TCNT0_BOTTOM   0x00



// //Local functions' protoypes
// static ErrorState_t enu_SetClockSelection(u8 Copy_u8_PWMNumber, u8 Copy_u8_ClockSelection);

// static ErrorState_t enu_SetWaveformGenerationMode(u8 Copy_u8_PWMNumber, u8 Copy_u8_WaveformMode);

// static ErrorState_t enu_SetOCxBehavior (u8 Copy_u8_PWMNumber, u8 Copy_u8_OCxBehavior);

// static ErrorState_t enu_SetDutyCycle (u8 Copy_u8_PWMNumber,u8 Copy_u8_WaveformMode, u8 Copy_u8_OcxBehavior, u8 Copy_f32_DutyCyclePercentage);

// #endif