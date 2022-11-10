// Lesson4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
int main() {
    tm datetime;
    std::cout << "Enter date in format '25.12.2020': ";
    std::cin >> std::get_time(&datetime, "%d.%m.%Y");
    std::cout
        << "year "  << datetime.tm_year    << std::endl
        << "month " << datetime.tm_mon + 1 << std::endl
        << "day "   << datetime.tm_mday    << std::endl;

    return 0;
}





int main_4() {
    /* ������������ ������ ������ ��� � ��� ��������
       ��������� ��������� ������� ��� ���������� � ���� (2022) ����
       ������:
       Enter name:  John Smith
       Year of birth:  1980
       A>This year, John Smith, you'll be 42 years old 

       B>This year, John, you'll be 42 years old 

       ������������� "��������":
       ������������ ������ (���������) ���, �������, �������.
       ��������� ��������� "��������" "������� ���, ��� ��������"
        � ��������� �� � ����� ����������
       ������:
       Surname: Smith
       Name: John
       Age: 42
       >'Smith John, 1980'
       */
    return 0;
}

int main_3() {
    // ������ �� ��������
    /* � �++ ���� ��� ������� � �������: ������ ��������
    *  � ����������� ��� std::string
    */
    std::string str;  // ���������� ��� �������� ������
    std::cout << "Enter string: ";
    // std::cin >> str;  // ������ ������ "�����" - �� �������
    
    // ������ ��, ��� ���������� (� ���������)
    std::getline(std::cin, str);
    std::cout << "You type: " << str << std::endl;

    // ������������ ����� - ��������, ���������� �����
    // "Hello" + " all" ==> "Hello all"
    // "10" + "20"  ==> "1020"

    int x = 10;              // �����
    std::string x_str =      // ������ � ���������� (���������)
        std::to_string(x);   // �������������� �����

    int y = 20;
    std::string y_str = std::to_string(y);

    std::cout << "x + y = " << x + y << std::endl
        << "x_str + y_str = " << x_str + y_str << std::endl
        << std::endl;

    return 0;
}

int main_2() {
    // ���������� � ���� ������ (�����������)
    int code;  // ��� ������� - ������ ������������
    char sym;  // ��� ������ - ������� ���������

    std::cout << "Enter code (0..255): ";
    std::cin >> code;  // ��������� ���� ������������

    sym = (char)code;  // () - �������������� ���� (�����)

    std::cout << "Symbol: " << sym << std::endl;

    /********* �������� ������ ************/
    std::cout << "Enter a symbol: ";
    std::cin >> sym;

    code = (int)sym;  // ���� �������������� ����

    std::cout << "Code of symbol: " << code << std::endl;


    return 10;
}

void main_dz()
{
    // ���������� ������������� - �������. 
    // ����� ������� ���������� � �������
    std::cout << cos(34 * M_PI / 180) << std::endl;

    // ������� ����-������-�������
    int time = 100530;    // ����� ����� � ��������
    int h = time / 3600;  // � ���� 3600 ������
    int minsec = time % 3600;  // time - h * 3600
    int m = minsec / 60;  // ������
    int s = minsec % 60;  // minsec - m * 60

    std::cout << "hours: " << h << std::endl
        << "minsec: " << minsec << std::endl
        << "min: " << m << std::endl
        << "sec: " << s << std::endl
        << std::endl;

    h = 10;  // 36000
    m = 20;  // 1200
    s = 30;  // 30  --> 37230 (timestamp)
    std::cout << h * 3600 + m * 60 + s;

}

/*

*/
