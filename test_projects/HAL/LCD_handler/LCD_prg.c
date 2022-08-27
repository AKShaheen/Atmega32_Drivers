/*
 * LCD_prg.c
 *
 *  Created on: Sep 18, 2021
 *      Author: zezos
 */

#include "LCD_cfg.h"
#include "../../MCAL/DIO_VI/DIO_int.h"
#include "../../LIB/STD_TYPES.h"
#include "util/delay.h"

#define LCD_FUNCTION_SET_CMD		(u8)0b00111000
#define LCD_DISPLAY_ON_CMD			(u8)0b00001100
#define LCD_DISPLAY_CLEAR_CMD		(u8)0b00000001
#define LCD_ENTRY_MODE_SET_CMD		(u8)0b00000110
#define LCD_SET_CURSOR_LOCATION 	(u8)0x80
#define LCD_CURSOR_OFF 				(u8)0x0C
#define LCD_CURSOR_ON 				(u8)0b1111



void LCD_vidsendCommand(u8 Copy_u8command);

void LCD_vidinit(void){

	DIO_u8setPortDirection(LCD_DATA_PORT , FULL_OUTPUT);
	DIO_u8setPinDirection(LCD_RS_PORT , LCD_RS_PIN,OUTPUT);
	DIO_u8setPinDirection(LCD_RW_PORT , LCD_RW_PIN,OUTPUT);
	DIO_u8setPinDirection(LCD_EN_PORT , LCD_EN_PIN,OUTPUT);

	_delay_ms(40);
	LCD_vidsendCommand(LCD_FUNCTION_SET_CMD);
	_delay_ms(1);
	LCD_vidsendCommand(LCD_DISPLAY_ON_CMD);
	_delay_ms(1);
	LCD_vidsendCommand(LCD_DISPLAY_CLEAR_CMD);
	_delay_ms(2);
	LCD_vidsendCommand(LCD_ENTRY_MODE_SET_CMD);
}
void LCD_vidsendCommand(u8 Copy_u8command){

	DIO_u8setPinValue(LCD_RS_PORT , LCD_RS_PIN , LOW);
	DIO_u8setPinValue(LCD_RW_PORT , LCD_RW_PIN , LOW);
	DIO_u8setPortValue(LCD_DATA_PORT , Copy_u8command);
	DIO_u8setPinValue(LCD_EN_PORT , LCD_EN_PIN ,HIGH);
	_delay_ms(2);
	DIO_u8setPinValue(LCD_EN_PORT , LCD_EN_PIN ,LOW);
	_delay_ms(2);

}
void LCD_vidwriteCharacter(u8 Copy_u8character){

	DIO_u8setPinValue(LCD_RS_PORT , LCD_RS_PIN , HIGH);
	DIO_u8setPinValue(LCD_RW_PORT , LCD_RW_PIN , LOW);
	DIO_u8setPortValue(LCD_DATA_PORT , Copy_u8character);
	DIO_u8setPinValue(LCD_EN_PORT , LCD_EN_PIN ,HIGH);
	_delay_ms(2);
	DIO_u8setPinValue(LCD_EN_PORT , LCD_EN_PIN ,LOW);
	_delay_ms(2);

}
void LCD_vidSendString(u8 *Copy_u8string){
	u8 i =0;
	while (Copy_u8string[i]!= '\0')
	{
		LCD_vidwriteCharacter(Copy_u8string[i]);
		i++;
	}
}
void LCD_vidSendInt(u32 Copy_u32number){
	u32 temp = Copy_u32number;//
	u8 digit[7];
	u8 length = 0 ;
	s8 i ; // not u8 because if we used u8 we will run in infinity loop
	while(temp != 0)
	{
		digit[length] =temp %10;
		temp/=10;
		length++;

	}
	for(i = length-1;i>=0;i--)
	{
		LCD_vidwriteCharacter(digit[i]+'0');

	}
}
void LCD_vidClrLcd(void){
	LCD_vidsendCommand(LCD_DISPLAY_CLEAR_CMD);
}

void LCD_GoToRowCol(u8 row, u8 col)
{
	u8 address;
	switch (row)
	{
		case 0:
			address = col;
			break;
		case 1:
			address = col + 0x40;
			break;
	}
	LCD_vidsendCommand(address | LCD_SET_CURSOR_LOCATION);
}
void LCD_SendStringRowCol(u8 row, u8 col, u8 *str){

	LCD_GoToRowCol(row,col);
	LCD_vidSendString(str);
}
