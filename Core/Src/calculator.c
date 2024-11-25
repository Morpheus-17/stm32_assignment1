/*
 * calculator.c
 *
 *  Created on: Nov 23, 2024
 *      Author: blueb
 */

#include "calculator.h"
#include "sll_stack.h"

// 중위 표기법을 후위 표기법으로 변환하는 함수
void infixToPostfix(char *infix, char *postfix) {
	Stack opStack;
	initStack(&opStack);
	int k = 0;  // postfix 배열의 인덱스

	for (int i = 0; infix[i] != '\0'; i++) {
		// 공백 무시
		if (infix[i] == ' ') {
			continue;
		}

		// 숫자일 경우
		if (isdigit(infix[i])) {
			postfix[k++] = infix[i];
		}
		// 여는 괄호 처리
		else if (infix[i] == '(') {
			push(&opStack, infix[i]);
		}
		// 닫는 괄호 처리
		else if (infix[i] == ')') {
			while (!isEmpty(&opStack) && peek(&opStack) != '(') {
				postfix[k++] = pop(&opStack);
			}
			pop(&opStack);  // 여는 괄호 '('를 팝
		}
		// 연산자 처리
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*'
				|| infix[i] == '/') {
			while (!isEmpty(&opStack)
					&& precedence(peek(&opStack)) >= precedence(infix[i])) {
				postfix[k++] = pop(&opStack);
			}
			push(&opStack, infix[i]);
		}
	}

	// 남아있는 연산자 모두 팝하여 postfix에 추가
	while (!isEmpty(&opStack)) {
		postfix[k++] = pop(&opStack);
	}
	postfix[k] = '\0';  // 문자열 종료
}

// 후위 표기법을 계산하는 함수
int evaluatePostfix(char *postfix) {
	Stack valueStack;
	initStack(&valueStack);

	for (int i = 0; postfix[i] != '\0'; i++) {
		// 공백 무시
		if (postfix[i] == ' ') {
			continue;
		}

		// 숫자일 경우
		if (isdigit(postfix[i])) {
			push(&valueStack, postfix[i] - '0');
		}
		// 연산자일 경우
		else {
			int val2 = pop(&valueStack);
			int val1 = pop(&valueStack);
			int result = applyOperator(val1, val2, postfix[i]);
			push(&valueStack, result);
		}
	}

	// 스택에 남은 값이 결과값
	return pop(&valueStack);
}

int evaluate(char *in, char *pos) {
	int ret;

	infixToPostfix(in, pos);
	ret = evaluatePostfix(pos);

	return ret;
}

