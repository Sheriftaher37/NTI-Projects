/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  HAL          ******************/
/******************    SWC:    SWITCH       ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

/* SWITCH STATE */
#define SW_PRESSED        1
#define SW_NOT_PRESSED    0

/* SWITCH TYPE */
#define SW_MAINTAINED     0    /* SELF LOCKING SWITCH */
#define SW_TEMPORARY      1    /* BOUNCING SWITCH */

/* SWITCH PULL TYPE */
#define SW_PULL_UP        0
#define SW_PULL_DOWN      1

u8 SW_u8GetState(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8SwitchType,u8 Copy_u8PullType);

#endif
