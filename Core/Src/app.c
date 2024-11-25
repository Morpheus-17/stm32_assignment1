/*
 * app.c
 *
 *  Created on: Nov 19, 2024
 *      Author: blueb
 */
#include "app.h"
#include "uart.h"
#include "calculator.h"
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart2;
#define rxBufferMax 255
extern int rxBufferWrite;							// write receivebuffer pointer
extern int rxBufferRead;								// read receivebuffer pointer
extern uint8_t rxBuffer[rxBufferMax];	// receivebuffer

int validExpression(char* expr){
	while(*expr!='\0'){
		if(!((*expr>='0' && *expr<='9')||
				(*expr=='*' || *expr=='/' || *expr=='+' || *expr=='-') ||
				(*expr=='(' && *expr<=')'))) return 0;
		expr++;
	}
	return 1;
}

void app(){
	int ret=0;
	// uart 장치 초기화
	initUart(&huart2);

	printf("Calculator\n");
	char ch=0;
	char infix[rxBufferMax];
	char postfix[rxBufferMax];
	char idx=0;
	int val;
	while(1)
	{
		ch=getUart();
		if((ch>='0' && ch<='9') || ((ch=='*') || (ch=='-')|| (ch=='+')|| (ch=='/'))) infix[idx++]=ch;
		idx%=rxBufferMax;

		if(ch == '\n') {
			ret=validExpression(infix);
			if(ret){

				char cval[100];
				infix[idx] = 0;

				val = evaluate(infix, postfix);
				itoa(val, cval, 10);
				printf("=%s\n",cval);
			}
			memset(infix,0,rxBufferMax);
			memset(postfix,0,rxBufferMax);
			idx=0;
		}

		if(ch!=0)
			if(ch!='\n')
				HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 10);
		ch=0;
	}

}

