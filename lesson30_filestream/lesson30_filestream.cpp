#include <iostream>
#include <fstream>
#include <string>

int main() {
    // задание "цензор": в файле file.txt заменить все слова "in" на "**"
    const char readername[] = "file.txt";
    const char writername[] = "fole.txt";
    const char find[] = "in";
    const char replace[] = "**";
    const size_t MAX_STR = 256;

    char str[MAX_STR];
    std::ifstream reader;  
    std::ofstream writer;  

    reader.open(readername);
    if (!reader) {
        std::cout << "Reader " << readername << " open error";
        return -1;
    }
    writer.open(writername);
    if (!writer) {
        std::cout << "Writer " << writername << " open error";
        return -2;
    }
    // while (!reader.eof()) {  По словам работает хорошо - заменяет, но
    //     reader >> str;          не сохраняет форматирование - весь файл в одну строку
    //     if (strcmp(str, find) == 0) {
    //         writer << replace << " ";
    //     }
    //     else {
    //         writer << str << " ";
    //     }
    // }
    while (!reader.eof()) {
        reader.getline(str, MAX_STR);
        // задача сводится к замене слов в строке (было в предыдущих ДЗ)

        writer << str;
        if (!reader.eof()) {      // если это не последняя строка
            writer << std::endl;  // то добавить разрыв строки
        }
    }
    reader.close();
    writer.flush();
    writer.close();
    return 0;
}

int main3() {
    // задание: в файле file.txt все символы "i" заменить на "o". Сохранить в 
    //  новом файле fole.txt
    const char readername[] = "file.txt";
    const char writername[] = "fole.txt";
    const char find = 'i';
    const char replace = 'o';

    char c;                 // для чтения символа из файла
    std::ifstream reader;   // файловые переменные - для чтения
    std::ofstream writer;   // и записи рез-та замены

    reader.open(readername);
    if (!reader) {
        std::cout << "Reader " << readername << " open error";
        return -1;
    }
    writer.open(writername);
    if (!writer) {
        std::cout << "Writer " << writername << " open error";
        return -2;
    }
    c = reader.get();            // читаем символ из файла (reader >> c) пропускает
    while (!reader.eof()) {      //   пробелы, разрывы и т.п.
        if (c == find) {         // если символ - заменный, то в файл пишем
            writer << replace;   //   другой символ
        }                        // иначе - тот же, что и считали
        else {                   // 
            writer << c;         // !! особенность при чтении по одному символу:
        }                        //    конец файла определяется по ошибке чтения
        c = reader.get();        //    поэтому циклическое пере-чтение находится
    }                            //    в конце цикла (а первое вынесено за цикл)
    reader.close();
    writer.flush();
    writer.close();

    return 0;
}

int main2() {
    // задание: найти самую длинную строку в файле file.txt, вывести ее
    const size_t MAX_STR = 256;            // Максимальная длина строки
    char str[MAX_STR];                     // буфер 1 (для строки из файла)
    char max_str[MAX_STR];                 // буфер 2 (для хранения максимальной)
    const char filename[] = "file.txt";    // имя файла
                                           // 
    size_t max_length = 0;                 // переменная для максимальной длины
    std::ifstream reader(filename);        // сокращенная форма - сразу open(...)
    if (!reader) {                         // проверка нужна
        std::cout << "Reader open error";  //  и для сокращенной формы
        return -1;                         // 
    }                                      // 
    while (!reader.eof()) {                // цикл до конца файла (EOF)
        reader.getline(str, MAX_STR);      //  считываем строку из файла в str
        size_t length =                    //  определяем ее длину
            strnlen_s(str, MAX_STR);       // 
        if (length > max_length) {         //  сравниваем длину с максимальной
            max_length = length;           //  если нашли более длинную строку,
            strcpy_s(max_str, str);        //  то заменяем max_length и сохраняем 
        }                                  //  саму строку в отдельном буфере (max_str)
    }
    reader.close();

    std::cout << "Max length of file's line = " << max_length << std::endl;
    std::cout << "It is: " << max_str << std::endl;

    return 0;
}

int main1()
{
    std::ofstream writer;
    std::ifstream reader;
    const std::string filename = "file.txt";

    writer.open(filename);  // по своему типу файл - на запись
    if (!writer) {            // открылся ли файл?
        std::cout << "Writer open error" << std::endl;
        return -1;
    }
    writer << "String 1 in file" << std::endl
        << "String 2 in next line\nLine 3";

    writer.flush();
    writer.close();
    //////////////////////////////////////////////////////////
    reader.open(filename);
    if (!reader) {
        std::cout << "Reader open error" << std::endl;
        return -2;
    }
    char str[128];
    std::string stdstr;
    // reader >> str;   // читает одно слово
    // reader.getline(str, 128);   // читает строку из файла
    // std::cout << str << std::endl;
    // 
    // std::getline(reader, stdstr);  // то же, для std::string
    // std::cout << stdstr << std::endl;

    while (!reader.eof()) {
        reader.getline(str, 128);
        std::cout << str << std::endl;
    }
    reader.close();

    std::cout << "--- Program finished ---\n";
    return 0;
}
/*
    Файлы. Потоки (stream).
    'A' - ANSI   = 60
        - UTF-16 = 0060
        - UTF-8  = 60

    'Я' - ANSI   = 237
        - UTF-16 = 0341  -ANSI- ?2 
        - UTF-8  = DA37  -ANSI- ц*
*/
