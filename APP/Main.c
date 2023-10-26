#include "../MCAL/Timer/Timer_Interface.h"
#include "../MCAL/SREG/SREG_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/SW/SW_Interface.h"
#include "../MCAL/Timers/Timers_Interface.h"
#include "../TMU/TMU_Interface.h"
#include <stdio.h>
#include <util/delay.h>
#include "../MCAL/USART/USART_Interface.h"
// #include <util/delay.h>

void SEND (void* Copy_pvid_Parameters)
{
	u8 Local_u8_Flag = *(u8*)(Copy_pvid_Parameters);

	Local_u8_Flag = True;
}
int main()
{
	u8 Local_au8_String [] = "H";
	u8 Local_u8_Flag = False;

	//Initializng USART
	USART_enu_Initialization();

	//Setting CallBack Function
	u8 Flag = USART_enu_SetCallBack(SEND, &Local_u8_Flag);

	while(1)
	{
		_delay_ms(5000);
		USART_enu_SendData(65);
	}


	// DIO_enu_SetPinDiretion(0,0,1);

	// if(Flag == ES_OUT_OF_RANGE)
	// {
	// 	DIO_enu_GetPinValue(0,0,1);
	// }
	// else
	// {
	// 	DIO_enu_SetPinValue(0,0,0);
	// }

	// //USART_enu_SendData(0xFF);

	// while(1)
	// {
	// 	u8 i = 5;
	// 	if(Local_u8_Flag)
	// 	{
	// 		//USART_enu_SendString(Local_au8_String);
	// 		USART_enu_SendData(i);

	// 		Local_u8_Flag = False;

	// 		i++;
	// 	}
	// }

	return 0;
}


// typedef struct
// {
// 	u16 Count;
// 	u8 Flag;

// }Count_t;

// #define Count_d ((Count_t*)(Copy_pvid_Parameters))->Count
// #define Flag_d ((Count_t*)(Copy_pvid_Parameters))->Flag

// void tog (void* Copy_pvid_Parameters)
// {
// 	Count_t* Local_pstr_ParametersPointer =  (Count_t*)(Copy_pvid_Parameters);

	
// 	(Local_pstr_ParametersPointer->Count)++;

// 	if(Local_pstr_ParametersPointer->Count == 4883)
// 	{
// 		Local_pstr_ParametersPointer->Flag = True;
// 	}

// 	// DIO_enu_TogglePinValue(DIO_PIN_GROUP_A,DIO_PIN_0);

	
	

// }













// int main()
// {
// 	Count_t Local_str_TimerCount = {48 , False};

// 	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_A, DIO_PIN_0, DIO_PIN_WRITE);
// 	DIO_enu_SetPinValue(DIO_PIN_GROUP_A, DIO_PIN_0, DIO_LOW);

// 	//Initializing OC0 pin
// 	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B, DIO_PIN_3, DIO_PIN_WRITE);

// 	//Initializing LED pin
// 	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B, DIO_PIN_0, DIO_PIN_WRITE);
// 	DIO_enu_SetPinValue(DIO_PIN_GROUP_B, DIO_PIN_0, DIO_LOW);


// 	//Initializing Timer
// 	Timer_enu_Initialization();

// 	//Setting ISR
// 	Timer_enu_SetCallBack(TIMER_0, TIMER_NORMAL, tog, &Local_str_TimerCount);

// 	//Setting GIE
// 	SREG_vid_EnableBitI();

// 	while (1)
// 	{
// 		if(Local_str_TimerCount.Flag)
// 		{
// 			DIO_enu_TogglePinValue(DIO_PIN_GROUP_B, DIO_PIN_0);

// 			Local_str_TimerCount.Count = 48;

// 			Local_str_TimerCount.Flag = False;
// 		}
// 	}
	

// 	return 0;
// }




















//Counter Code
// typedef struct 
// {
// 	u8 Flag;
// }Counter_t;

// void LOC_vid_MaximumReached(void* Copy_pvid_ParametersPointer)
// {
// 	((Counter_t*)Copy_pvid_ParametersPointer)->Flag = True;
// }

// int main (void)
// {
	
// 	Counter_t Local_str_Counter = {False};
// 	u16 Local_u8_Count;

	

// 	//Placing '10' value in OCR0 register
// 	Timer_enu_SetOCRxValue(TIMER_0,10);

// 	//Initializing Timer
// 	Timer_enu_Initialization();

// 	//initializing Timer call back function for Timer/Counter 0 compare match
// 	Timer_enu_SetCallBack(TIMER_0, TIMER_CTC, LOC_vid_MaximumReached, &Local_str_Counter);
	
// 	//LCD initialization
// 	LCD_enu_Initialization();

// 	//SEtting GIE
// 	SREG_vid_EnableBitI();

// 	//Configuring T0 pin 
// 	DIO_enu_SetPinDiretion(DIO_PIN_GROUP_B, DIO_PIN_0, DIO_PIN_READ);
// 	DIO_enu_SetPinValue(DIO_PIN_GROUP_B, DIO_PIN_0, DIO_FLOAT);

// 	while (1)
// 	{
// 		//Reading Count
// 		Timer_enu_ReadTCNTxValue(TIMER_0,&Local_u8_Count);

// 		LCD_enu_WriteIntegerNum(Local_u8_Count,LCD_ROW_1,LCD_COLUMN_1,LCD_PAGE_1);

// 		if(Local_str_Counter.Flag)
// 		{
// 			LCD_enu_GoToPosition(LCD_ROW_1,LCD_COLUMN_1,LCD_PAGE_1);

// 			LCD_enu_SendString("Maximum reached");
			
// 			_delay_ms(1000);

// 			Local_str_Counter.Flag = False;
// 		}

// 	}



// 	return 0;
// }
