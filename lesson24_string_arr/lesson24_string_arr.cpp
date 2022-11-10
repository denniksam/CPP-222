#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "colors.h"

size_t N = 10;        // максимальное кол-во ячеек-записей в книге
char*** phonebook;    // указатель на ресурс книги

void print_phonebook() {
    std::cout << "No\tFIO\t\tTel\n";  // "шапка" таблицы

    for (size_t i = 0; i < N; i++) {
        std::cout << (i + 1) << '\t';

        if (NULL == phonebook[i][0]) {  // нет данных ФИО
            std::cout << "--\t\t";
        }
        else {  // есть данные
            // оформление: при коротких именах съезжает тлф.
            //  задача: при длине ФИО менее 8 символов - добавлять 2 \t
            std::cout << phonebook[i][0] << '\t';
            if (strlen(phonebook[i][0]) < 8) std::cout << '\t';
        }

        if (phonebook[i][1] == NULL) {  // нет данных тлф
            std::cout << "--";
        }
        else {  // есть данные
            std::cout << phonebook[i][1];
        }

        std::cout << std::endl;
    }
}

bool add_phone(const char* name, const char* phone) {
    if (name == NULL || phone == NULL) {
        std::cout << colors::RED_BRIGHT << "NULL-argument in add_phone()"
            << colors::RESET << std::endl;
        return false;
    }
    size_t i = 0;
    while (i < N && phonebook[i][0] != NULL) {
        ++i;
    }    
    if (i == N) {  // i == N - книга заполнена (нет пустых)
        return false;
    }

    // phonebook[0][0] = (char*) name; - "псевдоним" - второй указатель на те же данные
    // правильно - копировать, выделить новую память и перенести данные
    phonebook[i][0] = new char[strlen(name) + 1];
    strcpy(phonebook[i][0], name);
    phonebook[i][1] = new char[strlen(phone) + 1];
    strcpy(phonebook[i][1], phone);

    return true;
}

void fill_demo() {
    add_phone("Petrovich",  "22332");
    add_phone("Pavlovna",   "322223");
    add_phone("Efimovich",  "555442");
    add_phone("Vasiliy",    "546325");
    add_phone("Andreevich", "919234");
    add_phone("Arestovich", "165874"); 
    add_phone("LaAntonio",  "699422");
    add_phone("Zelenskiy",  "228578");
    add_phone("Xao",        "428578");
}

bool input_phone() {
    const size_t BUF_SIZE = 100;
    char* name  = new char[BUF_SIZE];
    char* phone = new char[BUF_SIZE];
    std::cout << "Name: ";
    std::cin.getline(name, BUF_SIZE);
    std::cout << "Phone: ";
    std::cin  >> phone;
    bool res = add_phone(name, phone);
    delete[] name;
    delete[] phone;
    return res; 
}

void search_by_name() {
    const size_t BUF_SIZE = 100;
    char* name = new char[BUF_SIZE];
    std::cout << "Name: ";
    std::cin.getline(name, BUF_SIZE);

    for (size_t i = 0; i < N; ++i) {
        if (phonebook[i][0] != NULL) {
            if (_stricmp(phonebook[i][0], name) == 0) {
                std::cout << (i + 1) << " " << phonebook[i][0] << " "
                    << phonebook[i][1] << std::endl;
            }
        }
    }
    /*
    * Проект "телефонная книга"
    * Поиск по имени: добавить итоговую информацию (найдено Х записей)
    * ** Реализовать частичный поиск (по подстроке "petr" -> "Petrovich", "Petro")
    * Реализовать поиск по номеру тлф.
    */

    delete[] name;
}

void order_by_name() {
    // принцип сортировки - сравниваем соседние эл-ты и при необходимости переставляем
    // особенности: сравнение строк не такое же, как у чисел; обмен значениями - как указатели
    bool need_restart;
    do {
        need_restart = false;
        for (size_t i = 0; i < N - 1; i++) {
            // сравнить phonebook[i][0] и phonebook[i+1][0]
            if (phonebook[i][0] != NULL && phonebook[i + 1][0] != NULL) {
                if (strcmp(phonebook[i][0], phonebook[i + 1][0]) == 1) {
                    // порядок неправильный, нужно переставить ячейки [i] и [i+1]
                    // 
                    // [i] --> "WWW"    [i] --> "CC"      [i]              / "WWW"
                    // [i+1] --> "CC"   [i+1] --> "WWW"      \ "CC"   [i+1] 
                    //
                    char* tmp_ptr = phonebook[i][0];        //  "WWW"
                    phonebook[i][0] = phonebook[i + 1][0];  //   \ "CC"
                    phonebook[i + 1][0] = tmp_ptr;          //  / "WWW"
                    // синхронно с именами нужно менять телефоны
                    tmp_ptr = phonebook[i][1];
                    phonebook[i][1] = phonebook[i + 1][1];
                    phonebook[i + 1][1] = tmp_ptr;

                    need_restart = true;  // были изменения - нужно перезапустить
                }
            }
        }
    } while (need_restart);
    print_phonebook();
}

void order_by_phone() {
    bool need_restart;
    do {
        need_restart = false;
        for (size_t i = 0; i < N - 1; i++) {
            // сравнить  phonebook[i][1] и  phonebook[i+1][1]
            if (phonebook[i][1] != NULL && phonebook[i + 1][1] != NULL) {
                if (strcmp(phonebook[i][1], phonebook[i + 1][1]) == 1) {
                    char* tmp_ptr = phonebook[i][1];
                    phonebook[i][1] = phonebook[i + 1][1];
                    phonebook[i + 1][1] = tmp_ptr;
                    tmp_ptr = phonebook[i][0];
                    phonebook[i][0] = phonebook[i + 1][0];
                    phonebook[i + 1][0] = tmp_ptr;
                    need_restart = true;  // были изменения - нужно перезапустить
                }
            }
        }
    } while (need_restart);
    print_phonebook();
}

bool delete_record() {
    // удаление ячейки (записи в книге): 
    // исключение данных из ячейки (кол-во ячеек в книге не меняется)
    // + перемещение ячеек на освобожденные позиции (не должно быть пропусков)
    // 1. Запрашиваем у пользователя номер удаляемой ячейки, проверяем валидность
    char user_choice[10];
    int index;
    do {
        std::cout << "Enter record number: ";
        std::cin.getline(user_choice, 10);
        index = atoi(user_choice);  // ASCII - to - int
        if (index <= 0 || index > N) {
            std::cout << "Invalid choice. Use 1 - " << N << " numbers" << std::endl;
            index = 0;
        }
    } while (index == 0);
    // 2. По выходу из цикла  1 <= index <= N. Проверяем есть ли данные в ячейке
    int i = index - 1;
    if (phonebook[i][0] == NULL) {  // ячейка не заполнена
        std::cout << "Empty record selected - delete cancelled" << std::endl;
        return false;
    }
    else {  // есть данные - подтверждаем удаление
        std::cout << "Are you sure (delete "
            << phonebook[i][0] << " " << phonebook[i][1]
            << ") Y/... ";
        std::cin.getline(user_choice, 10);
        // проверить что ввод y или Y
        if (_stricmp(user_choice, "y") == 0) {  // удаление подтверждено
            // удаление = смещение последующих ячеек на данное место
            delete[] phonebook[i][0];  // освобождаем память 
            delete[] phonebook[i][1];  // выделенную для хранения данных
            for (size_t j = i; j < N-1; j++) {
                phonebook[j][0] = phonebook[j + 1][0];   // ФИО
                phonebook[j][1] = phonebook[j + 1][1];   // Тлф
            }
            phonebook[N - 1][0] = NULL;  // последняя ячейка смещена на предпоследнюю
            phonebook[N - 1][1] = NULL;  // а для последней - значение NULL
            return true;
        }
        else {
            std::cout << "Delete cancelled by user" << std::endl;
            return false;
        }
    }
    // std::cout << index << std::endl;
    

    return true;
}

int main()
{
    phonebook = new char** [N];  // первый уровень - ячейки 
    for (size_t i = 0; i < N; i++) {
        phonebook[i] = new char* [2];  // 2й - [ФИО][тлф]
        phonebook[i][0] = NULL;  // признак пустой
        phonebook[i][1] = NULL;  // (свободной) ячейки
    }

    std::cout << colors::BLUE_BOLD_BRIGHT
        << "Phonebook!"
        << colors::PURPLE_BOLD_BRIGHT
        << "  v0.4 \n"
        << colors::RESET;

    fill_demo();

    
    char user_choice[10];
    // int userChoice;          - приводит к ошибкам
    // std::cin >> userChoice;    если вводится не число
    do {
        std::cout
            << "1. Show all phones\n"
            << "2. Add phone\n"
            << "3. Search by name\n"
            << "4. Order by name\n"
            << "5. Order by phone\n"
            << "6. Delete record\n"
            << "0. Exit\n";
        std::cout << "Make a choice: ";

        // если от предыдущих итераций остался символ \n, то стираем его
        if( std::cin.peek() == '\n') std::cin.get();

        std::cin.getline(user_choice, 10);  // используем для того чтобы исключить ошибки cin
        if (strlen(user_choice) != 1) {
            std::cout << colors::PURPLE << "Incorrect choice (only 1 digit)\n" << colors::RESET;
            continue;
        }
        switch (user_choice[0]) {
        case '1': 
            print_phonebook(); 
            break;

        case '2': 
            if (input_phone()) {
                std::cout << colors::GREEN << "Phone added\n" << colors::RESET;
            }
            else {
                std::cout << colors::YELLOW << "Phone adding error\n" << colors::RESET;
            }
            break;

        case '3': search_by_name(); break;
        case '4': order_by_name() ; break;
        case '5': order_by_phone(); break;
        case '6': if(delete_record()) print_phonebook(); break;
        case '0': break;
        default:
            std::cout << colors::PURPLE << "Incorrect choice (choose from menu)\n" << colors::RESET;
            continue;
        }
    } while (user_choice[0] != '0');

    return 0;
}
/*
   Многомерные массивы - массивы строк
   Проект: телефонный справочник
   Описание: программа должна хранить данные о имени (ФИО) и
    номере телефона. Предоставляется интерфейс для поиска и 
    добавления записей.
   Задача: сопоставить информацию о тлф. и имени, собирая массив
    записей.
    [ 
        [ФИО][тлф]
        [ФИО][тлф]  
        [ФИО][тлф]  
        ... (10 = N)
        [ФИО][тлф]   
    ]
    phonebook[10] { [Petrovich] [223322] }
    phonebook[10][0] - ФИО (char[] "Petrovich") phonebook[10][0][2] - 't'
    phonebook[10][1] - тлф (char[] "223322")
*/
