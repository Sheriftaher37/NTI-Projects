/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  HAL          ******************/
/******************    SWC:    LED          ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_COM_AN     0
#define LED_COM_CA     1

u8 LED_u8TurnOn(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectionType);
u8 LED_u8TurnOff(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectionType);

#endif
