  /*

Code created by "LANKASH"
  @14/10/2021

File Contents : 'ADC' implementation Functions

*/

#include <avr/io.h>
#include "my_macros.h"
#include "ADC.h"

void ADC_init ()
{
  SET_BIT (ADMUX, REFS0);    //Configure Volt as 5V + Cap. @AREF pin.
  //SET_BIT (ADMUX, REFS1);
  SET_BIT (ADCSRA, ADEN);    //Enable the ADC Bit.
  
  //Adjust ADC Clock.
  #if defined Div_factor_2
  CLR_BIT (ADCSRA, ADPS0);
  CLR_BIT (ADCSRA, ADPS1);
  CLR_BIT (ADCSRA, ADPS2);
  
  #elif defined Div_factor_4
  CLR_BIT (ADCSRA, ADPS0);
  SET_BIT (ADCSRA, ADPS1);
  CLR_BIT (ADCSRA, ADPS2);
  
  #elif defined Div_factor_8
  SET_BIT (ADCSRA, ADPS0);
  SET_BIT (ADCSRA, ADPS1);
  CLR_BIT (ADCSRA, ADPS2);  
  
  #elif defined Div_factor_16
  CLR_BIT (ADCSRA, ADPS0);
  CLR_BIT (ADCSRA, ADPS1);
  SET_BIT (ADCSRA, ADPS2);

  #elif defined Div_factor_32
  SET_BIT (ADCSRA, ADPS0);
  CLR_BIT (ADCSRA, ADPS1);
  SET_BIT (ADCSRA, ADPS2);

  #elif defined Div_factor_64
  CLR_BIT (ADCSRA, ADPS0);
  SET_BIT (ADCSRA, ADPS1);
  SET_BIT (ADCSRA, ADPS2);

  #elif defined Div_factor_128
  SET_BIT (ADCSRA, ADPS0);
  SET_BIT (ADCSRA, ADPS1);
  SET_BIT (ADCSRA, ADPS2);
  #endif
}

//.....................................................................

unsigned short ADC_read ()
{
	unsigned short ADC_val;             //Declaring the Converted value from ADC Holder.
	
	SET_BIT (ADCSRA, ADSC);              //Start The Conversion from ADC.
	
	while (IS_BIT_CLR(ADCSRA, ADIF)) ;   //Stand-Still While ADC Conversion.
	
	SET_BIT(ADCSRA, ADIF);               //Clear the Flag Bit of ADC.
	
	ADC_val = (ADCL);                    // Reading the Low Value from ADC.
	ADC_val |= (ADCH<<8);                // Reading the High Value from ADC.
	
	return ADC_val;           
}

//.......................................................................

void ADC_pin (unsigned char pin)
{
	switch (pin)
	{
		case 0 :
		CLR_BIT(ADMUX, MUX0);
		CLR_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX2);
		//CLR_BIT(ADMUX, MUX3);
		//CLR_BIT(ADMUX, MUX4);
		break;
		
		case 1 :
		SET_BIT(ADMUX, MUX0);
		CLR_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX2);
		//CLR_BIT(ADMUX, 3);
		//CLR_BIT(ADMUX, 4);
		break;
		
		case 2 :
		CLR_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX2);
		//CLR_BIT(ADMUX, 3);
		//CLR_BIT(ADMUX, 4);
		break;
		
		case 3 :
		SET_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		CLR_BIT(ADMUX, MUX2);
		//CLR_BIT(ADMUX, 3);
		//CLR_BIT(ADMUX, 4);
		break;
		
		case 4 :
		CLR_BIT(ADMUX, MUX0);
		CLR_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		//CLR_BIT(ADMUX, 3);
		//CLR_BIT(ADMUX, 4);
		break;
		
		case 5 :
		SET_BIT(ADMUX, MUX0);
		CLR_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		//CLR_BIT(ADMUX, 3);
		//CLR_BIT(ADMUX, 4);
		break;
		
		case 6 :
		CLR_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		//CLR_BIT(ADMUX, 3);
		//CLR_BIT(ADMUX, 4);
		break;
		
		case 7 :
		SET_BIT(ADMUX, MUX0);
		SET_BIT(ADMUX, MUX1);
		SET_BIT(ADMUX, MUX2);
		//CLR_BIT(ADMUX, 3);
		//CLR_BIT(ADMUX, 4);
		break;
		
		default :
		break;
	}
}

//.......................................................................