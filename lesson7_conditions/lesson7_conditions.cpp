#include <iostream>
#include <string>
#include <cmath>  // sqrt - ������ ����������

int main() {
    // ������� ������ ��������� � ���������
    const float SQUARE_X_LEFT   = -4;  // ���������� � ����� ������� ��������
    const float SQUARE_X_RIGHT  = -1;
    const float SQUARE_Y_TOP    = 4;
    const float SQUARE_Y_BOTTOM = 1;

    float x, y;

    std::cout << "Enter point (x,y): ";
    std::cin >> x >> y;
    // A �������
    // ����� ������ �������� ���� 
    // X_LEFT < x < X_RIGHT   �   Y_TOP < y < Y_BOTTOM
    /* DRY - Don't Repeat Yourself - ��������� � ���������� ����
           - ������� ������������� ���������� ����
        ������������ - �������� ���������� �����, � � ��������
        ��������� ������ ��, ��� ��������
    if (SQUARE_X_LEFT < x && x < SQUARE_X_RIGHT
     && SQUARE_Y_TOP  < y && y < SQUARE_Y_BOTTOM) 
    {
        std::cout << "Point (" << x << "," << y << ") "
            << "Inside square A";
    }
    else {
        std::cout << "Point (" << x << "," << y << ") "
            << "Outside square A";
    }*/
    // ���������� ��� ������������ ������ (���������)
    std::string message;
    // ����� ��������� �����
    message = "Point (" + std::to_string(x) 
        + "," + std::to_string(y) + ") ";

    if (SQUARE_X_LEFT < x && x < SQUARE_X_RIGHT
     && SQUARE_Y_BOTTOM < y && y < SQUARE_Y_TOP)
    {
        message += "inside";  // ������������ �����
    }
    else {
        message += "outside";  // message = message + ".."
    }
    // ����� ��������� ���������
    message += " square A";
    // ����� ��������� �� �����
    std::cout << message << std::endl;

    // B Circle
    const float CIRCLE_CENTER_X = 2;
    const float CIRCLE_CENTER_Y = 2;
    const float CIRCLE_RADIUS   = 2;

    // ����� ������ ����� ���� ���������� �� ��� ������ 
    // ������ ������� (����� � ��������)
    // ���������� �� ������ �� �����:
    float x_to_center = sqrt(   // ������ ��. (<cmath>)
        (CIRCLE_CENTER_X - x) * (CIRCLE_CENTER_X - x)
        + (CIRCLE_CENTER_Y - y) * (CIRCLE_CENTER_Y - y)
    );
    // ��� ��������� ����� �� �� ����������, ��� ��� ��������
    message = "Point (" + std::to_string(x)
        + "," + std::to_string(y) + ") ";  // ����� �����

    // ��������� ����� - �� ���������� ���������
    message += (x_to_center < CIRCLE_RADIUS)
                ? "inside"
                : "outside";
    // ����� ���������
    message += " circle B";
    // ����� ��������� �� �����
    std::cout << message << std::endl;

    // RECTANGLE C


    return 0;
}

int main4() {
    long double x;  // 80 bit
    std::cout << "Enter x = ";
    std::cin >> x;
    int r = (int)x;
    if (x > r) r += 1;  // r = r + 1 -- ����������� �����
    std::cout << "Ceiling = " << r;
    return 0;
}

int main3() {
    float n;

    std::cout << "Enter number: " << std::endl;
    std::cin >> n;

    std::string type =
        (n == 0) 
        ? "zero" 
        : ( (n > 0) 
            ? "positive" 
            : "negative" ) ;

    std::cout << n << " is " << type << " number.";


    return 0;
}

int main2() {
    // ��������� �������� (���������)
    // � = (�������) ? ����1 : ����2 ;
    // ���� ������� +, �� ������������ ����1, ����� - ����2
    // ������ �. Excel  =����(���;����1;����2)
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;
    // std::string type = ((n % 2) == 0) ? "Even" : "Odd";
    
    // std::cout << n << " is " << type << " number";
    std::cout << n << " is " << (((n % 2) == 0) ? "Even" : "Odd") << " number";

    return 0;
}

int main1()
{
    // �������� 5 �����, ����� ����� �����������
    // ������: ������ ����� � ���������� ������ � ������
    //  ������������. ��������� ������� � ����� �����������
    int n, min;
    // �.�. ������ ��������� ����� �� ��������, ����������
    // ���� ���������� � ����� "�������" ������ ��������

    std::cout << "Value 1: ";
    std::cin >> n;
    min = n;  // ���� ������� ����, �� �� � ���� � ���

    std::cout << "Value 2: ";
    std::cin >> n;  // � �� �� ����������
    if (n < min) min = n;   // �������� �������� ��������, ����
                            // ��������� ��������� �������
    std::cout << "Value 3: ";
    std::cin >> n;
    if (n < min) min = n;

    std::cout << "Value 4: ";
    std::cin >> n;
    if (n < min) min = n;

    std::cout << "Value 5: ";
    std::cin >> n;
    if (n < min) min = n;

    std::cout << " Min value: " << min;

    return 0;
}

/*
���������������� ����� ������������� �����
����������� ��� ������� �����:
 ��� �������� ������������� ��� ����� (0.0000000001),
 ��� � ������� (100000000000) ����� � ������ �����
����� ����������� �� 
 ������� (�) - "�����" - ������, ��� ������� ����� �����
   ����� ������ �����, 1 < M < 9
 ���������� - ������� ����� 10, "������� �����" - ���������,
   ������� �� ������� ������ ������ �����
��������,
0.00123  --> M = 1.23,  E = -3  (10 ^ -3)
345000   --> M = 3.45,  E = 5
5.67     --> M = 5.67,  E = 0
double x = 1.23e-3; 
������ ��� ������ �������/����� �����
0.0000000001  1e-10
*/
