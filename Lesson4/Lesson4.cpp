// Lesson4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
int main() {
    tm datetime;
    std::cout << "Enter date in format '25.12.2020': ";
    std::cin >> std::get_time(&datetime, "%d.%m.%Y");
    std::cout
        << "year "  << datetime.tm_year    << std::endl
        << "month " << datetime.tm_mon + 1 << std::endl
        << "day "   << datetime.tm_mday    << std::endl;

    return 0;
}





int main_4() {
    /* Пользователь вводит полное имя и год рождения
       Программа вычисляет сколько лет исполнится в этом (2022) году
       Пример:
       Enter name:  John Smith
       Year of birth:  1980
       A>This year, John Smith, you'll be 42 years old 

       B>This year, John, you'll be 42 years old 

       Формирователь "карточки":
       Пользователь вводит (раздельно) имя, фамилию, возраст.
       Программа формирует "карточку" "Фамилия Имя, год рождения"
        и сохраняет ее в одной переменной
       Пример:
       Surname: Smith
       Name: John
       Age: 42
       >'Smith John, 1980'
       */
    return 0;
}

int main_3() {
    // Работа со строками
    /* В С++ есть два подхода к строкам: массив символов
    *  и специальный тип std::string
    */
    std::string str;  // переменная для хранения строки
    std::cout << "Enter string: ";
    // std::cin >> str;  // Вводит первое "слово" - до пробела
    
    // Вводит всё, что напечатано (с пробелами)
    std::getline(std::cin, str);
    std::cout << "You type: " << str << std::endl;

    // Конкатенация строк - сложение, соединение строк
    // "Hello" + " all" ==> "Hello all"
    // "10" + "20"  ==> "1020"

    int x = 10;              // Число
    std::string x_str =      // Строка с символьным (текстовым)
        std::to_string(x);   // представлением числа

    int y = 20;
    std::string y_str = std::to_string(y);

    std::cout << "x + y = " << x + y << std::endl
        << "x_str + y_str = " << x_str + y_str << std::endl
        << std::endl;

    return 0;
}

int main_2() {
    // переменные и типы данных (продолжение)
    int code;  // код символа - вводит пользователь
    char sym;  // сам символ - выводит программа

    std::cout << "Enter code (0..255): ";
    std::cin >> code;  // сохраняем ввод пользователя

    sym = (char)code;  // () - преобразование типа (явное)

    std::cout << "Symbol: " << sym << std::endl;

    /********* Обратная задача ************/
    std::cout << "Enter a symbol: ";
    std::cin >> sym;

    code = (int)sym;  // тоже преобразование типа

    std::cout << "Code of symbol: " << code << std::endl;


    return 10;
}

void main_dz()
{
    // Вычисление тригонометрии - косинус. 
    // Нужно градусы переводить в радианы
    std::cout << cos(34 * M_PI / 180) << std::endl;

    // Перевод часы-минуты-секунды
    int time = 100530;    // общее время в секундах
    int h = time / 3600;  // в часе 3600 секунд
    int minsec = time % 3600;  // time - h * 3600
    int m = minsec / 60;  // минуты
    int s = minsec % 60;  // minsec - m * 60

    std::cout << "hours: " << h << std::endl
        << "minsec: " << minsec << std::endl
        << "min: " << m << std::endl
        << "sec: " << s << std::endl
        << std::endl;

    h = 10;  // 36000
    m = 20;  // 1200
    s = 30;  // 30  --> 37230 (timestamp)
    std::cout << h * 3600 + m * 60 + s;

}

/*

*/
