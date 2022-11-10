
#include <iostream>

int main() {
    float x, y;  // ��������, �������� �������������
    char op;     // ������ ���������

    std::cout << "Enter expression like 3 + 2: ";
    std::cin >> x >> op >> y;

    float res;   // ��� �������� ����������

    /*
    if (op == '+')      res = x + y;
    else if (op == '-') res = x - y;
    else if (op == '*') res = x * y;
    else if (op == '/') res = x / y;
    else {  // ���� �� �������� ���� �������� ������
        std::cout << "Invalid operation";
        return -1;
    }
    */
    // �������� �������������� ������ - switch
    switch (op) {
    case '+': res = x + y; break;
    case '-': res = x - y; break;
    case '*': res = x * y; break;
    case ':':   // ������� "������������"
    case '/': res = x / y; break;
    case '%':   // ������� �� ������� - ������ ��� �����
        if (x == (int)x && y == (int)y) {
            res = ((int)x) % ((int)y);
            break;
        }       // ���� if �� ���������, �� �� ����� break
                // � ������ ��� "����������" � ������ ������ (� default)
    default:
        std::cout << "Invalid operation";
        return -1;
    }

    std::cout << x << " " << op << " " << y
        << " = " << res << std::endl;

    return 0;
}
/*
    �������: �����������
    ������������ ������ ��������� �� ����� ��������,
    ��������, 3 + 2
    ����������� �������� + - * /    %
    ��������� ������� ��������� ����������
*/

int main1()
{
    unsigned int products_cnt;     // �����������, �.�. 
    // �������������� ���-�� ���� �� �����

    unsigned short prod_per_page;  // ������������, 
    // ��� �� �������� �� ����� ������ ��� 65� �������

    unsigned int pages;

    std::cout << "Enter products count and page capacity ";
    std::cin >> products_cnt >> prod_per_page;

    pages = products_cnt / prod_per_page;  // �������
    // ������������ - ��� ������������� �������

    // ��! ���� ������� ����, �� �� ��������� +1 ��������
    if (products_cnt % prod_per_page != 0) {
        ++pages;
    }
    std::cout << "Pages count: " << pages;

    return 0;
}

/*
   �������. �����������
   ������� (���������): 
   ���� (������ ������������)
    - ���-�� �������
    - ���-�� ������� �� ����� ��������
   ����� (�������)
    - ����� ���-�� �������
    ��������, 
    �������   �� ��������   �������
      20          5            4
      20          10           2
      20          6            4
      20          7            3
*/
