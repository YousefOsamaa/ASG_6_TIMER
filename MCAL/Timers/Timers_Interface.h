// #ifndef TIMERS_INTERFACE_FILE
// #define TIMERS_INTERFACE_FILE

// #include "../../LIB/STD.h"
// #include "../../LIB/ErrorStates.h"


// //Timer Numbers
// #define TIMERS_0   0
// #define TIMERS_1   1
// #define TIMERS_2   2

// //Clock Selection options                   
// //                    TIMER0    TIMER1    TIMER2
// //TIMERS_V_GND         YES       YES       YES
// //TIMERS_PS_1          YES       YES       YES
// //TIMERS_PS_8          YES       YES       YES
// //TIMERS_PS_32         NO        NO        YES
// //TIMERS_PS_64         YES       YES       YES
// //TIMERS_PS_128        NO        NO        YES
// //TIMERS_PS_256        YES       YES       YES
// //TIMERS_PS_1024       YES       YES       YES
// //TIMERS_FALLING_EDGE  YES       YES       NO
// //TIMERS_RISING_EDGE   YES       YES       NO
// #define TIMERS_V_GND           0   
// #define TIMERS_PS_1            1 
// #define TIMERS_PS_8            2 
// #define TIMERS_PS_32           3 
// #define TIMERS_PS_64           4 
// #define TIMERS_PS_128          5 
// #define TIMERS_PS_256          6 
// #define TIMERS_PS_1024         7 
// #define TIMERS_FALLING_EDGE    8 
// #define TIMERS_RISING_EDGE     9 

// //Timer/Counter Waveform generation options        
// //                     TIMER0    TIMER1    TIMER2
// //TIMERS_OVERFLOW_MODE   YES       NO       YES
// //TIMERS_CTC_MODE        YES       NO       YES
// #define TIMERS_OVERFLOW_MODE       0           
// #define TIMERS_CTC_MODE            1

// //Timer/Counter Compare Match Output Mode     
// //                       TIMER0    TIMER1    TIMER2
// //TIMERS_DISCONNECT_OCX   YES       NO       YES
// //TIMERS_TOGGLE_OCX       YES       NO       YES
// //TIMERS_CLEAR_OCX        YES       NO       YES
// //TIMERS_SET_OCX          YES       NO       YES    
// #define TIMERS_DISCONNECT_OCX      0                 
// #define TIMERS_TOGGLE_OCX          1
// #define TIMERS_CLEAR_OCX           2 
// #define TIMERS_SET_OCX             3


// //Timer/Counter Interrupt Mode
// #define TIMERS_POLLING_MODE     0
// #define TIMERS_INTERRUPT_MODE   1




// //APIs' prototypes

// extern ErrorState_t Timers_enu_Initialization(void);

// extern ErrorState_t Timers_enu_SetCallBack (u8 Copy_u8_TimerNumber, u8 Copy_u8_WaveformMode, void (* Copy_pfun_AppFunction), void* Copy_pvid_Parameters);

// #endif