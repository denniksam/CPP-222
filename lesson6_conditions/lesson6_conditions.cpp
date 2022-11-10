
#include <iostream>

int main() {
    float x, y;  // операнды, вводимые пользователем
    char op;     // символ оператора

    std::cout << "Enter expression like 3 + 2: ";
    std::cin >> x >> op >> y;

    float res;   // дл€ хранени€ результата

    /*
    if (op == '+')      res = x + y;
    else if (op == '-') res = x - y;
    else if (op == '*') res = x * y;
    else if (op == '/') res = x / y;
    else {  // сюда мы попадаем если оператор другой
        std::cout << "Invalid operation";
        return -1;
    }
    */
    // оператор множественного выбора - switch
    switch (op) {
    case '+': res = x + y; break;
    case '-': res = x - y; break;
    case '*': res = x * y; break;
    case ':':   // принцип "проваливани€"
    case '/': res = x / y; break;
    case '%':   // остаток от делени€ - только дл€ целых
        if (x == (int)x && y == (int)y) {
            res = ((int)x) % ((int)y);
            break;
        }       // если if не сработает, то не будет break
                // а значит код "провалитс€" и пойдет дальше (в default)
    default:
        std::cout << "Invalid operation";
        return -1;
    }

    std::cout << x << " " << op << " " << y
        << " = " << res << std::endl;

    return 0;
}
/*
    «адание: калькул€тор
    ѕользователь вводит выражение из одной операции,
    например, 3 + 2
    ƒопускаютс€ операции + - * /    %
    ѕрограмма выводит результат вычислени€
*/

int main1()
{
    unsigned int products_cnt;     // беззнаковый, т.к. 
    // отрицательного кол-ва быть не может

    unsigned short prod_per_page;  // предполагаем, 
    // что на странице не будет больше чем 65к товаров

    unsigned int pages;

    std::cout << "Enter products count and page capacity ";
    std::cin >> products_cnt >> prod_per_page;

    pages = products_cnt / prod_per_page;  // остаток
    // игнорируетс€ - это целочисленное деление

    // Ќќ! если остаток есть, то он формирует +1 страницу
    if (products_cnt % prod_per_page != 0) {
        ++pages;
    }
    std::cout << "Pages count: " << pages;

    return 0;
}

/*
   ”слови€. ѕродолжение
   «адание (пагинаци€): 
   ƒано (вводит пользователь)
    - кол-во товаров
    - кол-во товаров на одной странице
   Ќайти (вывести)
    - общее кол-во страниц
    Ќапример, 
    товаров   на странице   страниц
      20          5            4
      20          10           2
      20          6            4
      20          7            3
*/
