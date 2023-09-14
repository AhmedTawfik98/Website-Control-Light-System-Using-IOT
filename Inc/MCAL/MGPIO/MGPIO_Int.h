/*
 * MGPIO_Int.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Mostafa Ashraf
 */

#ifndef INC_MCAL_MGPIO_MGPIO_INT_H_
#define INC_MCAL_MGPIO_MGPIO_INT_H_

#define GPIO_MODE_INPUT  0b00 /************** ??? ************/
#define GPIO_MODE_OUTPUT 0b01
#define GPIO_MODE_ALTFUN 0b10
#define GPIO_MODE_ANALOG 0b11

#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2

#define GPIO_PUSHPULL  0
#define GPIO_OPENDRAIN 1

#define GPIO_LOW_SPEED 00
#define GPIO_MEDIUM_SPEED 01
#define GPIO_HIGH_SPEED 10
#define GPIO_VERY_HIGH_SPEED 11

#define GPIO_NO_PULL 00
#define GPIO_PULL_UP 01
#define GPIO_PULL_DOWN 10

#define GPIO_LOW  0
#define GPIO_HIGH 1

typedef enum
{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
	INVALID_PIN,
}Pin_t;


typedef enum
{
	AF0=0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15,
}AltFunc_t;

void MGPIO_vSetPinMode(u8 A_u8PortId, u8 A_PinNo, u8 A_u8Mode);
void MGPIO_vSetPinOutputType(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8OutPutType);
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8OutputSpeed);
void MGPIO_vSetPinInputPull(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8PullType);

u8 MGPIO_u8GetPinValue(u8 A_u8PortId, u8 A_u8PinNo);

void MGPIO_vSetPinVal(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8PinVal);
void MGPIO_vSetPinVal_fast(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8PinVal); /*BSRR*/

void MGPIO_vSetAlternativeFunction(u8 A_u8PortId, u8 A_u8PinNo, u8 A_u8AltFun);


#endif /* MCAL_MGPIO_MGPIO_INT_H_ */
