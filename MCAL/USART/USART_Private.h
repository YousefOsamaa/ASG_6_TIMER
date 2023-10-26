#ifndef USART_PRIVATE_FILE
#define USART_PRIVATE_FILE



#include "../../LIB/STD.h"
#include "../../LIB/ErrorStates.h"

//USART Data Register - UDR
#define UDR *(volatile u8*)0x2C
typedef enum
{
    UDR_RX0 , //Receiver Buffer Bit 0
    UDR_RX1 , //Receiver Buffer Bit 1
    UDR_RX2 , //Receiver Buffer Bit 2
    UDR_RX3 , //Receiver Buffer Bit 3
    UDR_RX4 , //Receiver Buffer Bit 4 
    UDR_RX5 , //Receiver Buffer Bit 5
    UDR_RX6 , //Receiver Buffer Bit 6
    UDR_RX7 , //Receiver Buffer Bit 7

}UDR_RX_t;

typedef enum
{
    UDR_TX0 , //Transmitter Buffer Bit 0
    UDR_TX1 , //Transmitter Buffer Bit 1
    UDR_TX2 , //Transmitter Buffer Bit 2
    UDR_TX3 , //Transmitter Buffer Bit 3
    UDR_TX4 , //Transmitter Buffer Bit 4
    UDR_TX5 , //Transmitter Buffer Bit 5
    UDR_TX6 , //Transmitter Buffer Bit 6
    UDR_TX7 , //Transmitter Buffer Bit 7

}UDR_TX_t;


//USART Control and Status Register A - UCSRA
#define UCSRA *(volatile u8*)0x2B
typedef enum 
{
    UCSRA_MPCM , //Enable Multi-Processor Communication Mode
    UCSRA_U2X ,  //Enable Double Speed Asynchronous Mode (Write as zero in Synchronous)
    UCSRA_PE ,   //Parity Error Flag
    UCSRA_DOR ,  //DataOver Run Flag
    UCSRA_FE ,   //Frame Error Flag
    UCSRA_UDRE , //USART Data Register Empty Flag
    UCSRA_TXC ,  //Transmit Complete Flag
    UCSRA_RXC ,  //Receive Complete Flag

}UCSRA_t;

//USART Control and Status Register B - UCSRB
#define UCSRB *(volatile u8*)0x2A
typedef enum 
{
    UCSRB_TXB8 , //Transmitter Buffer Bit 8
    UCSRB_RXB8 , //Receiver Buffer Bit 8
    UCSRB_UCSZ2, //Character Size Bit 2
    UCSRB_TXEN , //Transmitter Enable
    UCSRB_RXEN , //Receiver Enable
    UCSRB_UDRIE, //USART Data Register Empty Interrupt Enable
    UCSRB_TXCIE , //Transmit Complete Interrupt Enable
    UCSRB_RXCIE , //Receive Complete Interrupt Enable

}UCSRB_t;

//USART Control and Status Register C - UCSRC
#define UCSRC *(volatile u8*)0x40
typedef enum 
{
    UCSRC_UCPOL , //USART Clock Polarity (Synchronous only)
    UCSRC_UCSZ0 , //Character Size Bit 0
    UCSRC_UCSZ1 , //Character Size Bit 1
    UCSRC_USBS ,  //USART Stop Bit Selection
    UCSRC_UPM0 ,  //USART Parity Mode Bit 0
    UCSRC_UPM1 ,  //USART Parity Mode Bit 1
    UCSRC_UMSEL , //USART Mode Selection
    UCSRC_URSEL , //USART Register Selection (Write as 1)

}UCSRC_t;

//USART Baud Rate Register High - UBBRH
#define UBBRH *(volatile u8*)0x40
typedef enum 
{
    UBBRH_B0 , //USART Baude Rate Register Bit 8
    UBBRH_B1 , //USART Baude Rate Register Bit 9
    UBBRH_B2 , //USART Baude Rate Register Bit 10
    UBBRH_B3 , //USART Baude Rate Register Bit 11
    UBBRH_RESERVED_0 ,
    UBBRH_RESERVED_1,
    UBBRH_RESERVED_2 ,
    UBBRH_URSEL , //USART Register Selection (Write as 0)

}UBBRH_t;

//USART Baud Rate Register Low - UBBRL
#define UBBRL *(volatile u8*)0x29
typedef enum 
{
    UBBRL_B0 , //USART Baude Rate Register Bit 0
    UBBRL_B1 , //USART Baude Rate Register Bit 1
    UBBRL_B2 , //USART Baude Rate Register Bit 2
    UBBRL_B3 , //USART Baude Rate Register Bit 3
    UBBRL_B4 , //USART Baude Rate Register Bit 4
    UBBRL_B5 , //USART Baude Rate Register Bit 5
    UBBRL_B6 , //USART Baude Rate Register Bit 6
    UBBRL_B7 , //USART Baude Rate Register Bit 7
    
}UBBRL_t;

//USART Modes
#define USART_NORMAL_ASYNCHRONOUS_MODE         0
#define USART_DOUBLE_SPEED_ASYNCHRONOUS_MODE   1
#define USART_SYNCHRONOUS_MODE                 2


//Asynchrounous Baude Rates
#define USART_BAUD_RATE_MACRO(SPEED_FACTOR) (u16)((F_CPU/(SPEED_FACTOR*USART_BAUDE_RATE)) - 1)
#define USART_BR_9600             9600UL
#define USART_BR_38_4_K           38400UL
#define USART_BR_115_2_K          115200UL

//Communication Status
#define USART_DISABLE_TX_RX             0
#define USART_EABLE_TX_RX               1
#define USART_ENABLE_TX_ONLY            2 
#define USART_ENABLE_RX_ONLY            3

//PArity Modes
#define USART_DISABLED_PARITY   0
#define USART_EVEN_PARITY       1
#define USART_ODD_PARITY        2

//Character Sizes
#define USART_5_BITS        0 
#define USART_6_BITS        1
#define USART_7_BITS        2 
#define USART_8_BITS        3 
#define USART_9_BITS        4

//Local functions' prototype
#define USART_1_STOP_BIT     0
#define USART_2_STOP_BITS    1

//Interrupt Modes
#define USART_POLLING_MODE          0
#define USART_RXC_INTERRUPT_MODE    1
#define USART_TXC_INTERRUPT_MODE    2
#define USART_EDRE_INTERRUPT_MODE   3

#define USART_NOT_DATA_RECEIVED  0xFF
#define USART_NUMBER_OF_ISRS      3

#endif
