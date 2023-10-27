#ifndef L293D_INTERFACE_FILE
#define L293D_INTERFACE_FILE

#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

#define L293D_H1   5
#define L293D_H2   6

#define L293D_CW     0
#define L293D_CCW    1


//APIs prototypes
extern ErrorState_t L293D_enu_Initialization (void);

extern ErrorState_t L293D_enu_SetRotationDirection(u8 Copy_BridgeNumber, u8 Copy_u8_Direction);

extern ErrorState_t L293D_enu_SetRotationSpeed (u8 Copy_u8_BridgeNumber, f32 Copy_f32_SpeedPercentage);

extern ErrorState_t L293D_enu_TurnOnMotor(u8 Copy_u8_BridgeNumber, f32 Copy_f32_SpeedPercentage);

extern ErrorState_t L293D_enu_TurnOffMotor(u8 Copy_u8_BridgeNumber);





#endif