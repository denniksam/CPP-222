// циклы, продолжение. Организицая меню, вложенные циклы
#include <Windows.h>    // работа с консолью как с окном
#include <iostream>
#include <conio.h>      // console input-output [ _getch() ]

// gotoxy(x,y) - переместить курсор в позицию (х,у)
#define gotoxy(x,y)   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y })

int main()
{
    /*
    Користувач вводить число. Визначити кількість цифр у цьому числі,
    порахувати їхню суму та середнє арифметичне.
    Визначити кількість нулів у цьому числі.
    Спілкування з користувачем організувати через меню.
    */

    char button;

    do {
        system("CLS");

        long long number;
        std::cout << "Enter your number: ";
        std::cin >> number;
        std::cout << std::endl;

        std::cout
            << " -------------Menu--------------" << std::endl
            << " The number of digit in a number" << std::endl
            << " The sum of digit in a number" << std::endl
            << " Arithmetical mean of digits" << std::endl
            << " The number of zeros in a number" << std::endl;

        gotoxy(0, 3);
        std::cout << ">";
        short y = 3;
        do {
            button = _getch();
            if (button == 0 || button == -32)
            {
                button = _getch();
            }
            gotoxy(0, y);
            std::cout << ' ';

            if (button == 80)
            {
                y += 1;
                if (y >= 7)
                {
                    y = 3;
                }
            }

            if (button == 72)
            {
                y -= 1;
                if (y < 3)
                {
                    y = 6;
                }
            }

            gotoxy(0, y);
            std::cout << '>';
        } while (button != 27 && button != 13 && button != 32);

        gotoxy(0, 8);

        if (button == 27)
        {
            std::cout << "Bye!";
            return -1;
        }
        short n;
        long long divider;
        short number_of_digits = 0;
        short sum = 0;
        short arithmetical_mean = 0;
        short number_of_zeros = 0;
        divider = 1;

        while (divider <= number)
        {
            divider *= 10;
        }
        while (divider > 1)
        {
            divider /= 10;
            n = number / divider;

            sum += n;
            number_of_digits += 1;
            if (n == 0)
            {
                number_of_zeros += 1;
            }
            arithmetical_mean = sum / number_of_digits;

            number -= n * divider;
        }
        switch (y)
        {
        case 3:
            std::cout << "The number of digits: " << number_of_digits;
            break;
        case 4:
            std::cout << "Sum: " << sum;
            break;
        case 5:
            std::cout << "Arithmetical mean of digit: " << arithmetical_mean;
            break;
        case 6:
            std::cout << "The number of zeros in a number: " << number_of_zeros;
            break;

        }
        std::cout << std::endl;

        system("PAUSE");

    } while (true);

    return 0;
}

int main2() {
    std::cout 
        << " -=Menu=-" << std::endl
        << "  Item 1" << std::endl
        << "  Item 2" << std::endl
        << "  Item 3" << std::endl;

    gotoxy(0, 1);      // переводим курсор на позицию "0" в строке "1" (вторая строка)
    std::cout << ">";  // ">" выведено перед "Item 1"
    short y = 1;       // координата курсора
    char c;
    do {                              // Блок управления меню
        c = _getch();                 // Считываем кнопку
        if (c == 0 || c == -32) {     // Стрелки сначала посылают -32,
            c = _getch();             //  поэтому считываем еще раз
        }
        // стираем "стрелку" в старой позиции
        gotoxy(0, y); std::cout << ' ';  // выводим пробел ' '

        // меняем координату "у" (в зависимости он нажатой кнопки)
        if (c == 80) {  // кнопка "вниз"
            y += 1;     // ось "у" на консоли перевернута - увеличивается вниз
            if (y >= 4) {
                y = 1;
            }
        }
        if (c == 72) {  // кнопка "вверх"
            y -= 1;
            if (y < 1) {
                y = 3;
            }
        }
        // рисуем стрелку в новой позиции
        gotoxy(0, y); std::cout << '>';

    } while (c != 27 && c != 32 && c != 13);  // 13 - Enter, 27 - ESC, 32 - Space
    
    gotoxy(0, 5);  // переводим курсор за меню (иначе новый вывод идет по нему)
    
    // После выхода из цикла у нас два варианта:
    // либо отмена (ESC), либо подтверждение (Enter или Space)
    if (c == 27) {  // это отмена
        std::cout << "Bye-bye";
        return 27;  // использование return позволяет не писать else
    }
    // else - не пишем, т.к. заход в if приведет к return - выходу из программы

    std::cout                  // Меню организовано таким образом,
        << "You select Item "  // что на строке с у=0 выводится "меню"
        << y                   // а дальше у=1 -- item 1, у=2 -- item 2, ...
        << std::endl;          // Поэтому значение "у" совпадает с номером выбора

    // Анализируем выбор меню 
    switch (y) {
    case 1:  // первый пункт меню: рисуем квадрат из "*"
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {  // вложенный цикл
                _putch('*');   // put char - самый простой вывод символа
            }
            std::cout << std::endl;
        }
        break;
    case 2:
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < i + 1; ++j) {  // внутренний цикл может зависеть от внешнего
                _putch('*');   
            }
            std::cout << std::endl; //  __*__
        }                           //  _***_
        break;                      //  *****
    case 3:  // rhomb <>            //  _***_
    {                               //  __*__
        // Лучше если позиции - нечетное число, выберем 5
        int n = 5;
        // верхняя часть
        for (int i = 0; i <= n / 2; ++i) {  // строки
            int spaces = n / 2 - i, stars = 1 + 2 * i;
            // пробелы
            for (int j = 0; j < spaces; ++j) {
                _putch(' ');
            }
            // ***
            for (int j = 0; j < stars; ++j) {
                _putch('*');
            }
            // пробелы (не выводим, и так пусто)
            // перевод строки
            std::cout << std::endl;
        }
        // нижняя часть
        for (int i = n/2 - 1; i >= 0; --i) {     // строки
            int spaces = n / 2 - i, stars = 1 + 2 * i;            
            for (int j = 0; j < spaces; ++j) {  // пробелы
                _putch(' ');
            }            
            for (int j = 0; j < stars; ++j) {   // ***
                _putch('*');
            }
            std::cout << std::endl;
        }
        break;
    }
    }
    return 0;
}

int main1()
{
    std::cout << "Press a key\n";
    char c;
    do {
        c = _getch();   // get char - сразу срабатывает при нажатии клавиши
        if(c == 0 || c == -32) c = _getch();
        std::cout << "Symbol: '" << c << "' code: " << (int)c << std::endl;
    } while (c != 27);  // 27 - ESC

    return 0;
}

/* О клавиатуре:
*  _getch() считывает один символ с клавиатуры, но на некоторые клавиши
* он принимает два значения, например, функциональные кнопки F1, F2
* сначала посылают "0" потом свой код. Кнопки управления курсором 
* - сначала -32 (224), потом свой код.
* Для работы с меню обычно используют стрелки, для них нужно помнить, что
* приходят парные значения.
* 
* left   75
* right  77
* up     72
* down   80
*/