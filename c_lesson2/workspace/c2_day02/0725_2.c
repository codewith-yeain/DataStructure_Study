# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>

typedef struct Student {
	char name[30];
	int score;
} Student;

int main() {
	/*Student S1 = {"��ö��", 80};
	Student S2 = { "ȫ�浿", 50 };
	Student S3 = { "�����", 60 };*/

	// ����ü �迭
	Student ar[] = {
		{ "��ö��", 80 },
		{ "ȫ�浿", 50 },
		{ "�����", 60 }
	};
	// [�ǽ�]
	// "ȫ�浿"�� ��µǰ� �ڵ带 �� �� ��������!
	printf("ar[1].name: %s\n", ar[1].name);

	// ����ü ������
	// �����ʹ� �������ε�, ����ü ������ �ּҰ��� ����ִ� ������

	Student ryu = {"��ȣ��", 100};
	Student* sptr = &ryu; // ����ü ������
	printf("ryu�� �ּҰ�: %d\n", &ryu);
	printf("ryu�� �ּҰ�: %d\n", sptr);

	// ����ü ���� ��ü�� �ּҰ� �ƴϴ�! &�� �ٿ��� �ּҰ� ������ ���̴�!
	// *sptr: ryu
	// (*sptr).name: ryu.name

	(*sptr).score = 50;

	// ����ü �����͸� ���� ������� �����ϱ�
	printf("(*sptr).name: %s\n", (*sptr).name);
	printf("(*sptr).score: %d\n", (*sptr).score);

	// ->
	printf("sptr -> name: %s\n", sptr -> name);
	printf("sptr -> score: %d\n", sptr -> score);


	
	return 0;
}