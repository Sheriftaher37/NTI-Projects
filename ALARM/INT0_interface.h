/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    INT0         ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#ifndef INT0_INTERFACE_H_
#define INT0_INTERFACE_H_

#define LOW_LEVEL       		1
#define ON_CHANGE				2
#define FALLING_EDGE			3
#define RISING_EDGE				4

#define EXTI_INT0				1


void EXTI_voidInt0Init(void);

/*Description: A function to set the reuired sense control of INT0 using postbuild configuration
 * Inputs:Copy_u8Sense, Options are:1-LOW_LEVEL
 * 									2-ON_CHANGE
 * 									3-FALLING_EDGE
 * 									4-RISING_EDGE
 * Output:Error status with type u8*/
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);

void EXTI_u8IntEnable(void);

void EXTI_u8IntDisable(void);

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void));

#endif // EXTI_INTERFACE_H_
