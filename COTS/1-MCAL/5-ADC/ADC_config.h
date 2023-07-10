/*************************************************************/
/*************************************************************/
/******************    Author: Sherif Taher ******************/
/******************    Layer:  MCAL         ******************/
/******************    SWC:    ADC          ******************/
/******************    Version:1.00         ******************/
/******************    Date:   1/5/2023     ******************/
/*************************************************************/
/*************************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/*description: MUX4:0 select if connect single ended input or diffrential input from this options.*/
/*optios:1-single ended---->1-ADC0
 *                          2-ADC1
 *                          3-ADC2
 *                          4-ADC3
 *                          5-ADC4
 *                          6-ADC5
 *                          7-ADC6
 *                          8-ADC7
 *        2-diffrential input------------->positive diffrential input                 negative diffrential input          gain
 *                          1-D0                     ADC0                                        ADC0                      10
 *                          2-D1  					 ADC1										 ADC0				       10
 *                          3-D2  					 ADC0										 ADC0				       200
 *                          4-D3  					 ADC1										 ADC0				       200
 *                          5-D4  					 ADC2										 ADC2				       10
 *                          6-D5  					 ADC3										 ADC2				       10
 *                          7-D6  					 ADC2										 ADC2				       200
 *                          8-D7  					 ADC3										 ADC2				       200*/
/******************************************************************************************************************************/
/*select refrence voltage
 *                         				options:1-AREFF
 *                         		   				2-AVCC
 *                         		   				3-INTERNAL
 */
#define ADC_Refrence_Seletion		AVCC
/******************************************************************************************************************************/
/*select resolution:
 * 								options:1-Eight_Bits
 * 										2-Ten_Bits
 */
#define ADC_Resolution				Eight_Bits
/******************************************************************************************************************************/
/*Adjust Prescaler:
 * 								Options:1-Division_Factor_2
 * 										2-Division_Factor_4
 * 										3-Division_Factor_8
 * 										4-Division_Factor_16
 * 										5-Division_Factor_32
 * 										6-Division_Factor_64
 * 										7-Division_Factor_128
 */
#define ADC_Prescaler				Division_Factor_128
/******************************************************************************************************************************/
/*Adjust ADC conversion mode:
 * 								Options:1-Single_conversion
 * 										2-Auto_Trigger
 */
#define ADC_Conversion				Single_conversion
/******************************************************************************************************************************/
/*Adjust Auto trigger source:
 * 								Options:1-Free_Running
 * 										2-Analog_Comparator
 * 										3-External_Interrupt_Requst_0
 * 										4-Timer0_Compare_Match
 * 										5-Timer0_Overflow
 * 										6-Timer_Compaer_Match_B
 * 										7-Timer1_Overflow
 * 										8-Timer1_Capture_Event
 */
#define ADC_Auto_Trigger_source			Free_Running
/******************************************************************************************************************************/

#endif
