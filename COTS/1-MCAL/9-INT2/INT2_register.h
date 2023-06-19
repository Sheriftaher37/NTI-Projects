/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    INT2         ******************/
/******************    Version:1.00         ******************/
/*************************************************************/
/*************************************************************/

#ifndef INT2_REGISTER_H_
#define INT2_REGISTER_H_

#define GICR            *((volatile u8*)0x5B)

#define GICR_INT2       5


#define GIFR            *((volatile u8*)0x5A)

#define MCUCSR          *((volatile u8*)0x54)
#define MCUCSR_INT2     6

#endif