

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "Timer_Config.h"
#include "Timer_Private.h"


u8 Timer_u8_TimerCount = TIMER_COUNT;
TIMER_t Timer_astr_TimerList[TIMER_COUNT] = {
                                                {TIMER_0, TIMER_FAST_PWM, TIMER_FAST_PWM_62500_HZ, TIMER_POLLING_MODE, TIMER_FAST_PWM_INVERTING, 0},
                                                    
                                            };