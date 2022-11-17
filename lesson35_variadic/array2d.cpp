#include <ctime>
#include <cstdlib>
#include <iostream>

#include "array2d.h"

// Creates 2D array of int[N][M]
int** create_arr2d(size_t N, size_t M) {
	int** arr = new int* [N];
	for (size_t i = 0; i < N; i++) {
		arr[i] = new int[M];
	}
	return arr;
}

// Free memory from 2D array of int[N][M]
void delete_arr2d(int** arr, size_t N) {
	for (size_t i = 0; i < N; i++) {
		delete[] arr[i] ;
	}
	delete[] arr;
}

// Fills 2D array of int[N][M] by randoms
void fill_arr2d(int** arr, size_t N, size_t M) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			arr[i][j] = rand() % 21 - 10;
		}
	}
}

// Prints 2D array of int[N][M] by randoms
void print_arr2d(int** arr, size_t N, size_t M) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			std::cout << arr[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

/* Creates array (plain) with only positive numbers from arr1 and arr2 (both 2D)
   res_size - returns count of positives found */
int* select_positive(int** arr1, int** arr2, size_t N, size_t M, size_t &res_size) {
	// first, count positives
	int cnt = 0;
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			if (arr1[i][j] > 0) {
				++cnt;
			}
		}
	}
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			if (arr2[i][j] > 0) {
				++cnt;
			}
		}
	}
	if (cnt == 0) {   // No positives
		return NULL;
	}
	int* res = new int[cnt];   // memory to return
	cnt = 0;
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			if (arr1[i][j] > 0) {
				bool in_array = false;				 // look through res
				for (size_t k = 0; k < cnt; k++) {	 // to find this positive
					if (res[k] == arr1[i][j]) 		 // 
						in_array = true;			 // 
				}
				if(!in_array)						 // if it is new value
					res[cnt++] = arr1[i][j];		 // append it in res
			}
		}
	}
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			if (arr2[i][j] > 0) {
				bool in_array = false;				 // look through res
				for (size_t k = 0; k < cnt; k++) {	 // to find this positive
					if (res[k] == arr2[i][j]) 		 // 
						in_array = true;			 // 
				}
				if (!in_array)						 // if it is new value
					res[cnt++] = arr2[i][j];		 // append it in res
			}
		}
	}
	res_size = cnt;   // side effect - outer variable will be changed
	// in res - unique numbers, but size (cnt) may be greater
	// int res_unique
	return res;
}

// Demo for 2D arrays
void arr2d_demo() {
	const int N = 3, M = 5;
	srand(time(NULL));
	int** arr1 = create_arr2d(N, M);
	fill_arr2d(arr1, N, M);
	print_arr2d(arr1, N, M);
	std::cout << "------------------------------------\n";

	int** arr2 = create_arr2d(N, M);
	fill_arr2d(arr2, N, M);
	print_arr2d(arr2, N, M);
	std::cout << "------------------------------------\n";

	size_t ucnt;   // for side effect
	int* uniqs = select_positive(arr1, arr2, N, M, ucnt);
	// after function call  ucnt - size of uniqs
	for (size_t i = 0; i < ucnt; i++)	{
		std::cout << uniqs[i] << ' ';
	}
	std::cout << "\n------------------------------------\n";

	delete_arr2d(arr1, N);
	delete_arr2d(arr2, N);
	delete[] uniqs;
}