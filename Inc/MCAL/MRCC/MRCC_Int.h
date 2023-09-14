/*
 * MRCC_Int.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa Ashraf
 */

#ifndef INC_MCAL_MRCC_INT_H_
#define INC_MCAL_MRCC_INT_H_


void MRCC_vInit(void) ;

void MRCC_vEnable_AHB1Clock(u8 per_name);
void MRCC_vEnable_AHB2Clock(u8 per_name);

void MRCC_vEnable_APB1Clock(u8 per_name);
void MRCC_vEnable_APB2Clock(u8 per_name);

void MRCC_Disable_AHB1Clock(u8 per_name);
void MRCC_Disable_AHB2Clock(u8 per_name);
void MRCC_Disable_APB1Clock(u8 per_name);
void MRCC_Disable_APB2Clock(u8 per_name);



#endif /* MCAL_MRCC_INT_H_ */
