/*
 * KEYPAD_int.h
 *
 *  Created on: Sep 20, 2021
 *      Author: Farid
 */

#ifndef HAL_KEYPAD_HANDLER_KEYPAD_INT_H_
#define HAL_KEYPAD_HANDLER_KEYPAD_INT_H_

void KEYPAD_vidInit(void);
u8 KEYPAD_u8GetPressed(void);
u8 KEYPAD_u8CheckKey(u8 Copy_u8KeyId);
void KEYPAD_vidGetAll(u8 *Copy_u8ptrKeyArray);

#endif /* HAL_KEYPAD_HANDLER_KEYPAD_INT_H_ */
