/*
 * MUSART_Program.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Mostafa.Ashraf
 */

#ifndef INC_MCAL_MUSART_INTERFACE_H_
#define INC_MCAL_MUSART_INTERFACE_H_

void MUSART_voidInit(void) ;

void MUSART_voidSendData(u8* copy_u8Data,u8 Copy_u8Len);

void MUSART_voidSendString(u8* copy_u8Data);

u8 MUSART_u8ReadData(void) ;

void MUSART_voidEnable(void) ;

void MUSART_voidDisable(void) ;

void MUSART_voidCallBack(void(*Fptr)(void)) ;





void MUART_voidInitialize (void);
void MUART_voidTransmit(u8 *Ptr_u8Data);
u8 MUART_u8Receive (u32 copy_u32MaxTimeToWait);
u8 HWIFI_u8CommandValidate (u32 Copy_u32TimeOut);
#endif /* MUSART_INTERFACE_H_ */
