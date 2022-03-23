/*
 * SPI.h
 *
 * Created: 3/8/2022 10:16:16 PM
 *  Author: Lankash
 */ 


#ifndef SPI_H_
#define SPI_H_

//..............................................................
 /*
   Set the clock prescaler of the SPI Master.
 */
//#define prescaler_2
//#define prescaler_4
//#define prescaler_8
#define prescaler_16
//#define prescaler_32
//#define prescaler_64
//#define prescaler_128

//..............................................................

/*
    Function name         :  SPI_master_init
    Function Returns      :  void
    Function Arguments    :  void
    Function Description  :  Initialize the SPI for Master M.C
*/
void SPI_master_init (void);

/*
    Function name         :  SPI_slave_init
    Function Returns      :  void
    Function Arguments    :  void
    Function Description  :  Initialize the SPI for Slave M.C
*/
void SPI_slave_init(void);


/*
    Function name         :  SPI_master_send_char
    Function Returns      :  unsigned char
    Function Arguments    :  unsigned char char
    Function Description  :  Send char From Master to Slave via SPI.
*/
unsigned char SPI_master_send_char(unsigned char data);


/*
    Function name         :  SPI_slave_recieve_char
    Function Returns      :  unsigned char
    Function Arguments    :  unsigned char data
    Function Description  :  Slave Receive data from Master via SPI.
*/
unsigned char SPI_slave_receive_char (unsigned char data);


/*
    Function name         :  SPI_master_send_string
    Function Returns      :  void
    Function Arguments    :  unsigned char *string
    Function Description  :  Send string From Master to Slave via SPI.
*/
void SPI_master_send_string (unsigned char *string);

#endif /* SPI_H_ */