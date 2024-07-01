# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>

# pragma pack(1) // defaul는 pack(4)로 4byte 단위로 건너뛰면서 담지만, pack(1)로 설정해줄 경우, 1byte 단위로 건너뛰면서 담게 된다.

// 구조체 정의
struct Student {
	char name[30]; // 멤버변수
	int kor; // 멤버변수
	int eng; // 멤버변수
};


// 구조체에 별명 설정하기
// 별명이 없을 땐 -> struct Korean 구조체 변수명;
// 별명이 있을 땐 -> Kor 구조체 변수명;
typedef struct Korean {
	int age;
} Kor;


// 구조체 별명만 설정하는 방식
typedef struct {
	int age;
} Person;


int main() {
	// 일반 자료형 변수 선언12
	int num;
	num = 10;
	// 구조체 변수 선언
	struct Student choi; // choi라는 이름을 가진 구조체 변수 선언
	// 구조체 내부의 변수(멤버변수)에 값을 저장하기
	
	/*choi.name = "최예인";*/ // 배열이기 때문에 주소값은 변경 불가능
	// 문자열에 값을 대입하는 함수 strcpy(), string.h에 정의되어있다.

	strcpy(choi.name, "최예인");
	choi.kor = 100;
	choi.eng = 77;

	printf("이름: %s\n국어점수: %d\n영어점수: %d\n", choi.name, choi.kor, choi.eng);
	printf("--------------------------------------------------------\n");

	// 변수 선언과 동시에 초기화
	int num1 = 10;
	
	// 구조체 변수 선언과 동시에 초기화
	// 멤버변수 순서에 맞추어 값들이 들어간다.
	struct Student s1 = { "홍길동", 90, 80 };
	s1.eng = 70;
	printf("이름: %s\n국어점수: %d\n영어점수: %d\n", s1.name, s1.kor, s1.eng);

	printf("--------------------------------------------------------\n");

	// 멤버변수 이름을 직접 명시하여 초기화를 할 수 있다.
	struct Student s2 = { .name = "김철수" };
	printf("이름: %s\n국어점수: %d\n영어점수: %d\n", s2.name, s2.kor, s2.eng);

	printf("--------------------------------------------------------\n");
	printf("구조체 변수 사이즈 : %d\n", sizeof(s2));


	// 별명 설정한 구조체 변수 선언
	struct Korean k1;
	Kor k2;

	// 별명만 설정한 구조체 변수 선언
	// struct Person p1; 기존 방식은 사용 불가능
	Person p2;


	return 0;
}