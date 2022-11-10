﻿#include <conio.h>
#include <time.h>
#include <iostream>

// функция pause() - выводит сообщение "Press a key" и ждет нажатия
void pause() {
    std::cout << "Press a key\n";
    _getch();
}

// функция, возвращающая случайное число в заданном пределе
int random_range(int max) {  // будем считать 0..max-1 (не включительно)
    return rand() % max;
}

// функция, выводящая делители числа n, а также их сумму
void print_divisors(int n) {
    int d, sum;
    sum = 1;
    std::cout << 1 << ' ';
    for (d = 2; d * d < n; d++) {
        if (n % d == 0) {
            std::cout << d << ' ' << n / d << ' ';
            sum += d + n / d;
        }
    }
    if (d * d == n) {
        std::cout << d << ' ';
        sum += d;
    }
    std::cout << '(' << sum << ')';
}


int main()
{
    std::cout << "Hello World!\n";
    pause();   // вызов функции - переход в "подпрограмму"

    srand( time(NULL) );
    int r = random_range(20) + random_range( random_range(20) );
    std::cout 
        << "random_range(20) = " 
        << random_range(20);   // вызов с передачей аргумента (значения параметра)
    std::cout << std::endl;

    for (int n = 10; n < 30; ++n) {
        std::cout << n << ": ";
        print_divisors(n);
        std::cout << std::endl;
    }
    
}

/*
    Функции
    Исторически, функции - именованные подпрограммы
    Подпрограмма - часть программы, имеющая логическое начало
     и конец.
    Именованная - обращение к подпрограмме происходит при помощи
     ее имени
    Термин "функция" очень нагружен в программировании и, в строгом
     употреблении, обозначает не то, о чем мы говорим.
     В этом ключе рекомендуется применять термин "процедура"
    Также исторически, функции и процедуры отличались тем, что
     функция возвращала значение, а процедура - нет.
    Процедурный подход (иногда - процедурная парадигма) - составление
     программ в виде набора процедур (или функций), вызывающих 
     друг друга по определенным закономерностям.

    Определение функции:
     [тип возврата] [имя]( [тип и имя параметров] ) {
        [тело функции]
        return [значение]
     }
     - [тип возврата] или тип возвращаемого значения - обычный тип
        в С++ (в т.ч. пользовательский). Плюс специальный тип "void",
        означающий что возврата нет (процедура)
    - [имя] - идентификатор, построенный по правилам именования и
        рекомендациям
    - () - обязательно, если параметров нет, то остаются пустые
        скобки ()
    - параметры: разделенные запятой пары [тип] [имя]. Если несколько
        параметров имеют одинаковые типы, то каждый раз тип повторяется
    Примеры:
    int my_random() { ... } - функция без параметров, которая возращает
      значение типа инт
      неправильно: int my_random { ... } (обязательно скобки my_random()  )
    void print( std::string str ) { ... } - функция с одним параметром
      str типа std::string, не возвращающая значений
    long mul(int x, int y) { ... } - c двумя параметрами х и у, оба
      типа int, возвращает значение типа long
      неправильно: long mul(int x, y) { ... } (перед у нужен int)
    int char_position( char c, std::string str ) { ... }

*/

/*
    Схема вызова-возврата         Создается функция (подпрограмма)
                              | [область возврата]     [область параметров]
int random_range(int max) {   |  <-..10^      [тело - область кода]  ^20
    return rand() % max;      |        |-------return (10)           |
}                             |                                      |
...                           |                                      |
int r = random_range(20) ---------------------------------------------
   (10) <--...

    аргумент (значение параметра) копируется в область параметров
    запускается тело функции, в нем происходит работа с параметром, все
     изменения которого допускаются, но отражаются только на области 
     параметров (не влияют на саму программу)
    команда возврата (return) запишет значение в область возврата,
     которая создается с тем типом, который заявлен для функции
    операция присваивания (int r = random_range(20)) перенесет (скопирует)
     данные из этой области в область переменной r
*/
