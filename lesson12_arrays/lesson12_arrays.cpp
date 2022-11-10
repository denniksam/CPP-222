
#include <iostream>

int main() {
    const size_t N = 20;  // size_t - тип для индексов 
    int arr[N];  // при указании размера массива нужна константа (не переменная)
    
    srand(time(0));  // сидирование генератора ПСЧ

    for (size_t i = 0; i < N; i++)
    {
        arr[i] = rand() % 101 - 50;
    }

    for (size_t i = 0; i < N; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    // задачи по работе с полученным массивом:
    // 1. Подсчитать кол-во положительных чисел в массиве arr.
    size_t cnt = 0;
    for (size_t i = 0; i < N; i++) {
        if (arr[i] > 0) {
            ++cnt;
        }
    }
    std::cout << "Positive elements: " << cnt << std::endl;

    // 2. Подсчитать кол-во отрицательных, а также (Отдельно) нулевых элементов
    size_t neg = 0;
    size_t countZeroes = 0;  // casing - соединение нескольких слов в названии
                             // lowerCamelCase - первое с маленькой, остальные с большой
                             // CapitalCamelCase, php_style, CONST_STYLE
    for (size_t i = 0; i < N; i++)
    {
        if (arr[i] < 0) {
            neg++;
        }
        if (arr[i] == 0)
            ++countZeroes;
    }
    std::cout << "Negative elements: " << neg << std::endl;
    std::cout << "There are " << countZeroes << " zero elements." << std::endl;

    // 3. Найти первый и последний отрицательные элементы и их индексы. Если он один - вывести
    //    его дважды (и как первый, и как последний). Если отрицательных нет,
    //    так и вывести (нет отрицательных)
    // 3а: первый отрицательный
    size_t first_neg_index;
    for (first_neg_index = 0; first_neg_index < N; first_neg_index++) {
        if (arr[first_neg_index] < 0) {
            break;
        }
    }
    if (first_neg_index == N) {  // цикл прошел все эл-ты и нигде не сработал break
        std::cout << "There are no negative elements." << std::endl;
    }
    else {  // сработал break
        std::cout << "First negative element: " << arr[first_neg_index]
            << " has index " << first_neg_index << std::endl;            
    }
    // 3б: последний отрицательный
    // общая идея - так же цикл, но с конца к началу.
    // Особенность: тип size_t не может хранить отрицательные числа, поэтому
    //  будет сложно понять как закочился цикл: прошел все эл-ты или нашел отрицательный
    // Применим гибридный подход: пустим цикл в прямом направлении, а элементы будем
    //  перебирать в обратном порядке
    size_t k;
    size_t last_neg_index;
    for (k = 0; k < N; ++k) {           // цикл в прямом направлении
        last_neg_index = N - 1 - k;
        if (arr[last_neg_index] < 0) {  // arr[N - 1 - k] --> k-й эл-т, но с конца
            break;                      // k          0  1  2    8  9  10   пусть N = 10
        }                               // N - 1 - k  9  8  7    1  0  -1(4 294 967 295)
    }
    if (k == N) {  // цикл прошел все эл-ты и нигде не сработал break
        std::cout << "There are no negative elements." << std::endl;
    }
    else {  // сработал break
        std::cout << "Last negative element: " << arr[last_neg_index]
            << " has index " << last_neg_index << std::endl;
    }

    // вывести все элементы массива (через пробел), которые находятся между первым
    //   и последним отрицательными элементами (сами граничные элементы не выводить)
    if (first_neg_index != N /* && k != N*/)
    {
        for (size_t i = first_neg_index + 1; i < last_neg_index; i++)
            std::cout << arr[i] << " ";
    }
    return 0;
}

int main1()
{
    // описание массива
    int arr1[10];   // тип имя[размер]
    // в памяти "бронируется" место на 10 ячеек типа int

    // заполнение массива
    arr1[0] = 10;   // доступ к ячейке массива - имя[индекс]
    arr1[1] = 11;
    arr1[2] = 12;
    arr1[3] = 13;
    arr1[4] = 14;

    // "прочитать" массив - вывести на экран
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << arr1[i] << ' ';
    }
    std::cout << std::endl << arr1 << std::endl;

    return 0;
}
/*
    Массивы
     последовательное (один-за-одним)
     однотипное (все элементы одного типа)
     хранилище данных.
    С одной стороны, массив - это переменная, то есть именованная сущность,
     отвечающая за хранение данных (имя одно, данных - много)
    С другой стороны, массив заменяет собой сразу несколько переменных,
     обеспечивая хранение множества данных (одного типа)

    <--- array --->   например int array[5] - выделить 5 ячеек
    [ ][ ][ ][ ][ ]
    индексация -  способ указать какую ячейку из массива мы имеем в виду
    индекс - смещение, определяющее сколько надо отступить от начала массива
      для того чтобы попасть в данную ячейку.
    !! описанный массив int array[5] имеет ячейки
    array[0] - array[1] - array[2] - array[3] - array[4]
*/