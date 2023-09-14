/*
 * MRCC_Prog.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa Ashraf
 */

#include"../Inc/LIB/BIT_Maths.h"
#include"../Inc/LIB/STD_TYPES.h"
#include "../Inc/MCAL/MRCC/MRCC_Int.h"
#include "../Inc/MCAL/MRCC/MRCC_Private.h"
#include "../Inc/MCAL/MRCC/MRCC_Config.h"

void MRCC_vInit(void)
{
	/*1- CSS (ON/OFF) */

	/*2- HSE_BYP CLR->Oscillator Enable not bypassed, SET->Oscillator Disable bypassed */
	CLR_BIT(RCC -> CR, HSEBYP);

	/*3- select clock switch (HSI/HSE/PLL) */
	SET_BIT(RCC -> CFGR, SW0);

	/*4- Bus prescalers   */

	/*5- PLL configuration */

	/*6- Enable the selected clock (HSI ON / HSE ON / PLL ON)*/
#if RCC_HSE_ENABLE == ENABLE
	SET_BIT(RCC->CR, HSEON);
#endif

}

void MRCC_vEnable_AHB1Clock(u8 per_name)
{
	/*enable rcc AHB1*/
	SET_BIT(RCC ->AHB1ENR ,per_name );
}

void MRCC_vEnable_AHB2Clock(u8 per_name){
	/*enable rcc AHB2*/
	SET_BIT(RCC ->AHB2ENR , per_name);
}


void MRCC_vEnable_APB1Clock(u8 per_name){
	/*enable rcc APB1*/
	SET_BIT(RCC ->APB1ENR ,per_name );
}


void MRCC_vEnable_APB2Clock(u8 per_name){
	/*enable rcc APB2*/
	SET_BIT(RCC ->APB2ENR , per_name);
	}




void MRCC_Disable_AHB1Clock(u8 per_name)
{

	/*disable rcc AHB1*/
	CLR_BIT(RCC ->AHB1ENR ,per_name );
}

void MRCC_Disable_AHB2Clock(u8 per_name)
{

	/*disable rcc AHB1*/
	CLR_BIT(RCC ->AHB1ENR ,per_name );
}
void MRCC_Disable_APB1Clock(u8 per_name)
{

	/*disable rcc AHB1*/
	CLR_BIT(RCC ->AHB1ENR ,per_name );
}
void MRCC_Disable_APB2Clock(u8 per_name)
{

	/*disable rcc AHB1*/
	CLR_BIT(RCC ->AHB1ENR ,per_name );
}
