/*
 * sll_stack.h
 *
 *  Created on: Nov 23, 2024
 *      Author: blueb
 */

#ifndef INC_SLL_STACK_H_
#define INC_SLL_STACK_H_

#include "main.h"

// 노드 구조체 정의 (싱글 링크드 리스트)
typedef struct Node {
    int data;           // 노드에 저장할 데이터
    struct Node* next;  // 다음 노드를 가리키는 포인터
} Node;

// 스택 구조체 정의
typedef struct {
    Node* top;   // 스택의 최상위 요소를 가리키는 포인터
} Stack;

// 스택 초기화 함수
void initStack(Stack* s);
// 스택이 비었는지 확인
int isEmpty(Stack* s);
// 스택에 원소를 추가 (push)하는 함수
void push(Stack* s, int value);
// 스택에서 원소를 제거 (pop)하는 함수
int pop(Stack* s);
// 스택의 top 값을 확인하는 함수 (peek)
int peek(Stack* s);
// 연산자 우선순위 확인 함수
int precedence(char op);
// 연산 수행 함수
int applyOperator(int a, int b, char op);

#endif /* INC_SLL_STACK_H_ */
