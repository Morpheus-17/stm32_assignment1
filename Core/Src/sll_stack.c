/*
 * sll_stack.c
 *
 *  Created on: Nov 23, 2024
 *      Author: blueb
 */
#include "sll_stack.h"
#include <stdio.h>
#include <stdlib.h>

// 스택 초기화 함수
void initStack(Stack *s) {
	s->top = NULL;  // 스택은 초기화 시 비어있으므로 top을 NULL로 설정
}

// 스택이 비었는지 확인
int isEmpty(Stack *s) {
	return s->top == NULL;  // top이 NULL이면 스택이 비어있음
}

// 스택에 원소를 추가 (push)하는 함수
void push(Stack *s, int value) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	if (!newNode) {
		printf("Memory allocation failed\n");
		return;
	}
	newNode->data = value;
	newNode->next = s->top;
	s->top = newNode;
}

// 스택에서 원소를 제거 (pop)하는 함수
int pop(Stack *s) {
	if (isEmpty(s)) {
		printf("Stack Underflow\n");
		return -1;
	}
	Node *temp = s->top;
	int poppedValue = temp->data;
	s->top = s->top->next;
	free(temp);
	return poppedValue;
}

// 스택의 top 값을 확인하는 함수 (peek)
int peek(Stack *s) {
	if (isEmpty(s)) {
		printf("Stack is empty\n");
		return -1;
	}
	return s->top->data;
}

// 연산자 우선순위 확인 함수
int precedence(char op) {
	if (op == '+' || op == '-') {
		return 1;
	} else if (op == '*' || op == '/') {
		return 2;
	}
	return 0;
}

// 연산 수행 함수
int applyOperator(int a, int b, char op) {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return 0;
	}
}

