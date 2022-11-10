// Lesson5_Conditions.cpp : ������� � �������� ��������

#include <iostream>

int main() {
    // �������� ����, ��� ��������� ����� 4-�������
    long x;
    std::cout << "Enter 4-digit number: ";
    std::cin >> x;

    if ( ! (x > 999 && x < 10000)) { // ��������� �������
         std::cout << "Wrong!";      // �����, ��� �����������
         return -1;                  // � ����� �� main
    }                                // ��� ��������� 
                                     // �� ������ else, �.�.
    std::cout << "Ok\n";             // ����� ��������� ���������
    
    // ������� ������ ����� ����� (����, ��� � ��� 4 �����)
    int digit1 = x / 1000;
    std::cout << "1st digit: " << digit1 << std::endl;
    
    // ������� ������ �����
    int digit2 =                    // 1234, d1 = 1
        (x - digit1 * 1000) / 100;  // 1234 - 1*1000 = 234
    
    std::cout << "2nd digit: " << digit2 << std::endl;

    return 0;
}

int main3() {
    // �������� ������ � ������
    std::string login, pass;

    std::cout << "Login: ";
    std::cin >> login;
    std::cout << "Password: ";
    std::cin >> pass;

    if (login == "user"  && pass == "123"
     || login == "admin" && pass == "321"
     || login == "moder" && pass == "hello")
    {
        std::cout << "Access granted";
    }
    else 
    {
        std::cout << "Access denied";
    }

    return 0;
}

int main2() {
    // "���������" ���������
    // ������������ ������ ����������� ����
    // ��������� ������� �������:
    //   < 35  cold
    //   35-37 norm
    //   37-38 desease
    //   >38   reanimation

    std::cout << "Enter body temperature: ";
    float t;
    std::cin >> t;
    if (t < 35)
        std::cout << "You've got a cold";
    if (t >= 35 && t < 37)
        std::cout << "Your temperature is normal";
    if (t >= 37 && t <= 38.2)
        std::cout << "You're ill.";
    if (t > 38.2)
        std::cout << "You should immediately go to the hospital! Reanimation";
    /*
    if (t < 35) {
        std::cout << "Cold";
    }
    else if (t < 37) {
        std::cout << "Normal";
    }
    else if (t < 38) {
        std::cout << "Desease";
    }
    else {
        std::cout << "Reanimation";
    }
    */
    /*
    if (t < 35) {
        std::cout << "Cold";
    }
    else {
        if (t < 37) {
            std::cout << "Normal";
        }
        else {
            if (t < 38) {
                std::cout << "Desease";
            }
            else {
                std::cout << "Reanimation";
            }
        }
    }
    */
    return 0;
}

int main1()
{
    std::cout
        << "2 < 3  --> " << (2 < 3)  << std::endl
        << "3 == 3 --> " << (3 == 3) << std::endl
        << "3 <= 3 --> " << (3 <= 3) << std::endl
        << "3 != 3 --> " << (3 != 3) << std::endl;

    // odd / even testing
    std::cout << "Enter number: ";
    int x;
    std::cin >> x;
    if (x % 2 == 1) {
        std::cout << "It is odd" << std::endl;
    } 
    else {
        std::cout << "It is even" << std::endl;
    }
    return 0;
}

/*
������� (�������� ���������, ��������) - ���������,
������� ��������� � ���� ���� ������������: true ��� false
 2 < 3  --> true (1)
 3 == 3 --> true (1)
 2 > 4  --> false(0)
������� ����������� �� ��������� � ���������
���������                ���������
x == y - ���������       x < y,  x > y  - �������
x != y - �����������     x <= y, x >= y - ���������
!! ��������� ��������� ������ ��������� ��������:
  ������:  = =    < =
  � ����� ������ �������:   =<  =>

��� �������� ����������� ������� ���������� ����. ��� ������
 bool (�� �� - ���������� ���)

 bool x = (3 == 2);
*/
/*
�������� �������� ��� �������� ���������
if(�������) { ���������; ���������; } - ����������� �����
���� ������� ������� (true), �� ��������� ����� ���������,
����� - ���������

if(�������) { ���������1; ���������1; }
else { ���������2; ���������2; }  - ������ �����
���� ������� ������� (true), �� ����� ��������� ���������1,
����� - ���������2

���������, ����������� � "����������� ������" {}
�������� "�����"
*/
/*
���������� ���������
���� ���������� ��������� ��������� ������� �����, ��
��� ����� ������������� ��������� ���������:
 && "�������� �" - ������� ���������� ���� �������
 || "���" - ������ ����������� ���� �� ����
 !  "��" (��������) - ������ ��������� ������� �� ��������

if( x > 10 && x < 20 ) -- � � ��������� (10,20)
if( login == "user" && pass == "123" )

*/
