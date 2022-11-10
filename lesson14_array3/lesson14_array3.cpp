#include <iostream>
#include <iomanip>
#include <time.h>

int main()
{
    const size_t MONTH = 12;
    const size_t PRODS = 3;

    std::string month_names[MONTH] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    std::string prod_names[PRODS] = {
        "Buckwheat", "Cucumbers", "Potato"
    };
    float sales[MONTH][PRODS];

    srand(time(NULL));
    for (size_t i = 0; i < MONTH; ++i) {
        for (size_t j = 0; j < PRODS; j++) {
            sales[i][j] = (float)(rand() % 2000) / 100;
        }
    }

    std::cout << "Monthly stat:\n";
    std::cout << "     ";
    for (size_t j = 0; j < PRODS; j++) {
        std::cout << std::setw(10) << prod_names[j];
    }
    std::cout << std::endl;
    for (size_t i = 0; i < MONTH; ++i) {
        std::cout << month_names[i] << "  ";
        for (size_t j = 0; j < PRODS; j++) {
            std::cout << std::setw(10) << sales[i][j] ;
        }
        std::cout << std::endl;
    }

    // 1. Найкращий продаж: який товар у якому місяці було продано на
    //  найбільшу суму.
    float  max_sale;             // змінна для найкращої продажі;
    size_t max_month = 0,        // для збереження місяцю та товару у ній
           max_prod  = 0;
    max_sale = sales[max_month][max_prod];
    for (size_t i = 0; i < MONTH; ++i) {
        for (size_t j = 0; j < PRODS; j++) {
            if (sales[i][j] > max_sale) {
                max_sale  = sales[i][j];
                max_month = i;
                max_prod  = j;
            }
        }
    }
    std::cout << "The best sale " << max_sale << " hrn: month - "
        << month_names[max_month] << ", product - "
        << prod_names[max_prod] << std::endl;

    // 2. Те ж саме, але найгірший - самостійно

    // 3. Вивести: назва товару - місяць з найкращим продажем
    for (size_t j = 0; j < PRODS; j++) {
        max_month = 0;
        max_sale = sales[max_month][j];
        for (size_t i = 0; i < MONTH; ++i) {
            if (sales[i][j] > max_sale) {
                max_sale = sales[i][j];
                max_month = i;
            }
        }
        std::cout << prod_names[j] << " have the best sale in " <<
            month_names[max_month] << std::endl;
    }

    // 4. Вивести: назва місяця - товар з найгіршим продажем - самостійно

    // 5. Користувач вводить два числа - місяць початку та кінця 
    //  звітності. Вивести дані продажів за звітний період.
    //  Користувач може ввести як 3 7, так і 7 3 - обробляємо обидва випадки
    //  якщо номер місяця неправильний - видаємо повідомлення про помилку
    long long m1, m2;    // змінні для звітних місяців. Вжито знаковий тип
                         // з метою оброблення від'ємних даних
    std::cout << "Enter two monthes: ";
    std::cin >> m1 >> m2;
    // Вважаємо, що користувач вводить значення від 1 до 12
    if (m1 > 12 || m1 < 1) {
        std::cout << "Error: illegal value for m1";
        return -1;
    }
    if (m2 > 12 || m2 < 1) {
        std::cout << "Error: illegal value for m2";
        return -2;
    }
    if (m2 < m1) {   // кінцевий місяц менший за початковий - міняємо їх місцями
        long long tmp = m2;
        m2 = m1;
        m1 = tmp;
    }
    // після перевірок ми впевнені у тому, що m1 <= m2 та їх значення від 1 до 12
    std::cout << "     ";
    for (size_t j = 0; j < PRODS; j++) {
        std::cout << std::setw(10) << prod_names[j];
    }
    std::cout << std::endl;
    for (size_t i = m1 - 1; i < m2; ++i) {
        std::cout << month_names[i] << "  ";
        for (size_t j = 0; j < PRODS; j++) {
            std::cout << std::setw(10) << sales[i][j];
        }
        std::cout << std::endl;
    }
}

/*
    Річна статистика: 12 місяців, та декілька товарів:
    гречка, огірки, бульба

    Циклічний зсув
  5  1 2 3 4 5 -> (праворуч) -|
  |<--------------------------|

     12345    2->
     00123   45
     45123
*/