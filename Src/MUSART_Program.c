/*
 * MUSART_Program.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Mostafa.Ashraf
 */


/***********************************************************************/
/*                           Standard Types LIB                        */
/***********************************************************************/

#include"../Inc/LIB/BIT_Maths.h"
#include"../Inc/LIB/STD_TYPES.h"
/***********************************************************************/
/*                           Lower Layer Interfaces                    */
/***********************************************************************/


/***********************************************************************/
/*                            own Header Files                         */
/***********************************************************************/



#include"../Inc/MCAL/MUART/MUSART_Private.h"
#include"../Inc/MCAL/MUART/MUSART_Config.h"
#include"../Inc/MCAL/MUART/MUSART_Interface.h"


static void(*MUSART_CALLPTR)(void)   = 0 ;


void MUSART_voidInit(void)
{

	/*Set Boaud Rate*/
	MUSART1->BRR = 0x683 ;   //baudRate 9600 bps   //baudRate 115200 bps, BRR = SystemClockFrequency(HSI = 16 MHZ) / (16 * baudRate) ->
	/*OverSampling 16 Sample*/
	MUSART1->CR1.OVER8 = 0 ;   //BitField
	/*8 Bit Word size*/
	MUSART1->CR1.M = 0 ;
	/*Disable Parity*/
	MUSART1->CR1.PCE = 	0 ;
	/*one Stop Bit*/
	CLR_BIT(MUSART1->CR2,12);
	CLR_BIT(MUSART1->CR2,13);
	/*Enable Trasmitter */
	MUSART1->CR1.TE = 1 ;
	/*Enable Receiver*/
	MUSART1->CR1.RE = 1 ;
	/*Receive interrupt  Enable*/
	MUSART1->CR1.RXNEIE = 0 ;
}

void MUSART_voidSendData(u8* copy_u8Data,u8 Copy_u8Len)
{
   for(u8 Copy_u8Iterator = 0 ; Copy_u8Iterator < Copy_u8Len ; Copy_u8Iterator++ )
   {
	   /*Send Byte*/
	   MUSART1->DR = copy_u8Data[Copy_u8Iterator] ;
	   /*wait until data transfer is complete from Transmitter buffer register to shift Transmitter Register*/
	   while(GET_BIT(MUSART1->SR,7) == 0) ;
   }

}


void MUSART_voidSendString(u8* copy_u8Data)
{
	u8 iterator=0;
	while(copy_u8Data[iterator] != '\0')
	{
		   MUSART1->DR = copy_u8Data[iterator] ;
		   while(GET_BIT(MUSART1->SR,6) == 0) ;
		   iterator++;
	}
}

u8 MUSART_u8ReadData(void)
{
	u16 local_u16Timeout = 0;
	u8  local_u8ReceivedData = 0;
	/*wait until data ready*/
	 while(GET_BIT(MUSART1->SR,5)==0)
	 {
		 local_u16Timeout++;
		 if(local_u16Timeout==10000)
		 {
			 local_u8ReceivedData = 255 ;
			 break;
		 }

	 }
	 local_u8ReceivedData=(u8) MUSART1->DR;
	 return local_u8ReceivedData  ;
}


u8 MUSART_u8ReadDataAsynch(void)
{
	 return (u8) MUSART1->DR;  ;
}
void MUSART_voidEnable(void)
{
  /*UART Enable*/
  MUSART1->CR1.UE =  1 ;
}

void MUSART_voidDisable(void)
{
	 /*UART Disable*/
	  MUSART1->CR1.UE =  1 ;
}



void MUSART_voidCallBack(void(*Fptr)(void))
{

	MUSART_CALLPTR = Fptr ;
}




void USART1_IRQHandler(void)
{
	MUSART_CALLPTR() ;

	MUSART1 -> SR = 0;

}




void MUART_voidTransmit(u8 *Ptr_u8Data)
{
	u8 Local_u8Counter = 0;
	while(Ptr_u8Data[Local_u8Counter] != '\0')
	{
		MUSART1 -> DR = Ptr_u8Data[Local_u8Counter];
		while(GET_BIT(MUSART1 -> SR, 7) == 0);
		Local_u8Counter++;

	}
}

/*
u8 MUART_u8Receive (void)
{
	while(GET_BIT(UART -> SR, 5) == 0);
	return (UART -> DR);
}
*/

u8 MUART_u8Receive (u32 copy_u32MaxTimeToWait)
{
	u32 timeout=0;
	u8 data=0;

	while(GET_BIT(MUSART1 -> SR, 5) == 0)
	{
		timeout++;
		if(timeout == copy_u32MaxTimeToWait)
		{
			data = 128;
			break;
		}
	}
	if(data == 0)
	{
		data = MUSART1 -> DR;
	}
	CLR_BIT(MUSART1 -> SR, 5);
    return data;
}


 u8 HWIFI_u8CommandValidate (u32 Copy_u32TimeOut)
{
	u8 Local_u8Counter=0;
	u8 Local_u8ReceivedChar=0;

	u8 Local_u8Response[100]={0};

	while(Local_u8ReceivedChar < 128)
	{
		Local_u8ReceivedChar = MUART_u8Receive(Copy_u32TimeOut);
		Local_u8Response[Local_u8Counter++] = Local_u8ReceivedChar;
	}

	for(Local_u8Counter=0; Local_u8Counter<100; Local_u8Counter++)
	{
		if(Local_u8Response[Local_u8Counter] == 'O' && Local_u8Response[Local_u8Counter+1] == 'K')
		{
			return 1;
		}
		else if(Local_u8Response[Local_u8Counter] == 'N' && Local_u8Response[Local_u8Counter+1] == 'D' && Local_u8Response[Local_u8Counter+3] == 'O' && Local_u8Response[Local_u8Counter+4] == 'K')
		{
			/* +IPD,1:0CLOSED */
			return Local_u8Response[Local_u8Counter+16];
		}
		else
		{
			return 0;
		}
	}
}
