/*
 * KEYPAD_cfg.h
 *
 *  Created on: Sep 20, 2021
 *      Author: Farid
 */

#ifndef HAL_KEYPAD_HANDLER_KEYPAD_CFG_H_
#define HAL_KEYPAD_HANDLER_KEYPAD_CFG_H_

extern u8 KEYPAD_au8KeyVal[4][4];

#define KEYPAD_PORT            PORT_A

#define KEYPAD_COLUMN_START    PIN_0
#define KEYPAD_COLUMN_END      PIN_3

#define KEYPAD_ROW_START       PIN_4
#define KEYPAD_ROW_END         PIN_7




#endif /* HAL_KEYPAD_HANDLER_KEYPAD_CFG_H_ */
