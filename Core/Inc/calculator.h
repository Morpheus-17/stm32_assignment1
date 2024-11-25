/*
 * calculator.h
 *
 *  Created on: Nov 23, 2024
 *      Author: blueb
 */

#ifndef INC_CALCULATOR_H_
#define INC_CALCULATOR_H_

#include "main.h"
#include "sll_stack.h"

void infixToPostfix(char* infix, char* postfix);
int evaluatePostfix(char* postfix);
int evaluate(char* in, char* pos);

#endif /* INC_CALCULATOR_H_ */
