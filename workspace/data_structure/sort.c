#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define CHANGE(data1, data2){int temp; temp = data1; data1 = data2; data2= temp;} // ��ũ�� �Լ�


void show(int* ar, int n) {
	for (int i = 0; i < n; i++) {
		printf("%2d ", ar[i]);
	}
	printf("\n");
}

void bubbleSort(int* ar, int n) { // �迭 �ּ�, n�� ����� ����

	// ���� ���� �ڵ� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i-1; j++) {
			if (ar[j] > ar[j + 1]) {
				CHANGE(ar[j], ar[j + 1])
			}
		}
	}

	show(ar, n);

}

void selectionSort(int* ar, int n) {
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i; j < n; j++) {
			if (ar[min] > ar[j]){
				min=j;
			}
		}
		CHANGE(ar[min], ar[i]);
		show(ar, n);
	}
}

void insertionSort(int* ar, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (ar[j] < ar[j-1]) { // ���� ���Ұ� �� ũ��
				CHANGE(ar[j], ar[j - 1]);
			}
			else { // ���� ���Ұ� �� ������
				break;
			}
		}
	}
	show(ar, n);
}



int main() {
	int ar[10] = { 10, 4, 5, 8, 1, 2, 6, 7, 9, 3 };
	//bubbleSort(ar, 10);
	//selectionSort(ar, 10);
	insertionSort(ar, 10);

	return 0;
}