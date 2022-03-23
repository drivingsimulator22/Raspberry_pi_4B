/*
 * UART.h
 *
 * Created: 3/2/2022 10:24:54 PM
 *  Author: "Lankash"
 *
 * Content: UART Functions Deceleration
 */ 

#ifndef UART_H_
#define UART_H_

//.......................................................

/*
Choosing no. of bits in the word of the data frame.
UMSEL:     @0=Asynchronous | @1=Synchronous.
UPM(0-1):  @00=Disabled | @10=Even Parity | @11=Odd Parity.
USBS:      @0=1-bit stop | @1=2-bit stop
UCSZ(0-2): @000=5-bit word ... @111=9-bit word
UCPOL:     @0=O/P rising edge | @1= O/P falling edge.
*/
#define synchronization 0    //@1 = Synchronized

#define parity_1 0
#define parity_0 0

#define stop_bit 0    //@0 = 1 stop bit, @1 = 2 stop bits

#define size_0 1      //000 = 5-bit word
#define size_1 1      // . . . . . . . .
#define size_2 0      //111 = 9-bit word

#define polarity 0    //@0=O/P rising edge | @1= O/P falling edge.

//.......................................................
/*
  Double speed of bit rate @Asynchronous operation mode.
*/
//#define double_on
#define double_off

//.......................................................

/*
    Function name         :  UART_init
    Function Returns      :  void
    Function Arguments    :  unsigned long baud
    Function Description  :  Initialize the USART communication.
*/
void UART_init (unsigned long baud);


/*
    Function name         :  UART_send
    Function Returns      :  void
    Function Arguments    :  char UART_send
    Function Description  :  Send data by UART.
*/
void UART_send_char (char data);


/*
    Function name         :  UART_receive
    Function Returns      :  char
    Function Arguments    :  void
    Function Description  :  Receive data by UART.
*/
char UART_receive (void);


/*
    Function name         :  UART_send_string
    Function Returns      :  void
    Function Arguments    :  char *str
    Function Description  :  Send string by UART.
*/
void UART_send_string (char *str);

//.......................................................

#endif