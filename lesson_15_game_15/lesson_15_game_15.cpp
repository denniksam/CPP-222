// Пятнашки
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <time.h>

#define gotoxy(x,y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y })

int main()
{
    const short N = 4;
    short field[N][N];
    const char
        lt = (char)218,  // ┌   left-top-corner
        rt = (char)191,  // ┐   right-top-corner
        lb = (char)192,  // └   lef-bottom
        rb = (char)217,  // ┘   right-bottom
        hl = (char)196,  // ─   horizontal line
        vl = (char)179;  // │   vertical line
    char c;          // клавіша, що її натискає користувач
    short x, y;      // Циклові змінні - координати поля
    short x0, y0;    // координати порожної (нульової) комірки
    bool was_move;   // чи був зроблений хід
    bool game_over;  // чи кінець гри 

    // заповнюємо поле числами від 1 до 15, 0 - вкінці
    for (y = 0; y < N; ++y) {
        for (x = 0; x < N; ++x) {
            field[y][x] = y * N + x + 1;
        }
    }
    x0 = y0 = N - 1;
    field[y0][x0] = 0;

    // Перемішуємо поле - робимо декілька випадкових ходів
    srand(time(NULL));
    for (x = 0; x < 5; ++x) {
        switch (rand() % 4) {  // rand() % 4  - від 0 до 3 - випадковий хід
        case 0:    // up
            if (y0 < N - 1) {
                field[y0][x0] = field[y0 + 1][x0];
                y0 += 1;
                field[y0][x0] = 0;
            }
            break;
        case 1:    // left
            if (x0 < N - 1) {
                field[y0][x0] = field[y0][x0 + 1];
                x0 += 1;
                field[y0][x0] = 0;
            }
            break;
        case 2:    // right
            if (x0 > 0) {
                field[y0][x0] = field[y0][x0 - 1];
                x0 -= 1;
                field[y0][x0] = 0;
            }
            break;
        case 3:    // down
            if (y0 > 0) {
                field[y0][x0] = field[y0 - 1][x0];
                y0 -= 1;
                field[y0][x0] = 0;
            }
        }
    }

    was_move = false;
    do {   // Ігровий цикл
        gotoxy(0, 2);   // Виводимо поле у тому самому місці
        // Виводимо поле
        // ┌ ─ ─ ─ ─ ─ ┐
        std::cout << lt;
        for (x = 0; x < N; ++x) { std::cout << hl << hl << hl; }
        std::cout << hl << rt << std::endl;

        for (y = 0; y < N; ++y) {
            std::cout << vl;
            for (x = 0; x < N; ++x) {
                if (field[y][x] == 0) {
                    std::cout << std::setw(3) << "";
                }
                else {
                    std::cout << std::setw(3) << field[y][x];
                }
            }
            std::cout << " " << vl << std::endl;
        }
        // └ ─ ─ ─ ─ ─ ┘
        std::cout << lb;
        for (x = 0; x < N; ++x) { std::cout << hl << hl << hl; }
        std::cout << hl << rb << std::endl;

        // Після аналізу натисненої клавіші перевіряємо чи зроблено хід
        if (was_move) {
            // Тут перевіряємо чи кінець гри
            game_over = true;
            for (y = 0; y < N; ++y) {
                for (x = 0; x < N; ++x) {
                    if (field[y][x] != (y * N + x + 1) % (N * N))
                        game_over = false;
                }
            }
            if (game_over) break;
        }

        std::cout << "Make a move";
        c = _getch();
        if (c == -32 || c == 0 || c == 224) {
            c = _getch();
        }
        was_move = false;   // скидаємо ознаку зробленого кроку
        // std::cout << (int)c;
        switch (c) {
        case 72:    // up
            if (y0 < N - 1) {
                field[y0][x0] = field[y0 + 1][x0];
                y0 += 1;
                field[y0][x0] = 0;
                was_move = true;
            }
            else {  // крайня комірка - рух неможливий
                Beep(300, 300);
            }
            break;
        case 75:    // left
            if (x0 < N - 1) {  // хід дозволений
                field[y0][x0] = field[y0][x0 + 1];
                x0 += 1;
                field[y0][x0] = 0;
                was_move = true;
            }
            else {  // крайня комірка - рух ліворуч неможливий
                Beep(300, 300);
            }
            break;
        case 77:    // right
            if (x0 > 0) {
                field[y0][x0] = field[y0][x0 - 1];
                x0 -= 1;
                field[y0][x0] = 0;
                was_move = true;
            }
            else {  // крайня комірка - рух неможливий
                Beep(300, 300);
            }
            break;
        case 80:    // down
            if (y0 > 0) {
                field[y0][x0] = field[y0 - 1][x0];
                y0 -= 1;
                field[y0][x0] = 0;
                was_move = true;
            }
            else {  // рух неможливий
                Beep(300, 300);
            }
            break;
        case 27:    // ESC
            break;
        default:
            Beep(700, 300);   // Звук частотою 700 Гц, тривалістю 300 мс
        }
        
    } while (c != 27 );

    return 0;
}
