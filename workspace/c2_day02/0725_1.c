# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>

# pragma pack(1) // defaul�� pack(4)�� 4byte ������ �ǳʶٸ鼭 ������, pack(1)�� �������� ���, 1byte ������ �ǳʶٸ鼭 ��� �ȴ�.

// ����ü ����
struct Student {
	char name[30]; // �������
	int kor; // �������
	int eng; // �������
};


// ����ü�� ���� �����ϱ�
// ������ ���� �� -> struct Korean ����ü ������;
// ������ ���� �� -> Kor ����ü ������;
typedef struct Korean {
	int age;
} Kor;


// ����ü ���� �����ϴ� ���
typedef struct {
	int age;
} Person;


int main() {
	// �Ϲ� �ڷ��� ���� ����12
	int num;
	num = 10;
	// ����ü ���� ����
	struct Student choi; // choi��� �̸��� ���� ����ü ���� ����
	// ����ü ������ ����(�������)�� ���� �����ϱ�
	
	/*choi.name = "�ֿ���";*/ // �迭�̱� ������ �ּҰ��� ���� �Ұ���
	// ���ڿ��� ���� �����ϴ� �Լ� strcpy(), string.h�� ���ǵǾ��ִ�.

	strcpy(choi.name, "�ֿ���");
	choi.kor = 100;
	choi.eng = 77;

	printf("�̸�: %s\n��������: %d\n��������: %d\n", choi.name, choi.kor, choi.eng);
	printf("--------------------------------------------------------\n");

	// ���� ����� ���ÿ� �ʱ�ȭ
	int num1 = 10;
	
	// ����ü ���� ����� ���ÿ� �ʱ�ȭ
	// ������� ������ ���߾� ������ ����.
	struct Student s1 = { "ȫ�浿", 90, 80 };
	s1.eng = 70;
	printf("�̸�: %s\n��������: %d\n��������: %d\n", s1.name, s1.kor, s1.eng);

	printf("--------------------------------------------------------\n");

	// ������� �̸��� ���� ����Ͽ� �ʱ�ȭ�� �� �� �ִ�.
	struct Student s2 = { .name = "��ö��" };
	printf("�̸�: %s\n��������: %d\n��������: %d\n", s2.name, s2.kor, s2.eng);

	printf("--------------------------------------------------------\n");
	printf("����ü ���� ������ : %d\n", sizeof(s2));


	// ���� ������ ����ü ���� ����
	struct Korean k1;
	Kor k2;

	// ���� ������ ����ü ���� ����
	// struct Person p1; ���� ����� ��� �Ұ���
	Person p2;


	return 0;
}