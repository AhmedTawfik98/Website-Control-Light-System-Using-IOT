/*
 * MEXTI_Private.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Mostafa Ashraf
 */

#ifndef INC_MCAL_MEXTI_PRIVATE_H_
#define INC_MCAL_MEXTI_PRIVATE_H_

/*******************************************************************************************************/
/*                                     Base Address Of EXTI Registers                                  */
/*******************************************************************************************************/

#define MEXTI_BASE_ADDRES 0x40013C00

#define    MSYSCFG_EXTICR1                  (*(volatile u32*)(0x40013808))


#define   EXTI_CONFG_MASK1                0xFFFFFFF0UL
#define   EXTI_CONFG_MASK2                0xFFFFFF0FUL
#define   EXTI_CONFG_MASK3                0xFFFFF0FFUL
#define   EXTI_CONFG_MASK4                0xFFFF0FFFUL


/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*-----------------------------------------------------------------------------------------------------*/

typedef struct
{
	/*  	Must be arranged like register map		*/

	volatile  u32   IMR		;				// From Here Choice The Line
	volatile  u32   EMR		;				// FOR Event Mask
	volatile  u32   RTSR	;				// For Enable or Disable Raising Trigger For Line
	volatile  u32   FTSR	;				// For Enable or Disable Falling Trigger For Line
	volatile  u32   SWIER   ;				// For The SoftWare Interrput Event
	volatile  u32   PR		;				// For The Pending
}EXTI_t;								    // The New Data Type Of That Struct


/*#####################################################################################################*/
/* Pointer Point To EXTI_t ( The Struct ) Casting Pointer To Struct Point To The Frist base  Address   */
/* Without Dereferance (It is A Pointer )                                                              */
/*#####################################################################################################*/

#define MEXTI					 (( volatile  EXTI_t * ) MEXTI_BASE_ADDRES )




#endif /* MCAL_MEXTI_PRIVATE_H_ */
