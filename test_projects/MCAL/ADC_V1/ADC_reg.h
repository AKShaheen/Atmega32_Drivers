/*
 * ADC_reg.h
 *
 *  Created on: Oct 15, 2021
 *      Author: zezos
 */

#ifndef ADC_V1_ADC_REG_H_
#define ADC_V1_ADC_REG_H_

#define ADMUX_REG 	*((volatile u8 *)0x27)
#define ADCSRA_REG 	*((volatile u8 *)0x26)
#define ADCH_REG 	*((volatile u8 *)0x25)
#define ADCL_REG 	*((volatile u8 *)0x24)
#define ADC_REG		*((volatile u16 *)0x24)
#define SFIOR_REG	*((volatile u8 *)0x50)



#endif /* ADC_V1_ADC_REG_H_ */
