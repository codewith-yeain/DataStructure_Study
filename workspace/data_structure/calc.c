#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // �����Ҵ� ���� �������
#include "cstack.h" // ����ڰ� ������ ��������� ����� ��� ""�� ����Ѵ�.

// �������� �켱������ �˷��ִ� �Լ�
int prec(char op) {
	switch (op) {
	case'+':
	case'-':
		return 0;
	case '*':
	case '/':
		return 1;
	}
	return -1;
}


// ���� ǥ������ ���� ǥ�������� �ٲٴ� �Լ�
char* inToPost(char exp[]) {// exp: ����ڰ� �Է��� ����ǥ����
	// res: ���� ǥ�������� �ٲ� ����� ������ �迭
	char* res = (char*)malloc(sizeof(char) * 100);
	int idx = 0; // res�� �ε��� ��ȣ
	int length = strlen(exp);
	char top; // ������ top�� ����ִ� ��Ҹ� ����� ����
	Stack s; // ��� ����� ����

	init(&s);

	for (int i = 0; i < length; i++) {
		char ch = exp[i]; // ch: ����ǥ���� �� ���� �ϳ�

		if (ch >= '0' && ch <= '9') { // ���ڶ��
			res[idx++] = ch; // �״�� res�� ����ش�.
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			// ���� �����ڶ��
			peek(&s, &top);
			// ������ ������� �ʰ�, 
			// ���� �ְ��� �ϴ� �����ڰ� ���ÿ� �����ϴ� �����ں��� �켱 ������ �۰ų� ���ٸ�
			while (!isEmpty(&s) && prec(ch) <= prec(top)) {
				pop(&s, &top); // ���ÿ� �ִ� �����ڸ� ������
				res[idx++] = top; // res�� ����ְ�
				peek(&s, &top); // ���ÿ� �����ϴ� ���� �����ڸ� top�� ����ش�.
			}
			push(&s, ch);
		}
		//else if (ch == '('){ // ���� �Ұ�ȣ���
		//	// ������ ���ÿ� Ǫ���Ѵ�.
		//	push(&s, ch);
		//}
		//else if (ch == ')') { // �ݴ� �Ұ�ȣ���
		//	// top�� '('�� �� ������ �̾Ƽ� res�� �ٿ��ش�.
		//	pop(&s, &top);
		//	while (top != '(') {
		//		res[idx++] = top;
		//		pop(&s, &top);
		//	}
		//}
	}// for

	while (!isEmpty(&s)) {
		pop(&s, &top);
		res[idx++] = top;
	}

	res[idx] = '\0';
	return res;

}// while

int main() {

	printf("���� �Է� : ");
	char exp[100];
	scanf("%s", exp);
	char* res = inToPost(exp);
	printf("����ǥ�������� �ٲ� �� : %s\n", res);


	return 0;
}