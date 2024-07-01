// 인공지능공학부, 2310165, 최예인, program_code1-a.c(1번문제 소문항 A번), 2024년 5월 8일
#define _CRT_SECURE_NO_WARNINGS

#include "arrayStack.h"
#include "arrayStackCalc.h"
#define MAX_EXPRESSION_LENGTH 101
#define MAX 100  // MAX 정의 추가

int main() {
    // 0. 스택 선언
    ArrayStack operand;  // 피연산자
    ArrayStack operator; // 연산자

    init(&operand);
    init(&operator);

    // 1. 수식 설정
    char input[] = "[ 3 * ( 20 + 10 ) ] - { 20 / 5 + [ 4 * 2 ] / 2 } + 8"; // 입력 받을 문자열을 저장할 배열
    char* exp[MAX]; // 공백을 기준으로 나눈 토큰들을 저장할 배열
    char* postfix[MAX]; // 후위표기식을 저장할 배열
    int count = 0;

    // 공백을 기준으로 문자열을 나누어 토큰 배열에 저장
    char* token = strtok(input, " ");
    while (token != NULL) {
        exp[count++] = token;
        token = strtok(NULL, " "); // 다음 토큰으로 이동
    }
    exp[count] = NULL;  // 배열의 끝을 표시하기 위해 NULL 추가

    // 2. 후위 표현식으로 변환
    infix_to_postfix(exp, count, postfix);

    // 후위표현식 출력
    printf("Postfix Expression: ");
    for (int i = 0; postfix[i] != NULL; i++) {
        printf("%s ", postfix[i]);
    }
    printf("\n");
    

    // 후위표현식을 평가하여 결과 출력
    int len = sizeof(postfix) / sizeof(postfix[0]);

    ArrayStack s;
    init(&s);

    
    int result = post_evaluation(postfix, &s, len);
    printf("%d", len);
    printf("Result: %d\n", peek(&s));


    return 0;
}
