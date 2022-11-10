#include <Windows.h>
#include <conio.h>
#include <iostream>

#define gotoxy(x,y)   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y })

int main() {
    short display_y = 0;                 // ������ ��� ����������� ����������
    short target_y  = 1;                 // ������, �� ������� �������� ����
    short gates_y   = 2;                 // ������ � "��������"
    short gates_x   = 38;
    short gates_w   = 3;                 // ������ �����

    short x  = 0;
    short dx = 1;
    char  c  = 2;                        // 1,2 - smiley, 3 - heart
    int   score = 0;                     // ��������� ����

    gotoxy(0, display_y);
    std::cout << score;

    gotoxy(gates_x, gates_y);            // "������" - 
    std::cout << '[';                    // ����� ������ [
    for (short i = 0; i < gates_w; i++)  // ������� � ���������� gates_w
        std::cout << ' ';                // 
    std::cout << ']';                    // ������ ������ ]

    while (true) {                       // ������� ����������� ����
        gotoxy(x, target_y); 
        std::cout << ' ';                // ������� ������ ���������
        x += dx;                         // �������� ����������
        gotoxy(x, target_y); 
        std::cout << c;                  // ���������� � ����� ���������
                              
        if (_kbhit()) {                  // keyboard hit - ������� ������ ����������
            char kb = _getch();          // ���� ������ ������ - ���������
            if (kb == 0 || kb == -32) {  // ����������� ������ �������� ��� �������
                kb = _getch();           // ��������� ������ �� ���
            }
            if (kb == 27) {              // ESC
                break;                   // ��������� ����� - �����
            }
            if (kb == 32) {              // Space (����� ������)
                if (x > gates_x          // ����� � ������
                 && x <= gates_x + gates_w ) {
                    ++score;             // ����������� ����
                }
                else {                   // ������ �����, �� �� �����
                    --score;             // ��������� ����
                }
                gotoxy(0, display_y);    // � ����� ������ ����� ������� �������
                std::cout << score       // ���������� ����� ���� �
                    << "  ";             //  ��������� �������������� ��������, ����� ������� ������
                Sleep(1000);             // � ������ ����� 
            }
            if (kb == 'g') {             // ������� ����������� ��������� ������
                ++gates_w;

                gotoxy(gates_x, gates_y);            
                std::cout << '[';                                // [   ]
                for (short i = 0; i < gates_w; i++)              // [  ]
                    std::cout << ' ';                            //     __
                std::cout << ']';                                // [  ]]
            }

        }

        if (x == 80 || x == 0) dx = -dx;
        
        Sleep(100);                      // ����� 100 �� (10 fps)
    }

    gotoxy(0, 5);  // ����� ���� ��������� �� ��������� ���������
    return 0;
    // ������: ���� � ��������� 80, �� �������� ���� � �������� ������� �� 0, ����� �������
}

int main1()
{
    // �������: ������� ������ ����� � ��������� ���������
    for (size_t i = 0; i < 20; i++)
    {                            // � �++, ��� ������������� � � ��� bool ����� ���� �������
        if (i % 2) continue;     // (i % 2) - 0 ���� 1, ��� ������� ��� �������, ��� false � true
        std::cout << i << "\n";  // ���� ����� ������, �� ������� - 0 � ��� �������������� ��� false
    }                            // �������� - 1 (true), ����������� continue -> ����� �������� (����� ������������)
    
    // �������� 0 ���� ������������ �� ������ ����� �������
    while (true) {       // ����������� ����
        std::cout << 0;
        if (_kbhit()) {  // keyboard hit - ������� ������ ����������
            break;       // ��������� ����� - �����
        }
    }

    return 0;
}

/* ��������� ���������� ������
    continue - ������� � ��������� ��������
    break - ����������� �����. ���������� ���������� - ����������� ���� � �������� ������

    ���� �����     
    ����1      |    ^
    ����2      |    |
    continue   v -->    break |
    ����3                     |
                              v
*/