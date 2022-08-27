/*
 * KEYPAD_prg.c
 *
 *  Created on: Sep 20, 2021
 *      Author: Farid
 */
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO_VI/DIO_int.h"
#include "KEYPAD_cfg.h"

#define  KEYPAD_NOT_PRESSED      0


void KEYPAD_vidInit(void)
{
	DIO_u8setPortDirection(KEYPAD_PORT , 0x0f);
	DIO_u8setPortValue(KEYPAD_PORT ,FULL_HIGH);
}
u8 KEYPAD_u8GetPressed(void)
{
	u8 Local_u8KeyPressed  = KEYPAD_NOT_PRESSED ;
	u8 Local_u8RowStatus ;

	u8 Local_u8Column ;
	u8 Local_u8Row ;

	for(Local_u8Column = KEYPAD_COLUMN_START ;Local_u8Column <= KEYPAD_COLUMN_END ; Local_u8Column++ )
	{
		//activate current column
		DIO_u8setPinValue(KEYPAD_PORT , Local_u8Column , LOW);

		//loop on the rows
		for(Local_u8Row = KEYPAD_ROW_START ; Local_u8Row <= KEYPAD_ROW_END ; Local_u8Row++)
		{
			//check the status of the current row
			DIO_u8getPinValue(KEYPAD_PORT , Local_u8Row , &Local_u8RowStatus);
			if(Local_u8RowStatus == 0)
			{
				//pressed
				//take action
				Local_u8KeyPressed = KEYPAD_au8KeyVal[Local_u8Row-KEYPAD_ROW_START][Local_u8Column -KEYPAD_COLUMN_START];
				//Local_u8KeyPressed = ((Local_u8Row-KEYPAD_ROW_START) + ((Local_u8Column -KEYPAD_COLUMN_START) *4)) +1 ;

				//wait until the key is released
				while(Local_u8RowStatus == 0)
				{
					DIO_u8getPinValue(KEYPAD_PORT , Local_u8Row , &Local_u8RowStatus);
				}

//				_delay_ms(30);
//				DIO_u8GetPinVal(KEYPAD_PORT , Local_u8Row , &Local_u8RowStatus);
//				if(Local_u8RowStatus == 0)
//				{
//					Local_u8KeyPressed = KEYPAD_au8KeyVal[Local_u8Row-KEYPAD_ROW_START][Local_u8Column -KEYPAD_COLUMN_START];
//
//				}
				//delay for debouncing
				_delay_ms(10);
			}

		}
		//deactivate current column
		DIO_u8setPinValue(KEYPAD_PORT , Local_u8Column , HIGH);

	}
	return Local_u8KeyPressed ;
}
