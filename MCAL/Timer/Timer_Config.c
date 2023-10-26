

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "Timer_Config.h"
#include "Timer_Private.h"


u8 Timer_u8_TimerCount = TIMER_COUNT;
TIMER_t Timer_astr_TimerList[TIMER_COUNT] = {
                                                {TIMER_0,TIMER_NORMAL,TIMER_PS_64,TIMER_INT_MODE,TIMER_TOGGLE_OCX},
                                                    
                                            };