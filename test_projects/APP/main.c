/*
 * main.c
 *
 *  Created on: Oct 26, 2021
 *      Author: zezos
 */

#include "../LIB/STD_TYPES.h"
#include "../HAL/KEYPAD_V2/KEYPAD_int.h"
#include "../HAL/LCD_handler/LCD_int.h"
#include "../MCAL/ADC_V1/ADC_int.h"
#include "util/delay.h"
void main(void){
	const f32 STEP = 4.88 ;
	u16 Digital_Step ;
	f32 analog_mv ;
	u32 varResis;
	LCD_vidinit();
	ADC_Vidinit();
	LCD_SendStringRowCol(2,1,"SHAHEEN OHMETER");
	LCD_SendStringRowCol(1,0,"RES = ");
	while(1){
		LCD_SendStringRowCol(1,5," ");
		Digital_Step = ADC_u16readPin(ADC0);
		analog_mv = Digital_Step*STEP ;
		varResis= (analog_mv*10000)/(5000-analog_mv);
		if(varResis >= 1000){
			LCD_vidSendInt(varResis/1000);
			LCD_vidSendString(".");
			LCD_vidSendInt(varResis%1000); //Halimo With the moves ..
			LCD_vidSendString("K    ");
		}else{
			LCD_SendStringRowCol(1,5,"       ");
			LCD_SendStringRowCol(1,5," ");
			LCD_vidSendInt(varResis);
		}

		_delay_ms(500);
	}
}
