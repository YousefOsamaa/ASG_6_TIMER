#ifndef USART_INTERFACE_FILE
#define USART_INTERFACE_FILE


#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"




//APIs' prototype
extern ErrorState_t USART_enu_Initialization(void);

extern ErrorState_t USART_enu_SendData(u16 Copy_u16_Data);

extern ErrorState_t USART_enu_ReceiveData(u16* Copy_pu16_Data);

extern ErrorState_t USART_enu_SendString (u8* Copy_pu8_String);

extern ErrorState_t USART_enu_SetCallBack(void (*Copy_pfun_AppFun)(void*), void* Copy_pvid_Paramters);



#endif