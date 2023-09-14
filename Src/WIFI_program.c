#include"../Inc/LIB/BIT_Maths.h"
#include"../Inc/LIB/STD_TYPES.h"

#include"../Inc/MCAL/MUART/MUSART_Private.h"
#include"../Inc/MCAL/MUART/MUSART_Config.h"
#include"../Inc/MCAL/MUART/MUSART_Interface.h"

#include "../Inc/HAL/HESP/WIFI_interface.h"
#include "../Inc/HAL/HESP/WIFI_private.h"
#include "../Inc/HAL/HESP/WIFI_config.h"

void HWIFI_voidInit(void)
{
	u8 Local_u8Output=0;
	
	while(Local_u8Output == 0)
	{
		MUART_voidTransmit("AT\r\n");
		Local_u8Output = HWIFI_u8CommandValidate(100000);
	}
	
	Local_u8Output=0;
	while(Local_u8Output == 0)
	{
		MUART_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Output = HWIFI_u8CommandValidate(100000);
	}
}

void HWIFI_voidConnectToNetwork (void)
{
	u8 Local_u8Output=0;
	
	while(Local_u8Output == 0)
	{
		MUART_voidTransmit("AT+CWJAP_CUR=\"WELCOME\",\"2023@2023\"\r\n");
		Local_u8Output = HWIFI_u8CommandValidate(100000);
	}
	
}

void HWIFI_voidConnectToServer (void)
{
	u8 Local_u8Output=0;
	
	while(Local_u8Output == 0)
	{
		MUART_voidTransmit("AT+CIPSTART=\"TCP\",\"23.179.32.36\",80\r\n");
		Local_u8Output = HWIFI_u8CommandValidate(100000);
	}
	
	
}

u8 HWIFI_u8GetData (void)
{
	u8 data;
	
	HWIFI_voidConnectToServer();
	
	MUART_voidTransmit("AT+CIPSEND=41\r\n");
	data = HWIFI_u8CommandValidate(50000);
	
	MUART_voidTransmit("GET http://itialex44.freeoda.com/status.txt");
	data = HWIFI_u8CommandValidate(100000);
	
	return data;
	
}

