/*
 * LCD_int.h
 *
 *  Created on: Sep 18, 2021
 *      Author: zezos
 */

#ifndef HAL_LCD_HANDLER_LCD_INT_H_
#define HAL_LCD_HANDLER_LCD_INT_H_

#include "../../LIB/STD_TYPES.h"


void LCD_vidinit(void);
void LCD_vidsendCommand(u8 Copy_u8command);
void LCD_vidwriteCharacter(u8 Copy_u8character);
void LCD_vidClrLcd(void);
void LCD_vidSendString(u8 *Copy_u8string);
void LCD_vidSendInt(u32 Copy_u32number);
void LCD_GoToRowCol(u8 row, u8 col);
void LCD_SendStringRowCol(u8 row, u8 col, u8 *str);
#endif /* HAL_LCD_HANDLER_LCD_INT_H_ */
