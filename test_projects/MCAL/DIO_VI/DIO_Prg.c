/*
 * DIO_Prg.c

 *
 *  Created on: Sep 17, 2021
 *      Author: zezos
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_reg.h"
#include "DIO_int.h"

#define RT_OK		(u8)0
#define RT_NOK		(u8)1
#define NULL		(void *)0

u8	DIO_u8setPortDirection(u8 Copy_u8port , u8 Copy_u8direction){

	u8 Local_u8errStatus = RT_OK ;
	switch(Copy_u8port){
	case PORT_A :	DDRA_REG = Copy_u8direction ;	break ;
	case PORT_B :   DDRB_REG = Copy_u8direction ;   break ;
	case PORT_C :   DDRC_REG = Copy_u8direction ;   break ;
	case PORT_D	:   DDRD_REG = Copy_u8direction ;   break ;
	default 	:	Local_u8errStatus = RT_NOK 	;
	}
	return Local_u8errStatus ;
}

u8  DIO_u8setPortValue(u8 Copy_u8port , u8 Copy_u8value){

	u8 Local_u8errStatus = RT_OK ;
	switch(Copy_u8port){
	case PORT_A :	PORTA_REG = Copy_u8value ;	 break ;
	case PORT_B :   PORTB_REG = Copy_u8value ;   break ;
	case PORT_C :   PORTC_REG = Copy_u8value ;   break ;
	case PORT_D	:   PORTD_REG = Copy_u8value ;   break ;
	default 	:	Local_u8errStatus = RT_NOK 	;
	}
	return Local_u8errStatus ;
}

u8  DIO_u8getPortValue(u8 Copy_u8port , u8 * Copy_u8pValue){

	u8 Local_u8errStatus = RT_OK ;
	if(Copy_u8pValue != NULL){
		switch(Copy_u8port){
		case PORT_A :	* Copy_u8pValue = PINA_REG ;   break ;
		case PORT_B :   * Copy_u8pValue = PINB_REG ;   break ;
		case PORT_C :   * Copy_u8pValue = PINC_REG ;   break ;
		case PORT_D	:   * Copy_u8pValue = PIND_REG ;   break ;
		default 	:	Local_u8errStatus = RT_NOK ;
		}
	}
	else{
		Local_u8errStatus = RT_NOK ;
	}
	return Local_u8errStatus ;
}

u8  DIO_u8setPinDirection(u8 Copy_u8port , u8 Copy_u8pin , u8 Copy_u8direction){

	u8 Local_u8errStatus = RT_OK ;
	if(Copy_u8pin <=7){
		switch(Copy_u8direction){
		case INPUT :
			switch(Copy_u8port){
			case PORT_A : CLR_BIT(DDRA_REG , Copy_u8pin);	break;
			case PORT_B : CLR_BIT(DDRB_REG , Copy_u8pin);	break;
			case PORT_C : CLR_BIT(DDRC_REG , Copy_u8pin);	break;
			case PORT_D : CLR_BIT(DDRD_REG , Copy_u8pin);	break;
			default 	:	Local_u8errStatus = RT_NOK ;	break;
			}
			break ;
			case OUTPUT :
				switch(Copy_u8port){
				case PORT_A : SET_BIT(DDRA_REG , Copy_u8pin);	break;
				case PORT_B : SET_BIT(DDRB_REG , Copy_u8pin);	break;
				case PORT_C : SET_BIT(DDRC_REG , Copy_u8pin);	break;
				case PORT_D : SET_BIT(DDRD_REG , Copy_u8pin);	break;
				default 	:	Local_u8errStatus = RT_NOK ;	break;
				}
				break ;
				default		: 	Local_u8errStatus = RT_NOK ;
		}
	}
	else{
		u8 Local_u8errStatus = RT_NOK ;
	}
	return Local_u8errStatus ;
}
u8  DIO_u8setPinValue(u8 Copy_u8port , u8 Copy_u8pin , u8 Copy_u8value){

	u8 Local_u8errStatus = RT_OK ;
	if(Copy_u8pin <=7){
		switch(Copy_u8value){
		case LOW :
			switch(Copy_u8port){
			case PORT_A : CLR_BIT(PORTA_REG , Copy_u8pin);	break;
			case PORT_B : CLR_BIT(PORTB_REG , Copy_u8pin);	break;
			case PORT_C : CLR_BIT(PORTC_REG , Copy_u8pin);	break;
			case PORT_D : CLR_BIT(PORTD_REG , Copy_u8pin);	break;
			default 	:	Local_u8errStatus = RT_NOK ;	break;
			}
			break ;
			case HIGH :
				switch(Copy_u8port){
				case PORT_A : SET_BIT(PORTA_REG , Copy_u8pin);	break;
				case PORT_B : SET_BIT(PORTB_REG , Copy_u8pin);	break;
				case PORT_C : SET_BIT(PORTC_REG , Copy_u8pin);	break;
				case PORT_D : SET_BIT(PORTD_REG , Copy_u8pin);	break;
				default 	:	Local_u8errStatus = RT_NOK ;	break;
				}
				break ;
				default		: 	Local_u8errStatus = RT_NOK ;
		}
	}
	else{
		u8 Local_u8errStatus = RT_NOK ;
	}
	return Local_u8errStatus ;
}
u8  DIO_u8getPinValue(u8 Copy_u8port , u8 Copy_u8pin , u8 * Copy_u8pValue){

	u8 Local_u8errStatus = RT_OK ;

	if(Copy_u8pin <= PIN_7){
		switch(Copy_u8port){
		case PORT_A : * Copy_u8pValue = GET_BIT(PORTA_REG , Copy_u8pin);	break;
		case PORT_B : * Copy_u8pValue = GET_BIT(PORTB_REG , Copy_u8pin);	break;
		case PORT_C : * Copy_u8pValue = GET_BIT(PORTC_REG , Copy_u8pin);	break;
		case PORT_D : * Copy_u8pValue = GET_BIT(PORTD_REG , Copy_u8pin);	break;
		default 	:	Local_u8errStatus = RT_NOK ;
		}
	}
	else{
		Local_u8errStatus = RT_NOK ;
	}
	return Local_u8errStatus ;
}


