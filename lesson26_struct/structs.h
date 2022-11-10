#pragma once

struct {           // структура без имени
    short day;     // 
    short month;   // поля структуры (day, month, year)
    int   year;    // 
} date;            // объект структуры (переменная)

struct Vector {    // Именованная структура
    float x;       // Ее имя (Vector) становится типом
    float y;       // данных и может использоваться
};                 // для объявления объектов

Vector zero_vector();  // прототип функции: она определяется в structs.cpp,
                       // а вызывается в main()  (lesson26...cpp)
Vector  add_vector(const Vector&, const Vector&);
Vector* add_vector(const Vector*, const Vector*);
void print_vector(const Vector& );
void print_vector(const Vector* );

/*
    Заголовочный (header) файл - используется для того чтобы во всех
    файлах проекта были видны объявления (типы, прототипы, константы...)

    Они позволяют разделять код проекта не несколько файлов и не 
    заботиться о видимости функций между ними
*/