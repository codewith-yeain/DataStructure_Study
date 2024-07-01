// 인공지능공학부, 2310165, 최예인, arrayStackCalc.h, 2024년 5월 14일
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "arrayStack.h"

#define MAX_EXPRESSION_LENGTH 101

//스택 내부 우선순위 함수
int pis(char* op) {
    if (strcmp(op, "(") == 0 || strcmp(op, "[") == 0 || strcmp(op, "{") == 0) return 0;
	if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
	if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
	if (strcmp(op, "^") == 0) return 3;
	return -1;
}

//스택 외부 우선순위 함수
int pie(char* op) {
	if (strcmp(op, "(") == 0 || strcmp(op, "[") == 0 || strcmp(op, "{") == 0) return 4;
	if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
	if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
	if (strcmp(op, "^") == 0) return 3;
	return -1;
}


// 중위표현식을 후위표현식으로 바꾸는 함수
void infix_to_postfix(char* exp[], int len, char* postfix[]) {
    ArrayStack operators;
    init(&operators);
    int postfixIndex = 0;

    for (int i = 0; i < len; i++) {
        char* temp = exp[i];

        if (isdigit(temp[0])) {
            postfix[postfixIndex++] = temp;
        }
        else {
            switch (temp[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                while (!isEmpty(&operators) && pis(peek(&operators)) >= pie(temp)) {
                    postfix[postfixIndex++] = pop(&operators);
                }
                push(&operators, temp);
                break;
            case '(':
            case '[':
            case '{':
                push(&operators, temp);
                break;
            case ')':
            case ']':
            case '}':
                while (!isEmpty(&operators) && strcmp(peek(&operators), "(") != 0 
                    && strcmp(peek(&operators), "[") != 0 && strcmp(peek(&operators), "{") != 0) {
                    postfix[postfixIndex++] = pop(&operators);
                }
                pop(&operators);
                break;
            default:
                break;
            }
        }
    }

    while (!isEmpty(&operators)) {
        postfix[postfixIndex++] = pop(&operators);
    }
  
    postfix[postfixIndex] = NULL; // 배열의 끝을 표시하기 위해 NULL 추가
}


// 후위표현식 계산 함수
int post_evaluation(char* postfix[], ArrayStack* s, int len) {

    for (int i = 0; i < len; i++) {
        char* ch = postfix[i];
        if (ch != NULL) { // NULL 체크
            if (isdigit(ch[0])) { // 피연산자일 때
                push(&s, ch); // 문자열 그대로 저장
            }
            else { // 연산자일 때
                int op2 = atoi(pop(&s)); // 두 번째 피연산자
                int op1 = atoi(pop(&s)); // 첫 번째 피연산자
                int calc_result = 0;

                switch (ch[0]) {
                case '+':
                    calc_result = op1 + op2;
                    break;
                case '-':
                    calc_result = op1 - op2;
                    break;
                case '*':
                    calc_result = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Error: division by zero\n");
                        exit(1);
                    }
                    calc_result = op1 / op2;
                    break;
                default:
                    printf("Error: unknown operator %s\n", ch);
                    exit(1);
                }
                // 계산 결과를 다시 스택에 푸시
                char buffer[20];
                sprintf(buffer, "%d", calc_result);
                push(&s, buffer);
                printf("%s", peek(&s));
            }
        }
    }

    show(&s);
    int result = atoi(peek(&s)); // 최종 결과를 정수로 변환
    return result;
}

