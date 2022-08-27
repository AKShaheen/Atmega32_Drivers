/*
 * EXT_INT_int.h
 *
 *  Created on: Oct 10, 2021
 *      Author: zezos
 */

#ifndef INTERUPTV1_EXT_INT_INT_H_
#define INTERUPTV1_EXT_INT_INT_H_

#define EXT_INT0	(u8)0
#define EXT_INT1	(u8)1
#define EXT_INT2	(u8)2

#define GIE_ENABLE 	(u8)7

#define ENABLE 		(u8)1
#define DISABLE		(u8)0
#define INT0_ENABLE	(u8)6
#define INT1_ENABLE	(u8)7
#define INT2_ENABLE	(u8)5

#define	ISC_00		(u8)0
#define	ISC_01      (u8)1
#define	ISC_10      (u8)2
#define	ISC_11      (u8)3
#define ISC_2		(u8)6



#define ONLOWLEVEL		(u8)0
#define ONLOGICCHANGE	(u8)1
#define ONFALLINGEDGE	(u8)2
#define ONRISINGEDGE	(u8)3

/*#define INT1_ONLOWLEVEL		(u8)00000000
#define INT1_ONLOGICCHANGE	(u8)00000100
#define INT1_ONFALLINGEDGE	(u8)00001000
#define INT1_ONRISINGEDGE	(u8)00001100

#define INT2_ONFALLINGEDGE	(u8)00000000
#define INT2_ONRISINGEDGE	(u8)01000000*/


u8 EXT_INT_u8enableGIE(u8 Copy_u8mode);
u8 EXT_INT_u8enableDisable(u8 Copy_u8intPin , u8 Copy_u8intMode);
u8 EXT_INT_u8senceControl(u8 Copy_u8intPin , u8 Copy_u8senceControl);
u8 EXT_INT_setCallBack(u8 Copy_u8intPin , void (*Copy_vidpFunc) (void));



#endif /* INTERUPTV1_EXT_INT_INT_H_ */
