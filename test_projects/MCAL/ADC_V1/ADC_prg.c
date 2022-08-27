/*
 * ADC_prg.c
 *
 *  Created on: Oct 15, 2021
 *      Author: zezos
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_int.h"
#include "ADC_reg.h"


void ADC_Vidinit(void){

	/*
	 * Config the ref voltage
	 */
	SET_BIT(ADMUX_REG,REFS0);
	CLR_BIT(ADMUX_REG,REFS1);
	/*----------------------------*/

	/*
	 * Config the Resolution to 10 bit
	 */
	CLR_BIT(ADMUX_REG,ADLAR);
	/*----------------------------*/
	/*
	 * Enable the ADS
	 */
	SET_BIT(ADCSRA_REG,ADEN);
	/*----------------------------*/
	/*
	 *Disable Auto trigger
	 */
	CLR_BIT(ADCSRA_REG,ADATE);
	/*----------------------------*/
	/*
	 * Config ADC Prescaller
	 */
	SET_BIT(ADCSRA_REG,ADPS2);
	CLR_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS0);
	/*----------------------------*/
}

u16 ADC_u16readPin(u8 Copy_u8pin){

	ADMUX_REG &= CHANNEL_CLEAR_MASK ;
	ADMUX_REG |= Copy_u8pin ;
	/*switch(Copy_u8pin){
	case ADC0 : CLR_BIT(ADMUX_REG,MUX0);  CLR_BIT(ADMUX_REG,MUX1);  CLR_BIT(ADMUX_REG,MUX2);  break;
	case ADC1 : SET_BIT(ADMUX_REG,MUX0);  CLR_BIT(ADMUX_REG,MUX1);  CLR_BIT(ADMUX_REG,MUX2);  break;
	case ADC2 : CLR_BIT(ADMUX_REG,MUX0);  SET_BIT(ADMUX_REG,MUX1);  CLR_BIT(ADMUX_REG,MUX2);  break;
	case ADC3 : SET_BIT(ADMUX_REG,MUX0);  SET_BIT(ADMUX_REG,MUX1);  CLR_BIT(ADMUX_REG,MUX2);  break;
	case ADC4 : CLR_BIT(ADMUX_REG,MUX0);  CLR_BIT(ADMUX_REG,MUX1);  SET_BIT(ADMUX_REG,MUX2);  break;
	case ADC5 : SET_BIT(ADMUX_REG,MUX0);  CLR_BIT(ADMUX_REG,MUX1);  SET_BIT(ADMUX_REG,MUX2);  break;
	case ADC6 : CLR_BIT(ADMUX_REG,MUX0);  SET_BIT(ADMUX_REG,MUX1);  SET_BIT(ADMUX_REG,MUX2);  break;
	case ADC7 : SET_BIT(ADMUX_REG,MUX0);  SET_BIT(ADMUX_REG,MUX1);  SET_BIT(ADMUX_REG,MUX2);  break;
	}*/
	SET_BIT(ADCSRA_REG,ADSC);
	while(!GET_BIT(ADCSRA_REG,ADIF));
	SET_BIT(ADCSRA_REG,ADIF);
	/*
	 * The hard way if you don't know the computer Architecture
	 * Digital_Read = 	ADCL_REG ;
	 * u16 Digital_Read = 0 ;
	 * Digital_Read |= (ADCH_REG<<8) ;
	 */
	return ADC_REG;
}

