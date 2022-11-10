#include <iostream>
#include <string>
#include <cmath>  // sqrt - корень квадратный

int main() {
    // условие задачи переносим в константы
    const float SQUARE_X_LEFT   = -4;  // координата Х левой стороны квадрата
    const float SQUARE_X_RIGHT  = -1;
    const float SQUARE_Y_TOP    = 4;
    const float SQUARE_Y_BOTTOM = 1;

    float x, y;

    std::cout << "Enter point (x,y): ";
    std::cin >> x >> y;
    // A квадрат
    // точка внутри квадрата если 
    // X_LEFT < x < X_RIGHT   И   Y_TOP < y < Y_BOTTOM
    /* DRY - Don't Repeat Yourself - замечание к оформлению кода
           - наличие повторяющихся фрагментов кода
        Рекомендация - выносить одинаковые части, а в условиях
        добавлять только то, что меняется
    if (SQUARE_X_LEFT < x && x < SQUARE_X_RIGHT
     && SQUARE_Y_TOP  < y && y < SQUARE_Y_BOTTOM) 
    {
        std::cout << "Point (" << x << "," << y << ") "
            << "Inside square A";
    }
    else {
        std::cout << "Point (" << x << "," << y << ") "
            << "Outside square A";
    }*/
    // переменная для формирования вывода (сообщения)
    std::string message;
    // Общая начальная часть
    message = "Point (" + std::to_string(x) 
        + "," + std::to_string(y) + ") ";

    if (SQUARE_X_LEFT < x && x < SQUARE_X_RIGHT
     && SQUARE_Y_BOTTOM < y && y < SQUARE_Y_TOP)
    {
        message += "inside";  // отличающаяся часть
    }
    else {
        message += "outside";  // message = message + ".."
    }
    // общее окончание сообщения
    message += " square A";
    // вывод сообщения на экран
    std::cout << message << std::endl;

    // B Circle
    const float CIRCLE_CENTER_X = 2;
    const float CIRCLE_CENTER_Y = 2;
    const float CIRCLE_RADIUS   = 2;

    // точка внутри круга если расстояние до его центра 
    // меньше радиуса (можно в квадрате)
    // расстояние до центра от точки:
    float x_to_center = sqrt(   // корень кв. (<cmath>)
        (CIRCLE_CENTER_X - x) * (CIRCLE_CENTER_X - x)
        + (CIRCLE_CENTER_Y - y) * (CIRCLE_CENTER_Y - y)
    );
    // Для сообщения берем ту же переменную, она уже свободна
    message = "Point (" + std::to_string(x)
        + "," + std::to_string(y) + ") ";  // общая часть

    // Отдельные части - по тернарному выражению
    message += (x_to_center < CIRCLE_RADIUS)
                ? "inside"
                : "outside";
    // Общее окончание
    message += " circle B";
    // вывод сообщения на экран
    std::cout << message << std::endl;

    // RECTANGLE C


    return 0;
}

int main4() {
    long double x;  // 80 bit
    std::cout << "Enter x = ";
    std::cin >> x;
    int r = (int)x;
    if (x > r) r += 1;  // r = r + 1 -- сокращенная форма
    std::cout << "Ceiling = " << r;
    return 0;
}

int main3() {
    float n;

    std::cout << "Enter number: " << std::endl;
    std::cin >> n;

    std::string type =
        (n == 0) 
        ? "zero" 
        : ( (n > 0) 
            ? "positive" 
            : "negative" ) ;

    std::cout << n << " is " << type << " number.";


    return 0;
}

int main2() {
    // тернарный оператор (выражение)
    // х = (условие) ? знач1 : знач2 ;
    // если условие +, то возвращается знач1, иначе - знач2
    // аналог ф. Excel  =ЕСЛИ(усл;знач1;знач2)
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;
    // std::string type = ((n % 2) == 0) ? "Even" : "Odd";
    
    // std::cout << n << " is " << type << " number";
    std::cout << n << " is " << (((n % 2) == 0) ? "Even" : "Odd") << " number";

    return 0;
}

int main1()
{
    // Вводится 5 чисел, нужно найти минимальное
    // Анализ: ввести числа и сравнивать каждое с каждым
    //  неэффективно. Программа большая и плохо расширяется
    int n, min;
    // т.к. задача сохранить числа не ставится, используем
    // одну переменную и будем "стирать" старое значение

    std::cout << "Value 1: ";
    std::cin >> n;
    min = n;  // если элемент один, то он и МАКС и МИН

    std::cout << "Value 2: ";
    std::cin >> n;  // в ту же переменную
    if (n < min) min = n;   // заменяем хранимое значение, если
                            // введенное оказалось меньшим
    std::cout << "Value 3: ";
    std::cin >> n;
    if (n < min) min = n;

    std::cout << "Value 4: ";
    std::cin >> n;
    if (n < min) min = n;

    std::cout << "Value 5: ";
    std::cin >> n;
    if (n < min) min = n;

    std::cout << " Min value: " << min;

    return 0;
}

/*
Экспоненциальная форма представления чисел
Применяется для дробных чисел:
 для удобства представления как малых (0.0000000001),
 так и больших (100000000000) чисел в единой форме
Число разбивается на 
 Мантису (М) - "цифры" - запись, при которой точка стоит
   после первой цифры, 1 < M < 9
 Экспоненту - степень числа 10, "перенос точки" - множитель,
   который из мантисы делает нужное число
Например,
0.00123  --> M = 1.23,  E = -3  (10 ^ -3)
345000   --> M = 3.45,  E = 5
5.67     --> M = 5.67,  E = 0
double x = 1.23e-3; 
Удобно для записи больших/малых чисел
0.0000000001  1e-10
*/
