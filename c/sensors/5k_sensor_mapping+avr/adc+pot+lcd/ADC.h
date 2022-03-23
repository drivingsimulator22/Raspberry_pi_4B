 /*

Code created by "LANKASH"
  @14/10/2021

File Contents : 'ADC' implemented Functions Prototypes + Macros.

*/
 
#ifndef ADC_H_
#define ADC_H_
 
//#define Div_factor_2          //ADC Clock divisor = 2
//#define Div_factor_4          //ADC Clock divisor = 4
//#define Div_factor_8          //ADC Clock divisor = 8
//#define Div_factor_16          //ADC Clock divisor = 16
//#define Div_factor_32          //ADC Clock divisor = 32
#define Div_factor_64          //ADC Clock divisor = 64
//#define Div_factor_128          //ADC Clock divisor = 128

//.....................................................

/*
    Function name         :  ADC_init
    Function Returns      :  void
    Function Arguments    :  void
    Function Description  :  Initialize the ADC of the Micro controller.
*/
void ADC_init ();


/*
    Function name         :  ADC_read
    Function Returns      :  unsigned short
    Function Arguments    :  void
    Function Description  :  Read the value from the ' ADC' of the Micro controller.
*/
unsigned short ADC_read ();


/*
    Function name         :  ADC_pin
    Function Returns      :  void
    Function Arguments    :  unsigned char pin
    Function Description  :  Select which ADC pin in Port 'A' (0 - 7).
*/
void ADC_pin (unsigned char pin);
//................................................................................

#endif