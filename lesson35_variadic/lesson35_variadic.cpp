#include <iostream>
#include <cstdarg>   // <varargs.h>
#include "array2d.h"

// "старый" подход (до С++11)
int sum_end = 0;
int sum(int x, ...) {      // нужен хотя бы один именованный параметр
    va_list args;          // список аргументов
    va_start(args, x);     // старт сканнирования - передаем список и последний именованный пар-р
    // нет механизма, определяющего количество переданных параметров
    // идеи - две: 
    //  1) указывать отдельным параметром кол-во параметров
    //  2) использовать специальное значение для признака конца (аналог '\0') - sum_end
    int res = x;           // заготавливаем результат, добавляем именованный параметр
    int arg;               // переменная для аргумента (значения параметра)
    while ((arg = va_arg(args, int)) != sum_end) {     // va_arg(args, int) - cканнер
        res += arg;                                    //  берет следующий int из args
    }                                                  // 
    return res;
}
// более современный подход - variadic template
template <class...T>
auto summ(T... args) {     // C++17 - поменять режим компиляции (Project-Properties-General-Language standart)
    return (args + ...);   // fold expression - все args записываются через "+"
}

template <class key_t, class val_t>
struct Pair {
    key_t key;
    val_t val;
};

int main()
{
    std::cout << sum(3, 1, 2, 3, sum_end) << "\n";
    std::cout << sum(1, 2, 3, sum_end) << "\n";
    std::cout << sum(3, 1, 2, 3, 5, sum_end) << "\n";

    std::cout << summ(3, 1, 2, 3, sum_end) << "\n";
    std::cout << summ(1.1, 2.1, 3.1, sum_end) << "\n";
    std::cout << summ(3.2f, 1.1f, 2.3f, 3.1f, 5.4f, sum_end) << "\n";

    Pair<int, char> pair;
    pair.key = 10;
    pair.val = 'A';

    arr2d_demo();

    return 0;
}

/* Variadic - функции с переменным количеством аргументов

*/
/*
    Big Endian                A    7    B    5  
    A7B5 - 16 битное число: 1010 0111 1011 0101   - математическое представление
    представление в памяти: A7 <-> B5  -    B    5    A    7 
                                          1011 0101 1010 0111   
    Зачем?
    Для простоты сужающего преобразования
    (char) A7B5 -> B5
*/