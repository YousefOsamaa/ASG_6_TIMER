#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"


#include "../../MCAL/DIO/DIO_Interface.h"

#include "USART_Private.h"
#include "USART_Config.h"


void (*pfun_ISR)(void*) = NULL;
void* pvid_ParamtersOfISrs = NULL; 

//APIs' implementation
extern ErrorState_t USART_enu_Initialization(void)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    //****************************************************************************************
    //                                   Initialize Baud Rate                                              
    //****************************************************************************************

    //Wriing to UBBRH
    UBBRH &= ~(1 << UBBRH_URSEL);

    u16 Local_u16_ValueOfUBRR;

    #if  USART_MODE == USART_NORMAL_ASYNCHRONOUS_MODE    
        
        Local_u16_ValueOfUBRR = USART_BAUD_RATE_MACRO(16);

        //Placing Most Signficant 4 bits in UBBRH 3:0
        UBBRH |= (u8)(Local_u16_ValueOfUBRR >> 8);
        //Placing the least significant 8 bits in UBBRL
        UBBRL = (u8)(Local_u16_ValueOfUBRR); 
   
    #elif  USART_MODE == USART_DOUBLE_SPEED_ASYNCHRONOUS_MODE    
   
        Local_u16_ValueOfUBRR = USART_BAUD_RATE_MACRO(8);

        //Placing Most Signficant 4 bits in UBBRH 3:0
        UBBRH |= (u8)(Local_u16_ValueOfUBRR >> 8);
        //Placing the least significant 8 bits in UBBRL
        UBBRL = (u8)(Local_u16_ValueOfUBRR); 
   
    #elif  USART_MODE == USART_SYNCHRONOUS_MODE    

        Local_u16_ValueOfUBRR = USART_BAUD_RATE_MACRO(2);

        //Placing Most Signficant 4 bits in UBBRH 3:0
        UBBRH |= (u8)(Local_u16_ValueOfUBRR >> 8);
        //Placing the least significant 8 bits in UBBRL
        UBBRL = (u8)(Local_u16_ValueOfUBRR); 
   
    #else
        #error USART_MODE is invalid
    #endif



    //****************************************************************************************
    //                                      Enabling TX and RX        
    //****************************************************************************************
    #if USART_COMMUNICATION_MODE == USART_DISABLE_TX_RX

        //Turning off RX
        UCSRB &= ~( 1 << UCSRB_RXEN );
        //Turning off TX
        UCSRB &= ~( 1 << UCSRB_TXEN );

    #elif USART_COMMUNICATION_MODE == USART_ENABLE_TX_ONLY

        //Turning off RX
        UCSRB &= ~( 1 << UCSRB_RXEN );
        //Turning on TX
        UCSRB |= ( 1 << UCSRB_TXEN );
    
    #elif USART_COMMUNICATION_MODE == USART_ENABLE_RX_ONLY

        //Turning on RX
        UCSRB |= ( 1 << UCSRB_RXEN );
        //Turning off TX
        UCSRB &= ~( 1 << UCSRB_TXEN );

    #elif USART_COMMUNICATION_MODE == USART_EABLE_TX_RX

        //Turning on RX
        UCSRB |= ( 1 << UCSRB_RXEN );
        //Turning on TX
        UCSRB |= ( 1 << UCSRB_TXEN );

    #else

        #error USART_COMMUNICATION_MODE is invalid

    #endif



    //****************************************************************************************
    //                                      Initialzing Synchronization                       
    //****************************************************************************************

    //Writing to UCSRA
    UCSRC |= (1 << UCSRC_URSEL);
    
    #if USART_MODE == USART_SYNCHRONOUS_MODE

        //Choosing Synchronous mode
        UCSRC |= (1 << UCSRC_UMSEL);
    
    #elif USART_MODE == USART_NORMAL_ASYNCHRONOUS_MODE

        //Choosing Asynchronous mode
        UCSRC &= ~(1 << UCSRC_UMSEL);

    #elif USART_MODE == USART_DOUBLE_SPEED_ASYNCHRONOUS_MODE

        //Choosing Asynchronous mode
        UCSRC &= ~(1 << UCSRC_UMSEL);
        //Choosing Double Speed mode
        UCSRA |= (1 << UCSRA_U2X);

    #else

        #error USART_MODE is invalid

    #endif


    //****************************************************************************************
    //                                      Initialzing Frame                       
    //****************************************************************************************
                        
    //1] Character Size:  UCSRB_UCSZ2  UCSRC_UCSZ1  UCSRC_UCSZ0

    //Writing to UCSRC
    UCSRC |= (1 << UCSRC_URSEL);

    //Clearing UCSZ1 and UCSZ0 
    UCSRC &= ~(3 << UCSRC_UCSZ0);
    //Clearing UCSZ2
    UCSRB &= ~(1 << UCSRB_UCSZ2);

    #if USART_CHARACTER_SIZE == USART_5_BITS

        //Bits already contain 000

    #elif USART_CHARACTER_SIZE == USART_6_BITS
        
        //Bits contain 001
        UCSRC |= (1 << UCSRC_UCSZ0);

    #elif USART_CHARACTER_SIZE == USART_7_BITS
        
        //Bits contain 010
        UCSRC |= (1 << UCSRC_UCSZ1);
    
    #elif USART_CHARACTER_SIZE == USART_8_BITS
      
        //Bits contain 011
        UCSRC |= (1 << UCSRC_UCSZ0);
        UCSRC |= (1 << UCSRC_UCSZ1);
    
    #elif USART_CHARACTER_SIZE == USART_9_BITS
      
        //Bits contain 111
        UCSRC |= (1 << UCSRC_UCSZ0);
        UCSRC |= (1 << UCSRC_UCSZ1);
        UCSRB |= (1 << UCSRB_UCSZ2);
    #else

        #error USART_CHARACTER_SIZE is invalid

    #endif


    //2] Stop Bits Selection:    UCSRC_USBS

    //Writing to UCSRC
    UCSRC |= (1 << UCSRC_URSEL);

    #if USART_NUMBER_OF_STOP_BITS == USART_1_STOP_BIT 

        //Bit contains 0
        UCSRC &= ~( 1 << UCSRC_USBS);

    
    #elif USART_NUMBER_OF_STOP_BITS == USART_2_STOP_BITS
        
        //Bit contains 1
        UCSRC |= ( 1 << UCSRC_USBS);

    #else

        #error USART_NUMBER_OF_STOP_BITS is invalid

    #endif


    //3] Parity Check Mode Selection: UCSRC_UPM1 UCSRC_UPM0

    //Writing to UCSRC
    UCSRC |= (1 << UCSRC_URSEL);

    //Bits contain 00
    UCSRC &= ~(3 << UCSRC_UPM0);

    #if USART_PARITY_MODE == USART_DISABLED_PARITY 

        //Bits already contain 00

    
    #elif USART_PARITY_MODE == USART_EVEN_PARITY
   
         //Bits contain 10
         UCSRC |= (1 << UCSRC_UPM1);
        

    #elif USART_PARITY_MODE == USART_ODD_PARITY
    
        //Bits contain 11
        UCSRC |= (3 << UCSRC_UPM0);
    
    #else

        #error USART_PARITY_MODE is invalid

    #endif


    //****************************************************************************************
    //                                      Initialzing Interrupts                       
    //****************************************************************************************

    //Clearing 3 bits  RXCIE TXCIE UDRIE
    UCSRB &= ~(7 << UCSRB_UDRIE); 
    
    #if USART_INTERRUPT_MODE == USART_RXC_INTERRUPT_MODE

        //Bits contains 100
        UCSRB |= (1 << UCSRB_RXCIE);
    
    #elif USART_INTERRUPT_MODE == USART_TXC_INTERRUPT_MODE

        //Bit contains 010
        UCSRB |= (1 << UCSRB_TXCIE);

    #elif USART_INTERRUPT_MODE == USART_EDRE_INTERRUPT_MODE

        //Bit contains 001
        UCSRB |= (1 << UCSRB_UDRIE);

    #elif USART_INTERRUPT_MODE == USART_POLLING_MODE

        //Bits already contain 000
    
    #else
    
        #error USART_INTERRUPT_MODE is invalid
    
    #endif





    return Local_u8_ErrorFlag;
}

extern ErrorState_t USART_enu_SendData(u16 Copy_u16_Data)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    //Seeing if Transmitter Buffer is ready to take a new value
    if((UCSRA >> UCSRA_UDRE) & 1)
    {
        #if USART_CHARACTER_SIZE == USART_9_BITS

            //Getting 9nth-bit from Data
            u8 Local_u8_DataBit8 = (Copy_u16_Data >> 8) & 1;

            //Placing 9nth-bit in TXB8
            UCSRB |= (Local_u8_ErrorFlag << UCSRB_TXB8);

        #endif
        
        UDR = (u8)(Copy_u16_Data);

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_WAIT;
    }

    return Local_u8_ErrorFlag;
}

extern ErrorState_t USART_enu_ReceiveData(u16* Copy_pu16_Data)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    u16 Local_u16_TempData = 0x00;

    //Seeing if Receiver Buffer has a new value
    if((UCSRA >> UCSRA_RXC) & 1)
    {

        #if USART_CHARACTER_SIZE == USART_9_BITS

            //Getting 9nth-bit from Data
            u8 Local_u8_DataBit8 = (UCSRB >> UCSRB_RXB8) & 1;

            //Placing 9nth-bit in Local Temp
            Local_u16_TempData |= (Local_u8_DataBit8 >> 8); 

        #endif

        //Placing rest of data in Local temp
        Local_u16_TempData = UDR;
        
        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_WAIT;

        Local_u16_TempData = USART_NOT_DATA_RECEIVED;
    }

    
    *Copy_pu16_Data = Local_u16_TempData;

    return Local_u8_ErrorFlag;
}

extern ErrorState_t USART_enu_SendString (u8* Copy_pu8_String)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_pu8_String)
    {
        u8* Local_pu8_SendingPoninter = Copy_pu8_String;

        while(*Local_pu8_SendingPoninter)
        {
            USART_enu_SendData(*Local_pu8_SendingPoninter);

            Local_pu8_SendingPoninter++;
        }
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }
    return Local_u8_ErrorFlag;

}

extern ErrorState_t USART_enu_SetCallBack (void (*Copy_pfun_AppFun)(void*), void* Copy_pvid_Paramters)
{
    u8 Local_u8_ErrorFlag = ES_NOK;

    if(Copy_pfun_AppFun)
    {
        pfun_ISR = Copy_pfun_AppFun;

        pvid_ParamtersOfISrs = Copy_pvid_Paramters;

        Local_u8_ErrorFlag = ES_OK;
    }
    else
    {
        Local_u8_ErrorFlag = ES_NULL_POINTER;
    }

    return Local_u8_ErrorFlag;
}

//ISRs
#if USART_INTERRUPT_MODE == USART_RXC_INTERRUPT_MODE
   
    void __vector_13 (void)__attribute__((signal));
   
    void __vector_13 (void)
    {
        if(pfun_ISR)
        {
            pfun_ISR(pvid_ParamtersOfISrs);
        }
    }
    
#elif  USART_INTERRUPT_MODE == USART_EDRE_INTERRUPT_MODE
    
    void __vector_14 (void)__attribute__((signal));
    
    void __vector_14 (void)
    {
        if(pfun_ISR)
        {
            pfun_ISR(pvid_ParamtersOfISrs);
        }
    }

#elif  USART_INTERRUPT_MODE == USART_TXC_INTERRUPT_MODE
    
    void __vector_15 (void)__attribute__((signal));
    
    void __vector_15 (void)
    {
        if(pfun_ISR)
        {
            pfun_ISR(pvid_ParamtersOfISrs);
        }
    }

#endif

//Local functions' implementation


