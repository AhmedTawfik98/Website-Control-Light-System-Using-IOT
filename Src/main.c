#include"../Inc/LIB/BIT_Maths.h"
#include"../Inc/LIB/STD_TYPES.h"

#include "../Inc/MCAL/MRCC/MRCC_Int.h"
#include "../Inc/MCAL/MSTK/MSTK_Int.h"
#include "../Inc/MCAL/MGPIO/MGPIO_Int.h"
#include "../Inc/MCAL/MUART/MUSART_Interface.h"
#include "../Inc/HAL/HESP/WIFI_interface.h"


int main()
{
	u8 data;
	MRCC_vEnable_AHB1Clock(0);	 //Enable POERTA

	MRCC_vEnable_APB2Clock(4);  //Enable UART1

	MSTK_vInit(); // Initialize the SysTick timer


	MGPIO_vSetPinMode(GPIO_PORTA,PIN9, GPIO_MODE_ALTFUN);
	MGPIO_vSetPinMode(GPIO_PORTA, PIN10, GPIO_MODE_ALTFUN);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,  PIN9,AF7);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,  PIN10, AF7);

	MUSART_voidInit();

	 MGPIO_vSetPinMode(GPIO_PORTA,  PIN1, GPIO_MODE_OUTPUT);
	 MGPIO_vSetPinOutputType(GPIO_PORTA,  PIN1, GPIO_NO_PULL);

	 HWIFI_voidInit();

	 HWIFI_voidConnectToNetwork ();

	 HWIFI_voidConnectToServer ();

	 data= HWIFI_u8GetData ();


	if (data == '1')
	{
		MGPIO_vSetPinVal(GPIO_PORTA, PIN1, GPIO_HIGH);
	}
	else if (data == '0')
	{
		MGPIO_vSetPinVal(GPIO_PORTA,  PIN1, GPIO_LOW);
	}

	while(1)
	{


	}

	return 0;
}
