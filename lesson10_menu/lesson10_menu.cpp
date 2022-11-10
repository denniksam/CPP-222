// �����, �����������. ����������� ����, ��������� �����
#include <Windows.h>    // ������ � �������� ��� � �����
#include <iostream>
#include <conio.h>      // console input-output [ _getch() ]

// gotoxy(x,y) - ����������� ������ � ������� (�,�)
#define gotoxy(x,y)   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y })

int main()
{
    /*
    ���������� ������� �����. ��������� ������� ���� � ����� ����,
    ���������� ���� ���� �� ������ �����������.
    ��������� ������� ���� � ����� ����.
    ���������� � ������������ ����������� ����� ����.
    */

    char button;

    do {
        system("CLS");

        long long number;
        std::cout << "Enter your number: ";
        std::cin >> number;
        std::cout << std::endl;

        std::cout
            << " -------------Menu--------------" << std::endl
            << " The number of digit in a number" << std::endl
            << " The sum of digit in a number" << std::endl
            << " Arithmetical mean of digits" << std::endl
            << " The number of zeros in a number" << std::endl;

        gotoxy(0, 3);
        std::cout << ">";
        short y = 3;
        do {
            button = _getch();
            if (button == 0 || button == -32)
            {
                button = _getch();
            }
            gotoxy(0, y);
            std::cout << ' ';

            if (button == 80)
            {
                y += 1;
                if (y >= 7)
                {
                    y = 3;
                }
            }

            if (button == 72)
            {
                y -= 1;
                if (y < 3)
                {
                    y = 6;
                }
            }

            gotoxy(0, y);
            std::cout << '>';
        } while (button != 27 && button != 13 && button != 32);

        gotoxy(0, 8);

        if (button == 27)
        {
            std::cout << "Bye!";
            return -1;
        }
        short n;
        long long divider;
        short number_of_digits = 0;
        short sum = 0;
        short arithmetical_mean = 0;
        short number_of_zeros = 0;
        divider = 1;

        while (divider <= number)
        {
            divider *= 10;
        }
        while (divider > 1)
        {
            divider /= 10;
            n = number / divider;

            sum += n;
            number_of_digits += 1;
            if (n == 0)
            {
                number_of_zeros += 1;
            }
            arithmetical_mean = sum / number_of_digits;

            number -= n * divider;
        }
        switch (y)
        {
        case 3:
            std::cout << "The number of digits: " << number_of_digits;
            break;
        case 4:
            std::cout << "Sum: " << sum;
            break;
        case 5:
            std::cout << "Arithmetical mean of digit: " << arithmetical_mean;
            break;
        case 6:
            std::cout << "The number of zeros in a number: " << number_of_zeros;
            break;

        }
        std::cout << std::endl;

        system("PAUSE");

    } while (true);

    return 0;
}

int main2() {
    std::cout 
        << " -=Menu=-" << std::endl
        << "  Item 1" << std::endl
        << "  Item 2" << std::endl
        << "  Item 3" << std::endl;

    gotoxy(0, 1);      // ��������� ������ �� ������� "0" � ������ "1" (������ ������)
    std::cout << ">";  // ">" �������� ����� "Item 1"
    short y = 1;       // ���������� �������
    char c;
    do {                              // ���� ���������� ����
        c = _getch();                 // ��������� ������
        if (c == 0 || c == -32) {     // ������� ������� �������� -32,
            c = _getch();             //  ������� ��������� ��� ���
        }
        // ������� "�������" � ������ �������
        gotoxy(0, y); std::cout << ' ';  // ������� ������ ' '

        // ������ ���������� "�" (� ����������� �� ������� ������)
        if (c == 80) {  // ������ "����"
            y += 1;     // ��� "�" �� ������� ����������� - ������������� ����
            if (y >= 4) {
                y = 1;
            }
        }
        if (c == 72) {  // ������ "�����"
            y -= 1;
            if (y < 1) {
                y = 3;
            }
        }
        // ������ ������� � ����� �������
        gotoxy(0, y); std::cout << '>';

    } while (c != 27 && c != 32 && c != 13);  // 13 - Enter, 27 - ESC, 32 - Space
    
    gotoxy(0, 5);  // ��������� ������ �� ���� (����� ����� ����� ���� �� ����)
    
    // ����� ������ �� ����� � ��� ��� ��������:
    // ���� ������ (ESC), ���� ������������� (Enter ��� Space)
    if (c == 27) {  // ��� ������
        std::cout << "Bye-bye";
        return 27;  // ������������� return ��������� �� ������ else
    }
    // else - �� �����, �.�. ����� � if �������� � return - ������ �� ���������

    std::cout                  // ���� ������������ ����� �������,
        << "You select Item "  // ��� �� ������ � �=0 ��������� "����"
        << y                   // � ������ �=1 -- item 1, �=2 -- item 2, ...
        << std::endl;          // ������� �������� "�" ��������� � ������� ������

    // ����������� ����� ���� 
    switch (y) {
    case 1:  // ������ ����� ����: ������ ������� �� "*"
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {  // ��������� ����
                _putch('*');   // put char - ����� ������� ����� �������
            }
            std::cout << std::endl;
        }
        break;
    case 2:
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < i + 1; ++j) {  // ���������� ���� ����� �������� �� ��������
                _putch('*');   
            }
            std::cout << std::endl; //  __*__
        }                           //  _***_
        break;                      //  *****
    case 3:  // rhomb <>            //  _***_
    {                               //  __*__
        // ����� ���� ������� - �������� �����, ������� 5
        int n = 5;
        // ������� �����
        for (int i = 0; i <= n / 2; ++i) {  // ������
            int spaces = n / 2 - i, stars = 1 + 2 * i;
            // �������
            for (int j = 0; j < spaces; ++j) {
                _putch(' ');
            }
            // ***
            for (int j = 0; j < stars; ++j) {
                _putch('*');
            }
            // ������� (�� �������, � ��� �����)
            // ������� ������
            std::cout << std::endl;
        }
        // ������ �����
        for (int i = n/2 - 1; i >= 0; --i) {     // ������
            int spaces = n / 2 - i, stars = 1 + 2 * i;            
            for (int j = 0; j < spaces; ++j) {  // �������
                _putch(' ');
            }            
            for (int j = 0; j < stars; ++j) {   // ***
                _putch('*');
            }
            std::cout << std::endl;
        }
        break;
    }
    }
    return 0;
}

int main1()
{
    std::cout << "Press a key\n";
    char c;
    do {
        c = _getch();   // get char - ����� ����������� ��� ������� �������
        if(c == 0 || c == -32) c = _getch();
        std::cout << "Symbol: '" << c << "' code: " << (int)c << std::endl;
    } while (c != 27);  // 27 - ESC

    return 0;
}

/* � ����������:
*  _getch() ��������� ���� ������ � ����������, �� �� ��������� �������
* �� ��������� ��� ��������, ��������, �������������� ������ F1, F2
* ������� �������� "0" ����� ���� ���. ������ ���������� �������� 
* - ������� -32 (224), ����� ���� ���.
* ��� ������ � ���� ������ ���������� �������, ��� ��� ����� �������, ���
* �������� ������ ��������.
* 
* left   75
* right  77
* up     72
* down   80
*/