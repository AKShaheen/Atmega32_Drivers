/*
 * EXT_INT_reg.h
 *
 *  Created on: Oct 10, 2021
 *      Author: zezos
 */

#ifndef INTERUPTV1_EXT_INT_REG_H_
#define INTERUPTV1_EXT_INT_REG_H_

#define GICR_REG 	*((volatile u8 *)0x5B)
#define GIFR_REG 	*((volatile u8 *)0x5A)
#define MCUCR_REG 	*((volatile u8 *)0x55)
#define MCUCSR_REG	*((volatile u8 *)0x54)
#define SREG_REG	*((volatile u8 *)0x5F)


void __vector_1(void) __attribute__ ((signal, used, externally_visible));
void __vector_2(void) __attribute__ ((signal, used, externally_visible));
void __vector_3(void) __attribute__ ((signal, used, externally_visible));
#endif /* INTERUPTV1_EXT_INT_REG_H_ */
