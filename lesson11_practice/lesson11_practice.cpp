#include <Windows.h>
#include <conio.h>
#include <iostream>

#define gotoxy(x,y)   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y })

int main() {
    short display_y = 0;                 // строка для отображения статистики
    short target_y  = 1;                 // строка, по которой движется цель
    short gates_y   = 2;                 // строка с "воротами"
    short gates_x   = 38;
    short gates_w   = 3;                 // ширина ворот

    short x  = 0;
    short dx = 1;
    char  c  = 2;                        // 1,2 - smiley, 3 - heart
    int   score = 0;                     // начальный счет

    gotoxy(0, display_y);
    std::cout << score;

    gotoxy(gates_x, gates_y);            // "ворота" - 
    std::cout << '[';                    // левый символ [
    for (short i = 0; i < gates_w; i++)  // пробелы в количестве gates_w
        std::cout << ' ';                // 
    std::cout << ']';                    // правый символ ]

    while (true) {                       // игровой бесконечный цикл
        gotoxy(x, target_y); 
        std::cout << ' ';                // стираем старое положение
        x += dx;                         // сдвигаем координату
        gotoxy(x, target_y); 
        std::cout << c;                  // отображаем в новом положении
                              
        if (_kbhit()) {                  // keyboard hit - нажатие кнопки клавиатуры
            char kb = _getch();          // если кнопка нажата - считываем
            if (kb == 0 || kb == -32) {  // специальная кнопка посылает два символа
                kb = _getch();           // считываем второй из них
            }
            if (kb == 27) {              // ESC
                break;                   // остановка цикла - выход
            }
            if (kb == 32) {              // Space (нажат пробел)
                if (x > gates_x          // Попал в ворота
                 && x <= gates_x + gates_w ) {
                    ++score;             // увеличиваем счет
                }
                else {                   // пробел нажат, но не попал
                    --score;             // уменьшаем счет
                }
                gotoxy(0, display_y);    // В любом случае после нажатия пробела
                std::cout << score       // Отображаем новый счет и
                    << "  ";             //  несколько дополнительных пробелов, чтобы стереть старое
                Sleep(1000);             // И делаем паузу 
            }
            if (kb == 'g') {             // скрытая возможность расширить ворота
                ++gates_w;

                gotoxy(gates_x, gates_y);            
                std::cout << '[';                                // [   ]
                for (short i = 0; i < gates_w; i++)              // [  ]
                    std::cout << ' ';                            //     __
                std::cout << ']';                                // [  ]]
            }

        }

        if (x == 80 || x == 0) dx = -dx;
        
        Sleep(100);                      // пауза 100 мс (10 fps)
    }

    gotoxy(0, 5);  // сдвиг вниз сообщения об окончании программы
    return 0;
    // задача: если х достигает 80, то движение идет в обратную сторону до 0, потом обратно
}

int main1()
{
    // задание: вывести четные числа в некотором диапазоне
    for (size_t i = 0; i < 20; i++)
    {                            // В С++, для совместимости с С тип bool может быть заменен
        if (i % 2) continue;     // (i % 2) - 0 либо 1, при анализе как условия, это false и true
        std::cout << i << "\n";  // Если число четное, то остаток - 0 и это воспринимается как false
    }                            // Нечетное - 1 (true), выполняется continue -> новая итерация (вывод пропускается)
    
    // выводить 0 пока пользователь не нажмет любую клавишу
    while (true) {       // бесконечный цикл
        std::cout << 0;
        if (_kbhit()) {  // keyboard hit - нажатие кнопки клавиатуры
            break;       // остановка цикла - выход
        }
    }

    return 0;
}

/* Операторы управления циклом
    continue - переход к следующей итерации
    break - прекращение цикла. Популярное применение - бесконечный цикл с условием выхода

    тело цикла     
    опер1      |    ^
    опер2      |    |
    continue   v -->    break |
    опер3                     |
                              v
*/