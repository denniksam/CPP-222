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
	if (n > 100) {     // "некий лимит памяти"
		return NULL;   // превышен "лимит" - возврат NULL как признак ошибки
	}
	return new int[n]; // выделение реальной памяти
}

void free_arr(int* arr) {  // освобождение памяти
	if (arr == NULL) {
		std::cout << "free_arr: NULL pointer error" << std::endl;
		return;
	}
	delete[] arr;
}

void fill_random(int* arr, size_t length) {
	if (!arr) {  // для борьбы с ошибкой arr = NULL
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
	// для указателей есть предопределенные константы:
	// nullptr - MS компилятор
	// NULL - универсальная константа
	// хотя NULL это обычный 0, рекоменуется использовать NULL - для указателей,
	// а 0 - для чисел. НЕ рекомедуется NULL для чисел, 0 - для указателей
	// Рекомедуется для указателей, которые не инициализированы, задавать
	//  значение NULL

	int* p;  // не рекомендуется. Или int* р = new int; или int* p = NULL;
	//////////
	p = new int;

	// в функциях, использующих указатели, также рекомендуется (требуется)
	// проверять все передаваемые указатели на NULL

	int n = 101;
	int* arr = NULL;  // рекомендация - до назначения установить NULL
	arr = make_arr(n);
	fill_random(arr, n);
	print_arr(arr, n);
	print1(arr, n);
	free_arr(arr);
	arr = NULL;  // освобожденный указатель рекомедуется обнулить

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

	// двумерные массивы: появляется разделение на обычные (прямоугольные)
	//  и массивы указателей - "зубчатые", "рваные" (jagged, ragged) массивы
	int** jag;  // массив указателей (указатель на указатель)
	jag = new int* [3];  // Первый уровень - массив из трех указателей	   
	jag[0] = new int[2]; // первый из указателей - на массив из 2х эл-тов  [ [][] ]
	jag[1] = new int[3]; // второй из указателей - на массив из 3х эл-тов  [ [][][] ]
	jag[2] = new int[1]; // третий из указателей - на массив из 1го эл-та  [ [] ]

	int** rect = new int* [4];			   // создаем массив из 4х указателей
	for (size_t i = 0; i < 4; i++) {	   // циклом
		rect[i] = new int[5];			   // в каждый из 4х указателей создаем 
		for (size_t j = 0; j < 5; j++) {   // массив из 5 эл-тов
			rect[i][j] = 11 + i * 10 + j;  // каждый из эл-тов получает значение
		}								   // rect [int*] ----> [int][int][int][int][int]    [][][][][]
	}									   //      [int*] ----------------------------------->
	print3(rect, 4, 5);					   //      [int*]
										   //      [int*]

	int ar2d[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	// print3((int**)ar2d, 3, 4); - ошибка из-за несовместимости int** и int[][]
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

void print3(int** arr, size_t n, size_t m) {  // вывод прямоугольного массива
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			std::cout << arr[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

/* Указатели, часть 2
int* и int[] - полностью совместимые - функция, которая принимает
параметр int[] может работать с аргументом int* и наоборот.

int** и int[][] - несовместимы
 при создании статического массива (int[][]) происходит линеаризация - на самом
 деле создается один массив, в котором все под-массивы стоят "в линию" один
 за одним. Поэтому тип int[][] превращается в int*
 Принудительное преобразование int[][] к int** приводит к тому, что элементы
 массива int[][] (числа) начинают восприниматься как адреса (int*) и приводят
 к обращения к памяти.

int* x, y;  -- два указателя? Нет, х - указатель, у - нет, просто int
int* x, * y;
int *x, *y;
int *x, y;

*/
