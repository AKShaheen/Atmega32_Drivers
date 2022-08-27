/*
 * ADC_int.h
 *
 *  Created on: Oct 15, 2021
 *      Author: zezos
 */


#ifndef ADC_V1_ADC_INT_H_
#define ADC_V1_ADC_INT_H_

#include "../../LIB/STD_TYPES.h"

/*--------------------------*/
/*
 * ADMUX PINS
 */
#define REFS1  	(u8)7
#define REFS0  	(u8)6
#define ADLAR	(u8)5
#define MUX4  	(u8)4
#define MUX3  	(u8)3
#define MUX2  	(u8)2
#define MUX1  	(u8)1
#define MUX0  	(u8)0
/*--------------------------*/
/*
 * ADCSRA
 */
#define ADEN 	(u8)7
#define ADSC	(u8)6
#define ADATE	(u8)5
#define ADIF  	(u8)4
#define ADIE	(u8)3
#define ADPS2  	(u8)2
#define ADPS1  	(u8)1
#define ADPS0  	(u8)0
/*--------------------------*/
/*
 * ADC PINS
 */
#define ADC0  	(u8)0
#define ADC1  	(u8)1
#define ADC2  	(u8)2
#define ADC3  	(u8)3
#define ADC4  	(u8)4
#define ADC5  	(u8)5
#define ADC6  	(u8)6
#define ADC7  	(u8)7
/*--------------------------*/

#define CHANNEL_CLEAR_MASK 0b11100000

void ADC_Vidinit(void);
u16 ADC_u16readPin(u8 Copy_u8pin);

#endif /* ADC_V1_ADC_INT_H_ */
