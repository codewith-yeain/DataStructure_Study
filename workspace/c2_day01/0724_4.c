#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printTime(int second) {
	//int hours, minutes, seconds;

	//hours = second / 3600;
	//minutes = (second % 15) / 60;
	//seconds = second % 60;

	//printf("���: %d�ð�/%d��/%d��\n", hours, minutes, seconds);

	int time[3];

	time[0] = second / 3600;
	time[1] = (second % 15) / 60;
	time[2] = second % 60;

	printf("���: %d�ð�/%d��/%d��\n", time[0], time[1], time[2]);

}


int main() {
	int second;
	printf("�� ��: ");
	scanf_s("%d", &second);

	printTime(second);

	return 0;
}