#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <string>

const int Y = 5;
const int X = 7;

void print_rec2(int x, int y) {
    if (y == 0) return;
    print_rec2(x, y - 1);
    std::cout << x << ' ' << y << std::endl;
}

void print_rec(int x, int y) {
    if (x == 0 && y == 0) return;
    if (y == 0) {
        print_rec(x - 1, Y);
    }
    else {
        print_rec(x, y - 1);
    }
    std::cout << x << ' ' << y << std::endl;
}

int main() {
    char str[] = "Hello";
    char str2[]  = "Hello";

    // Current date/time based on current system
    time_t now = time(0);

    // Convert now to tm struct for local timezone
    tm* localtm = localtime(&now);

    std::cout << "The local date and time is: " 
        << asctime(localtm) 
        << (*localtm).tm_mday << '.' << localtm->tm_mon
        << std::endl;
    return 0;
}

void replace_spaces(char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        if (str[i] == ' ') {
            str[i] = '-';
        }
    }
}

int main4() {
    // Задание: пользователь вводит логин и пароль
    //  если логин - admin, а пароль - qwerty, то выдается 
    //  приветствие, иначе - ACCESS DENIED
    const size_t BUFFER_SIZE = 100;
    char* login = new char[BUFFER_SIZE];
    char* password = new char[BUFFER_SIZE];

    std::cout << "Enter login: ";
    std::cin.getline(login, BUFFER_SIZE);

    std::cout << "Enter password: ";
    std::cin.getline(password, BUFFER_SIZE);

    if ( strcmp(login, "admin") == 0
      && strcmp(password, "qwerty") == 0 ) 
    {
        std::cout << "Hello, admin ";
    }
    else {
        std::cout << "ACCESS DENIED";
    }
    return 0;
}

int main3() {
    // Пользователь вводит строку
    const size_t BUFFER_SIZE = 100;
    char* str = new char[BUFFER_SIZE];

    std::cout << "Enter string: ";
    // std::cin >> str;  // ввод первого слова
    std::cin.getline(str, BUFFER_SIZE);  // ввод всей строки

    // заменить все пробелы на '-'
    replace_spaces(str);

    std::cout << str << std::endl;

    return 0;
}

int main2() {
    // функции работы со строками
    char* str = new char[16];
    strcpy(str, "Hello, World");
    strcpy_s(str, 14, "Hello, World");

    int len = strlen(str);  // длина строки !! только символы
    
    // конкатенация строк - соединение
    char* str2 = new char[4];
    strcpy(str2, "!!!");   //     12       3  1
    strcat(str, str2);     // Hello, World!!!\0

    // прямой доступ к символам - разыменование массива
    str[7] = 'w';

    // сравнение строк
    int res = _stricmp(str, "Hello, World!!!");  // res: -1 0 +1
    std::cout << res << std::endl;

    std::cout << str << " - " << len << std::endl;
    return 0;
}

int main1()
{
    char str1[] = "Hello";
    // задание: создать копию строки str1
    
    // неправильное решение (забыли про \0)
    // char* str2 = new char[5];
    // for (size_t i = 0; i < 5; i++)
    // {
    //     str2[i] = str1[i];
    // }
    
    // Правильное решение (с учетом \0)
    char* str2 = new char[5 + 1];  // 5 символов +1 терминатор
    for (size_t i = 0; i < 5; i++)
    {
        str2[i] = str1[i];
    }
    str2[5] = '\0';  // 0-терминатор - признак конца строки

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;



    return 0;
}
/*
    Строки
    Работу со строками делят на два вида:
    char*  -- старый тип, может работать в С
    std::string  -- специальный класс, создающий "безопасную" оболочку

    Часть 1 : char*
    Строка представляет собой обычный массив символов
    Главной особенностью строк является то, что они завершаются
    дополнительным символом '\0' (символ с кодом 0). Это позволяет
    определять их размер (или признак конца)
    НО!! Создает опасность:
     - если этот символ "забыть", то строка становится бесконечной
     - про дополнительный размер (+1 символ) нужно помнить при
        расчете размера массива "Hello" -> "Hello\0"
    функции работы со строками (#include <string.h>):
     strcpy(str, "Hello, World"); - копирования строк
     strcpy_s(str, 14, "Hello, World"); - с улучшенной безопасностью (
       ограничивает количество копируемых символов - 14)
     strlen(str); - длина строки
     strcat(str, str2); - конкатенация строк - str2 дописывается к str 
       !! важно - в str должен быть "запас"

     strcmp(str, "Hello, World!!!");  - сравнение строк: -1 0 1
     _stricmp(str, "Hello, World!!!");  - caseInsensitive 
     !! if( strcmp() ) ... - тест на неравенство
        if( strcmp() == 0 ) - на равенство
     !! нельзя сравнивать строки обычным ==
         if( str == "Hello" ) - сравнение адрессов
     !! внимание на сравнение чисел в строках:
         120 < 21 : "1" < "2"
*/
