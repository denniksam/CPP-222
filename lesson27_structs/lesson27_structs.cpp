#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

enum struct data_type {
    PHONE,
    EMAIL
};

struct phonebook_cell {   // ячейка телефонной книги
    char name[32];        // имя в любом случае
    union {               // Объединение  - выбор одного из
        char email[32];   // либо почта
        long long phone;  // либо тлф
    } data;               // 
    data_type cell_type;  // Перечисление - указывает какой тип реализован
};

std::ostream& operator <<(std::ostream& os, const phonebook_cell* cell) {
    os << cell->name << " ";
    switch (cell->cell_type) {
    case data_type::PHONE: os << cell->data.phone; break;
    case data_type::EMAIL: os << cell->data.email; break;
    }
    return os;
}

void fill_phone(phonebook_cell* cell, const char* str, long long phone) {
    if( cell != NULL && str != NULL ) {
        strcpy(cell->name, str);
        cell->data.phone = phone;
        cell->cell_type = data_type::PHONE;
    }
}
void fill_email(phonebook_cell* cell, const char* name, const char* email) {
    // if (cell != NULL && name != NULL && email != NULL ) 
    if( cell && name && email ) {
        strcpy(cell->data.email, email);
        strcpy(cell->name, name);
        cell->cell_type = data_type::EMAIL;
    }
}

int main() {
    auto *cell1 = new phonebook_cell;
    fill_phone(cell1, "Petrovich", 233322);
    std::cout << cell1 << std::endl;

    auto* cell2 = new phonebook_cell;
    fill_email(cell2, "Markovna", "mar@ukr.net");
    std::cout << cell2 << std::endl;

    return 0;
}



union int32 {                 // value    bytes            byte[]
    int value;                // 32b      32(суммарно)     32(суммарно)
    struct {                  // 
        unsigned char b1;     // [8]      b1   [8]         [0]   [8]
        unsigned char b2;     // [8]      b2   [8]         [2]   [8]
        unsigned char b3;     // [8]      b3   [8]         [3]   [8]
        unsigned char b4;     // [8]      b4   [8]         [4]   [8]
    } bytes;                  // 
    unsigned char byte[4];
    short shorts[2];
};                           

int main3() {
    int32 x;
    x.value = 0x12345678;
    std::cout << std::hex << x.value << std::endl
        << (int) x.bytes.b1 << " "
        << (int) x.bytes.b2 << " "
        << (int) x.bytes.b3 << " "
        << (int) x.bytes.b4 << std::endl;

    std::cout << std::hex << x.value << std::endl
        << (int)x.byte[0] << " "
        << (int)x.byte[1] << " "
        << (int)x.byte[2] << " "
        << (int)x.byte[3] << std::endl;

    std::cout << std::hex << x.value << std::endl
        << x.shorts[0] << " "
        << x.shorts[1] << std::endl;

    std::cout << ((x.value & 0x00FFF000) >> 12) ;

    return 0;
}


union age_t {  // "информация" о возрасте
    short year;          // 16 бит
    unsigned char age;   // 8 бит
    unsigned short uyear;
};                    // всего - 16 бит (по бОльшему)

int main2() {
    age_t mr_x;        // - year -   --  Реально в памяти
    mr_x.year = 1988;  // [ 07 c4 ]  --  [ c4 07 ]
                       //     -age-  --  BE (BigEndian) - В памяти младший байт выше
    std::cout << mr_x.year << "  " << (int)mr_x.age << std::endl;
    std::cout << std::hex << mr_x.year << "  " << (int)mr_x.age << std::endl;
    
    mr_x.year = 0;
    mr_x.age = 37;  // 0x25
    std::cout << std::dec << mr_x.year << "  " << (int)mr_x.age << std::endl;
    std::cout << std::hex << mr_x.year << "  " << (int)mr_x.age << std::endl;
    std::cout << "--------------------------------------------\n";
    std::cout << std::dec << &mr_x.year << " " << (void*) & mr_x.age << std::endl;
    return 0;  
}




enum unit_t {  // простое перечисление - создает константы
    BYTE,      // 0
    KBYTE,     // 1
    MBYTE      // 2 
};
enum struct timeunit_t {  // именованные (scoped) перечисления
    SECOND = 1,
    MINUTE = 60,
    HOUR = 3600
};
enum { DEVELOP, RELEASE };  // анонимное перечисление - создание констант
const int MODE = DEVELOP;

int main1()
{
    unit_t unit;
    unit = KBYTE;
    if(MODE == DEVELOP) std::cout << unit << std::endl;

    timeunit_t tunit = timeunit_t::MINUTE;
    switch (tunit) {
    case timeunit_t::SECOND: std::cout << "sec" << std::endl; break;
    case timeunit_t::MINUTE: std::cout << "min" << std::endl; break;
    case timeunit_t::HOUR: std::cout << "hour" << std::endl; break;
    }
    std::cout << (int)tunit << " " << sizeof(tunit) << std::endl;
    return 0;
}
/*
    Структуры. Объединения. Перечисления.
    Перечисления (enum) - конструкции, позволяющие создавать и
    ограничивать константы

    Объединения (union) - конструкции, создающие общую область
    для нескольких переменных (с "перекрытием")
*/
