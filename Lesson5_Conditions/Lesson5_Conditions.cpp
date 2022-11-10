// Lesson5_Conditions.cpp : Условия и условный оператор

#include <iostream>

int main() {
    // Проверка того, что введенное число 4-значное
    long x;
    std::cout << "Enter 4-digit number: ";
    std::cin >> x;

    if ( ! (x > 999 && x < 10000)) { // Инверсное условие
         std::cout << "Wrong!";      // вывод, что неправильно
         return -1;                  // и выход из main
    }                                // Это позволяет 
                                     // не писать else, т.к.
    std::cout << "Ok\n";             // выход остановит программу
    
    // Вывести первую цифру числа (зная, что в нем 4 цифры)
    int digit1 = x / 1000;
    std::cout << "1st digit: " << digit1 << std::endl;
    
    // Вывести вторую цифру
    int digit2 =                    // 1234, d1 = 1
        (x - digit1 * 1000) / 100;  // 1234 - 1*1000 = 234
    
    std::cout << "2nd digit: " << digit2 << std::endl;

    return 0;
}

int main3() {
    // проверка логина и пароля
    std::string login, pass;

    std::cout << "Login: ";
    std::cin >> login;
    std::cout << "Password: ";
    std::cin >> pass;

    if (login == "user"  && pass == "123"
     || login == "admin" && pass == "321"
     || login == "moder" && pass == "hello")
    {
        std::cout << "Access granted";
    }
    else 
    {
        std::cout << "Access denied";
    }

    return 0;
}

int main2() {
    // "каскадное" сравнение
    // Пользователь вводит температуру тела
    // программа выводит диагноз:
    //   < 35  cold
    //   35-37 norm
    //   37-38 desease
    //   >38   reanimation

    std::cout << "Enter body temperature: ";
    float t;
    std::cin >> t;
    if (t < 35)
        std::cout << "You've got a cold";
    if (t >= 35 && t < 37)
        std::cout << "Your temperature is normal";
    if (t >= 37 && t <= 38.2)
        std::cout << "You're ill.";
    if (t > 38.2)
        std::cout << "You should immediately go to the hospital! Reanimation";
    /*
    if (t < 35) {
        std::cout << "Cold";
    }
    else if (t < 37) {
        std::cout << "Normal";
    }
    else if (t < 38) {
        std::cout << "Desease";
    }
    else {
        std::cout << "Reanimation";
    }
    */
    /*
    if (t < 35) {
        std::cout << "Cold";
    }
    else {
        if (t < 37) {
            std::cout << "Normal";
        }
        else {
            if (t < 38) {
                std::cout << "Desease";
            }
            else {
                std::cout << "Reanimation";
            }
        }
    }
    */
    return 0;
}

int main1()
{
    std::cout
        << "2 < 3  --> " << (2 < 3)  << std::endl
        << "3 == 3 --> " << (3 == 3) << std::endl
        << "3 <= 3 --> " << (3 <= 3) << std::endl
        << "3 != 3 --> " << (3 != 3) << std::endl;

    // odd / even testing
    std::cout << "Enter number: ";
    int x;
    std::cin >> x;
    if (x % 2 == 1) {
        std::cout << "It is odd" << std::endl;
    } 
    else {
        std::cout << "It is even" << std::endl;
    }
    return 0;
}

/*
Условие (условное выражение, предикат) - выражение,
имеющее результат в виде двух возможностей: true или false
 2 < 3  --> true (1)
 3 == 3 --> true (1)
 2 > 4  --> false(0)
Условия разделяются на сравнения и отношения
Сравнения                Отношения
x == y - равенство       x < y,  x > y  - строгие
x != y - неравенство     x <= y, x >= y - нестрогие
!! составные операторы нельзя разрывать пробелом:
  НЕЛЬЗЯ:  = =    < =
  а также менять порядок:   =<  =>

Для хранения результатов условий существует спец. тип данных
 bool (он же - логический тип)

 bool x = (3 == 2);
*/
/*
Условный оператор или оператор ветвления
if(условие) { операторы; операторы; } - сокращенная форма
если условие истинно (true), то операторы будут выполнены,
иначе - пропущены

if(условие) { операторы1; операторы1; }
else { операторы2; операторы2; }  - полная форма
если условие истинно (true), то будут выполнены операторы1,
иначе - операторы2

операторы, заключенные в "операторные скобки" {}
называют "телом"
*/
/*
Логические операторы
Если необходимо проверять несколько условий сразу, то
для этого предусмотрены следующие операторы:
 && "оператор И" - требует выполнение всех условий
 || "ИЛИ" - должно выполниться хотя бы одно
 !  "НЕ" (инверсия) - меняет результат условия на обратный

if( x > 10 && x < 20 ) -- х в диапазоне (10,20)
if( login == "user" && pass == "123" )

*/
