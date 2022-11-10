#include <iostream>
#include "structs.h"

Vector zero_vector() {
    Vector ret;
    ret.x = ret.y = 0;
    return ret;
}

Vector add_vector(const Vector &a, const Vector &b) {
    Vector ret;    
    ret.x = a.x + b.x;
    ret.y = a.y + b.y;
    return ret;
}
Vector* add_vector(const Vector* pa, const Vector* pb) {
    if (pa == NULL || pb == NULL) {
        std::cout << "add_vector: argument NULL" << std::endl;
        return NULL;
    }
    Vector *ret = new Vector;
    ret->x = pa->x + pb->x;
    ret->y = pa->y + pb->y;
    return ret;
}

void print_vector(const Vector& a) {
    std::cout << "(" << a.x << ";" << a.y << ")\n";
}

void print_vector(const Vector* pa) {
    std::cout << "(" << pa->x << ";" << pa->y << ")\n";
}

/*
    Функции и передача структур-параметров
    [ret] add_vector(a,b) {
           ..... return ret;
    Особенностью работы функций со структурами является создание их копий
    при приеме параметров
     add_vector(Vector a, Vector b)
     add(v1,v2) :  v1 - копируется в a,  v2 -- b
    Используется технология - передачи по ссылке (по псевдониму)
     перед именем параметра добавляется &
     add_vector(Vector &a, Vector &b)
     происходит "связывание" переменных вызова (v1,v2)  и параметров
     функции (a,b). Это выгодно тем, что не создаются копии, однако
     опасно тем, что изменения (a,b) в теле функции отразятся на 
     переменных (v1,v2) - это называется побочным эффектом функции
      (function side effect)
     Для "защиты" связанных данных от случайного изменения перед ссылками
     добавляют const 
     Альтернатива - использование указателей
*/
