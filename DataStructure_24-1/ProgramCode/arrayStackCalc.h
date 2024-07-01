// �ΰ����ɰ��к�, 2310165, �ֿ���, arrayStackCalc.h, 2024�� 5�� 14��
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "arrayStack.h"

#define MAX_EXPRESSION_LENGTH 101

//���� ���� �켱���� �Լ�
int pis(char* op) {
    if (strcmp(op, "(") == 0 || strcmp(op, "[") == 0 || strcmp(op, "{") == 0) return 0;
	if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
	if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
	if (strcmp(op, "^") == 0) return 3;
	return -1;
}

//���� �ܺ� �켱���� �Լ�
int pie(char* op) {
	if (strcmp(op, "(") == 0 || strcmp(op, "[") == 0 || strcmp(op, "{") == 0) return 4;
	if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
	if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
	if (strcmp(op, "^") == 0) return 3;
	return -1;
}


// ����ǥ������ ����ǥ�������� �ٲٴ� �Լ�
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
  
    postfix[postfixIndex] = NULL; // �迭�� ���� ǥ���ϱ� ���� NULL �߰�
}


// ����ǥ���� ��� �Լ�
int post_evaluation(char* postfix[], ArrayStack* s, int len) {

    for (int i = 0; i < len; i++) {
        char* ch = postfix[i];
        if (ch != NULL) { // NULL üũ
            if (isdigit(ch[0])) { // �ǿ������� ��
                push(&s, ch); // ���ڿ� �״�� ����
            }
            else { // �������� ��
                int op2 = atoi(pop(&s)); // �� ��° �ǿ�����
                int op1 = atoi(pop(&s)); // ù ��° �ǿ�����
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
                // ��� ����� �ٽ� ���ÿ� Ǫ��
                char buffer[20];
                sprintf(buffer, "%d", calc_result);
                push(&s, buffer);
                printf("%s", peek(&s));
            }
        }
    }

    show(&s);
    int result = atoi(peek(&s)); // ���� ����� ������ ��ȯ
    return result;
}

