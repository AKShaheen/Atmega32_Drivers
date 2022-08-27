/*
 * EXT_INT_prg.c
 *
 *  Created on: Oct 10, 2021
 *      Author: zezos
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/ERR_TYPES.h"
#include "EXT_INT_reg.h"
#include "EXT_INT_int.h"

void (* int0CallBackPtr) (void) ;
void (* int1CallBackPtr) (void) ;
void (* int2CallBackPtr) (void) ;



u8 EXT_INT_u8enableGIE(u8 Copy_u8mode){
	u8 Local_u8errStatus = RT_OK ;
	switch(Copy_u8mode){
	case ENABLE  : 	SET_BIT(SREG_REG,GIE_ENABLE);	break;
	case DISABLE : 	CLR_BIT(SREG_REG,GIE_ENABLE); 	break;
	default		 :	Local_u8errStatus = RT_NOK ; break;
	}
	return Local_u8errStatus ;
}

u8 EXT_INT_u8enableDisable(u8 Copy_u8intPin , u8 Copy_u8intMode){
	u8 Local_u8errStatus = RT_OK ;
	if(Copy_u8intPin <=2){
		switch(Copy_u8intMode){
		case DISABLE :
			switch(Copy_u8intPin){
			case EXT_INT0 	: CLR_BIT(GICR_REG , INT0_ENABLE);	break;
			case EXT_INT1 	: CLR_BIT(GICR_REG , INT1_ENABLE);	break;
			case EXT_INT2	: CLR_BIT(GICR_REG , INT2_ENABLE);	break;
			default 	:	Local_u8errStatus = RT_NOK ;	break;
			}
			break ;
			case ENABLE :
				switch(Copy_u8intPin){
				case EXT_INT0 	: SET_BIT(GICR_REG , INT0_ENABLE);	break;
				case EXT_INT1 	: SET_BIT(GICR_REG , INT1_ENABLE);	break;
				case EXT_INT2	: SET_BIT(GICR_REG , INT2_ENABLE);	break;
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
u8 EXT_INT_u8senceControl(u8 Copy_u8intPin , u8 Copy_u8senceControl){

	u8 Local_u8errStatus = RT_OK ;
	if(Copy_u8intPin <=2){
		switch(Copy_u8intPin){
		case EXT_INT0 :
			switch(Copy_u8senceControl){
			case ONLOWLEVEL 	: CLR_BIT(MCUCR_REG , ISC_00);	CLR_BIT(MCUCR_REG , ISC_01);	break;
			case ONLOGICCHANGE	: SET_BIT(MCUCR_REG , ISC_00);	CLR_BIT(MCUCR_REG , ISC_01);	break;
			case ONFALLINGEDGE	: CLR_BIT(MCUCR_REG , ISC_00);	SET_BIT(MCUCR_REG , ISC_01);	break;
			case ONRISINGEDGE	: SET_BIT(MCUCR_REG , ISC_00);	SET_BIT(MCUCR_REG , ISC_01);	break;
			default 			: Local_u8errStatus = RT_NOK ;									break;
			}
			break ;
			case EXT_INT1 :
				switch(Copy_u8senceControl){
				case ONLOWLEVEL 	: CLR_BIT(MCUCR_REG , ISC_10);	CLR_BIT(MCUCR_REG , ISC_11);	break;
				case ONLOGICCHANGE	: SET_BIT(MCUCR_REG , ISC_10);	CLR_BIT(MCUCR_REG , ISC_11);	break;
				case ONFALLINGEDGE	: CLR_BIT(MCUCR_REG , ISC_10);	SET_BIT(MCUCR_REG , ISC_11);	break;
				case ONRISINGEDGE	: SET_BIT(MCUCR_REG , ISC_10);	SET_BIT(MCUCR_REG , ISC_11);	break;
				default 			: Local_u8errStatus = RT_NOK ;						break;
				}
				break ;
				case EXT_INT2 :
					switch(Copy_u8senceControl){
					case ONFALLINGEDGE	: CLR_BIT(MCUCR_REG , ISC_2);		break;
					case ONRISINGEDGE	: SET_BIT(MCUCR_REG , ISC_2);		break;
					default 			: Local_u8errStatus = RT_NOK ;	break;
					}
					break ;
					default		: 	Local_u8errStatus = RT_NOK ;	break;
		}
	}
	else{
		u8 Local_u8errStatus = RT_NOK ;
	}
	return Local_u8errStatus ;
}
u8 EXT_INT_setCallBack(u8 Copy_u8intPin , void (*Copy_vidpFunc) (void)){
	u8 Local_u8errStatus = RT_OK ;
	switch(Copy_u8intPin){
	case EXT_INT0 :	int0CallBackPtr = Copy_vidpFunc ; break;
	case EXT_INT1 :	int1CallBackPtr = Copy_vidpFunc ; break;
	case EXT_INT2 :	int2CallBackPtr = Copy_vidpFunc ; break;
	default		: 	Local_u8errStatus = RT_NOK ;
	}
	return Local_u8errStatus ;

}

void __vector_1(void){
		int0CallBackPtr();
}
void __vector_2(void){
		int1CallBackPtr();
}
void __vector_3(void){
		int2CallBackPtr();
}

