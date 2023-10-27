#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer/Timer_Interface.h"

#include "L293D_Config.h"
#include "L293D_Private.h"


//APIs implemenations
extern ErrorState_t L293D_enu_Initialization (void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    //Initializing Timer Module
    Local_u8_ErrorFlag = Timer_enu_Initialization();   

    #if L293D_H1_STATUS == L293D_USED

        #if !((L293D_IN1_GROUP >= DIO_PIN_GROUP_A && L293D_IN1_GROUP <= DIO_PIN_GROUP_D) && (L293D_IN1_PIN >= DIO_PIN_0 && L293D_IN1_PIN <= DIO_PIN_7) && (L293D_IN2_GROUP >= DIO_PIN_GROUP_A && L293D_IN2_GROUP <= DIO_PIN_GROUP_D) && (L293D_IN2_PIN >= DIO_PIN_0 && L293D_IN2_PIN <= DIO_PIN_7) && (L293D_EN1_TIMER >= TIMER_0 && L293D_EN1_TIMER <= TIMER_2) && (L293D_H1_ROTATION_DIRECTION == L293D_CCW || L293D_H1_ROTATION_DIRECTION == L293D_CW) && (L293D_H1_INITIAL_STATE == L293D_ON || L293D_H1_INITIAL_STATE == L293D_OFF))

            #error H-Bridege 1 Configuration Error

        #else

            //Choosing pins as Output
            DIO_enu_SetPinDiretion(L293D_IN1_GROUP, L293D_IN1_PIN, DIO_PIN_WRITE); 
            DIO_enu_SetPinDiretion(L293D_IN2_GROUP, L293D_IN2_PIN, DIO_PIN_WRITE);
             
              
        
            #if  L293D_EN1_TIMER == TIMER_0  
                    
                //Timer needs DDRx = 1 to produce a PWM 
                DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B, DIO_PIN_3, DIO_PIN_WRITE); 

                    
            #elif L293D_EN1_TIMER == TIMER_1

                // To be Done Later

            #elif L293D_EN1_TIMER == TIMER_2 
                        
                //Overriding Normal port operation 
                //Timer needs DDRx = 1 to produce a PWM 
                DIO_enu_SetPinDiretion(DIO_PIN_GROUP_D, DIO_PIN_7, DIO_PIN_WRITE); 

            #endif

            //If H1 must be initialized as on 
            #if L293D_H1_INITIAL_STATE == L293D_ON
                
                //TO be done later
            
            #else
                
                //If H1 must be initialized as off 
                Timer_enu_SetDutyCycleForPWM(L293D_EN1_TIMER, TIMER_FAST_PWM, TIMER_FAST_PWM_INVERTING, 0); 

            #endif
            
            //Assumes CCW state
            DIO_enu_SetPinValue(L293D_IN1_GROUP, L293D_IN1_PIN, DIO_HIGH);
            DIO_enu_SetPinValue(L293D_IN2_GROUP, L293D_IN2_PIN, DIO_LOW);
            
            //If H1 must be initialized as CW
            #if  L293D_H1_ROTATION_DIRECTION == L293D_CW

            DIO_enu_TogglePinValue(L293D_IN1_GROUP, L293D_IN1_PIN);
            DIO_enu_TogglePinValue(L293D_IN2_GROUP, L293D_IN2_PIN);

            #endif
             
        #endif

    #endif

    #if L293D_H2_STATUS == L293D_USED
        
        #if !((L293D_IN3_GROUP >= DIO_PIN_GROUP_A && L293D_IN3_GROUP <= DIO_PIN_GROUP_D) && (L293D_IN3_PIN >= DIO_PIN_0 && L293D_IN3_PIN <= DIO_PIN_7) && (L293D_IN4_GROUP >= DIO_PIN_GROUP_A && L293D_IN4_GROUP <= DIO_PIN_GROUP_D) && (L293D_IN4_PIN >= DIO_PIN_0 && L293D_IN4_PIN <= DIO_PIN_7) && (L293D_EN2_TIMER >= TIMER_0 && L293D_EN2_TIMER <= TIMER_2) && (L293D_H2_ROTATION_DIRECTION == L293D_CCW || L293D_H2_ROTATION_DIRECTION == L293D_CW) && (L293D_H2_INITIAL_STATE == L293D_ON || L293D_H2_INITIAL_STATE == L293D_OFF))

            #error H-Bridge 2 Configuration Error

        #else            

            
            //Choosing pins as Output
            DIO_enu_SetPinDiretion(L293D_IN3_GROUP, L293D_IN3_PIN, DIO_PIN_WRITE); 
            DIO_enu_SetPinDiretion(L293D_IN4_GROUP, L293D_IN4_PIN, DIO_PIN_WRITE); 
        
            #if  L293D_EN2_TIMER == TIMER_0  
                    
                //Timer needs DDRx = 1 to produce a PWM 
                DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B, DIO_PIN_3, DIO_PIN_READ); 
                    
            #elif L293D_EN2_TIMER == TIMER_1

                // To be Done Later

            #elif L293D_EN2_TIMER == TIMER_2 
                        
                //Timer needs DDRx = 1 to produce a PWM 
                DIO_enu_SetPinDiretion(DIO_PIN_GROUP_D, DIO_PIN_7, DIO_PIN_READ); 

            #endif 

            

            #if L293D_H2_INITIAL_STATE == L293D_ON

                //To start with a specified speed percentage code to be done later right now it starts with configures duty percentage in timer

            #elif L293D_H2_INITIAL_STATE == L293D_OFF
            
                //If H2 must be initialized as off 
                Timer_enu_SetDutyCycleForPWM(L293D_EN2_TIMER, TIMER_FAST_PWM, TIMER_FAST_PWM_INVERTING, 0); 
        

            #endif
            
            //Assumes CCW state
            DIO_enu_SetPinValue(L293D_IN3_GROUP, L293D_IN3_PIN, DIO_LOW);
            DIO_enu_SetPinValue(L293D_IN4_GROUP, L293D_IN4_PIN, DIO_HIGH);
            #if L293D_H1_ROTATION_DIRECTION == L293D_CW

            //If H2 must be initialized as CW
            DIO_enu_TogglePinValue(L293D_IN3_GROUP, L293D_IN3_PIN);
            DIO_enu_TogglePinValue(L293D_IN4_GROUP, L293D_IN4_PIN);

            #endif 

        #endif

    #endif

    #if L293D_H1_STATUS == L293D_USED && L293D_H2_STATUS == L293D_USED

        //Checking for timer reuse
        #if L293D_EN1_TIMER == L293D_EN2_TIMER

            #error H1 and H2 are using the same timer module

        #endif
  

    #endif
    

    
    return Local_u8_ErrorFlag;
    
}

extern ErrorState_t L293D_enu_SetRotationDirection(u8 Copy_BridgeNumber, u8 Copy_u8_Direction)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    
    switch (Copy_BridgeNumber)
    {
        case L293D_H1:
        {
            #if L293D_H1_STATUS == L293D_USED

                if (Copy_u8_Direction == L293D_CCW)
                {
                    
                    DIO_enu_SetPinValue(L293D_IN1_GROUP, L293D_IN1_PIN, DIO_HIGH);
                    DIO_enu_SetPinValue(L293D_IN2_GROUP, L293D_IN2_PIN, DIO_LOW);

                    Local_u8_ErrorFlag = ES_OK;
                }
                else if (Copy_u8_Direction == L293D_CW)
                {
                    DIO_enu_SetPinValue(L293D_IN1_GROUP, L293D_IN1_PIN, DIO_LOW);
                    DIO_enu_SetPinValue(L293D_IN2_GROUP, L293D_IN2_PIN, DIO_HIGH);

                    Local_u8_ErrorFlag = ES_OK;

                }
                else
                {
                    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                }

            #else

                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                
            #endif

            break;
        } 

        case L293D_H2:
        {
            #if L293D_H2_STATUS == L293D_USED

                if (Copy_u8_Direction == L293D_CCW)
                {
                    DIO_enu_SetPinValue(L293D_IN3_GROUP, L293D_IN3_PIN, DIO_HIGH);
                    DIO_enu_SetPinValue(L293D_IN4_GROUP, L293D_IN4_PIN, DIO_LOW);
                }
                else if (Copy_u8_Direction == L293D_CW)
                {
                    DIO_enu_SetPinValue(L293D_IN3_GROUP, L293D_IN3_PIN, DIO_LOW);
                    DIO_enu_SetPinValue(L293D_IN4_GROUP, L293D_IN4_PIN, DIO_HIGH);
                }
                else
                {
                    Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
                }
            
            #else
            
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            
            #endif
            
            break;
        } 
        
        default:
        {
            Local_u8_ErrorFlag = ES_OUT_OF_RANGE;

            break;
        }
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t L293D_enu_SetRotationSpeed (u8 Copy_u8_BridgeNumber, f32 Copy_f32_SpeedPercentage)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    switch (Copy_u8_BridgeNumber)
    {
        case L293D_H1:
        {
            #if L293D_H1_STATUS == L293D_USED
 
                Timer_enu_SetDutyCycleForPWM(L293D_EN1_TIMER, TIMER_FAST_PWM, TIMER_FAST_PWM_INVERTING, Copy_f32_SpeedPercentage);
            
                Local_u8_ErrorFlag =ES_OK;
            
            #else
            
                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            
            #endif

            break;
        }

        case L293D_H2:
        {
            #if L293D_H2_STATUS == L293D_USED

                Timer_enu_SetDutyCycleForPWM(L293D_EN2_TIMER, TIMER_FAST_PWM, TIMER_FAST_PWM_INVERTING, Copy_f32_SpeedPercentage);
            
                Local_u8_ErrorFlag =ES_OK;

            #else

                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;

            #endif
            
            break;
        }

        default:
        {
            Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            
            break;
        }
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t L293D_enu_TurnOnMotor(u8 Copy_u8_BridgeNumber, f32 Copy_f32_SpeedPercentage)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    switch (Copy_u8_BridgeNumber)
    {
        case L293D_H1:
        {

            #if L293D_H1_STATUS == L293D_USED
 
                Timer_enu_SetDutyCycleForPWM(L293D_EN1_TIMER, TIMER_FAST_PWM, TIMER_FAST_PWM_INVERTING, Copy_f32_SpeedPercentage);
                      
                Local_u8_ErrorFlag = ES_OK;

            #else

                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            
            #endif

            break;
        }

        case L293D_H2:
        {
            
            #if L293D_H2_STATUS == L293D_USED

                Timer_enu_SetDutyCycleForPWM(L293D_EN2_TIMER, TIMER_FAST_PWM, TIMER_FAST_PWM_INVERTING, Copy_f32_SpeedPercentage);
                
                Local_u8_ErrorFlag = ES_OK;


            #else

                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;

            #endif

            break;
        }
    
        default:
        {
            Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            break;
        }
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t L293D_enu_TurnOffMotor(u8 Copy_u8_BridgeNumber)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    switch (Copy_u8_BridgeNumber)
    {
        case L293D_H1:
        {
            #if L293D_H1_STATUS == L293D_USED

                Timer_enu_SetDutyCycleForPWM(L293D_EN1_TIMER, TIMER_FAST_PWM, TIMER_FAST_PWM_INVERTING, 0);
                

                Local_u8_ErrorFlag = ES_OK;

            #else

                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            
            #endif            
            
            break;
        }

        case L293D_H2:
        {            
            #if L293D_H2_STATUS == L293D_USED

                Timer_enu_SetDutyCycleForPWM(L293D_EN2_TIMER, TIMER_FAST_PWM, TIMER_FAST_PWM_INVERTING, 0);
              

                Local_u8_ErrorFlag = ES_OK;

            #else

                Local_u8_ErrorFlag = ES_OUT_OF_RANGE;

            #endif            

            break;
        }
    
        default:
        {
            Local_u8_ErrorFlag = ES_OUT_OF_RANGE;
            
            break;
        }

    }

    return Local_u8_ErrorFlag;

}


