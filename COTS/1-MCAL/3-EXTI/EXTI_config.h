/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    EXTI         ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*options:
 * 1-LOW_LEVEL
 * 2-ON_CHANGE
 * 3-FALLING_EDGE
 * 4-RISING_EDGE */

#define INT0_SENSE   		LOW_LEVEL

/*options:
 * 1-LOW_LEVEL
 * 2-ON_CHANGE
 * 3-FALLING_EDGE
 * 4-RISING_EDGE */

#define INT1_SENSE   		LOW_LEVEL

/*options:
 * 1-FALLING_EDGE
 * 2-RISING_EDGE */

#define INT2_SENSE   		FALLING_EDGE

/*options:
 * 1-ENABLED
 * 2-DISABLED */

#define INT0_INITIAL_STATE    DISABLED

/*options:
 * 1-ENABLED
 * 2-DISABLED */

#define INT1_INITIAL_STATE    DISABLED

/*options:
 * 1-ENABLED
 * 2-DISABLED */

#define INT2_INITIAL_STATE    DISABLED

#endif
