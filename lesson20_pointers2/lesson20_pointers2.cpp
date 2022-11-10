#include <iostream>

void print1(int* arr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void print2(int arr[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void print3(int** arr, size_t n, size_t m);
void print4(int* arr, size_t n, size_t m);


int* make_arr(size_t n) {
	if (n > 100) {     // "����� ����� ������"
		return NULL;   // �������� "�����" - ������� NULL ��� ������� ������
	}
	return new int[n]; // ��������� �������� ������
}

void free_arr(int* arr) {  // ������������ ������
	if (arr == NULL) {
		std::cout << "free_arr: NULL pointer error" << std::endl;
		return;
	}
	delete[] arr;
}

void fill_random(int* arr, size_t length) {
	if (!arr) {  // ��� ������ � ������� arr = NULL
		std::cout << "fill_random: NULL pointer error" << std::endl;
		return;
	}
	for (size_t i = 0; i < length; i++) {
		arr[i] = rand();
	}
}

void print_arr(int* arr, size_t length) {
	if (!arr) {  
		std::cout << "print_arr: NULL pointer error" << std::endl;
		return;
	}
	for (size_t i = 0; i < length; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

int main() {
	// ��� ���������� ���� ���������������� ���������:
	// nullptr - MS ����������
	// NULL - ������������� ���������
	// ���� NULL ��� ������� 0, ������������ ������������ NULL - ��� ����������,
	// � 0 - ��� �����. �� ������������ NULL ��� �����, 0 - ��� ����������
	// ������������ ��� ����������, ������� �� ����������������, ��������
	//  �������� NULL

	int* p;  // �� �������������. ��� int* � = new int; ��� int* p = NULL;
	//////////
	p = new int;

	// � ��������, ������������ ���������, ����� ������������� (���������)
	// ��������� ��� ������������ ��������� �� NULL

	int n = 101;
	int* arr = NULL;  // ������������ - �� ���������� ���������� NULL
	arr = make_arr(n);
	fill_random(arr, n);
	print_arr(arr, n);
	print1(arr, n);
	free_arr(arr);
	arr = NULL;  // ������������� ��������� ������������ ��������

	return 0;
}

int main1()
{
	int arr1[5] = { 5, 4, 3, 2, 1 };
	std::cout << "Static array:\n";
	print1(arr1, 5);
	print2(arr1, 5);

	int* arr2 = new int[5] { 2, 3, 4, 5, 6 };
	std::cout << "Dynamic array:\n";
	print1(arr2, 5);
	print2(arr2, 5);

	// ��������� �������: ���������� ���������� �� ������� (�������������)
	//  � ������� ���������� - "��������", "������" (jagged, ragged) �������
	int** jag;  // ������ ���������� (��������� �� ���������)
	jag = new int* [3];  // ������ ������� - ������ �� ���� ����������	   
	jag[0] = new int[2]; // ������ �� ���������� - �� ������ �� 2� ��-���  [ [][] ]
	jag[1] = new int[3]; // ������ �� ���������� - �� ������ �� 3� ��-���  [ [][][] ]
	jag[2] = new int[1]; // ������ �� ���������� - �� ������ �� 1�� ��-��  [ [] ]

	int** rect = new int* [4];			   // ������� ������ �� 4� ����������
	for (size_t i = 0; i < 4; i++) {	   // ������
		rect[i] = new int[5];			   // � ������ �� 4� ���������� ������� 
		for (size_t j = 0; j < 5; j++) {   // ������ �� 5 ��-���
			rect[i][j] = 11 + i * 10 + j;  // ������ �� ��-��� �������� ��������
		}								   // rect [int*] ----> [int][int][int][int][int]    [][][][][]
	}									   //      [int*] ----------------------------------->
	print3(rect, 4, 5);					   //      [int*]
										   //      [int*]

	int ar2d[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	// print3((int**)ar2d, 3, 4); - ������ ��-�� ��������������� int** � int[][]
	print4((int*)ar2d, 3, 4);
	print4(&ar2d[0][0], 3, 4);
	print4(*ar2d, 3, 4);

	return 0;
}

void print4(int* arr, size_t n, size_t m) {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			std::cout << arr[i*m + j] << ' ';
		}
		std::cout << std::endl;
	}
}

void print3(int** arr, size_t n, size_t m) {  // ����� �������������� �������
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

/* ���������, ����� 2
int* � int[] - ��������� ����������� - �������, ������� ���������
�������� int[] ����� �������� � ���������� int* � ��������.

int** � int[][] - ������������
 ��� �������� ������������ ������� (int[][]) ���������� ������������ - �� �����
 ���� ��������� ���� ������, � ������� ��� ���-������� ����� "� �����" ����
 �� �����. ������� ��� int[][] ������������ � int*
 �������������� �������������� int[][] � int** �������� � ����, ��� ��������
 ������� int[][] (�����) �������� �������������� ��� ������ (int*) � ��������
 � ��������� � ������.

int* x, y;  -- ��� ���������? ���, � - ���������, � - ���, ������ int
int* x, * y;
int *x, *y;
int *x, y;

*/
