// Lesson3.cpp : ���������� � ���� ������

#include <iostream>  // ��������� ��������
#include <iomanip>   // ������������ ������
#include <string>

int main() {
    char hr = (char)205;  // horizontal line
    std::string str;
    //std::cin >> str;
    std::getline(std::cin, str);
    std::cout << str + std::to_string(2) << std::endl
        << std::stoi("10") << std::endl;

    std::cout
        << "Name: \"The warand the peace\"\n"
        << "Avtor : L.N.Tolstoj\n"
        << "Izdatelstvo : Piter\n"
        << "Pages : 500.\n"
        << std::endl   // ������������ \n
        << (char)201   // left-top corner
        << hr << hr << hr << hr << hr << hr << hr << hr << hr << hr << hr << hr << hr << hr << hr << hr
        << (char)187   // right-top corner
        << std::endl
        << (char)186
        << std::setw(12) << "Pory Roku"  // setw - ����������� ������
        << std::setw(5) << (char)186;


    return 0;
}
/*
������ ��������:
������������ ������ 
 - ���������� ����� ��������
 - ����� �������
 = ��������� ������� ������� �������� ��������

������� ����������:
 - �������� �������� ������� 
 - ���� ��������
 = ��������� ������� ��������� ���������
*/

int main1()
{
    int x;   // ����������� ����������
    x = 10;  // ������������ - ����������� ������ �� ������ ����� � ������
    int y = 20;  // ����������� + ������������� - ���������� �� �������
    // ��������� - ����������� ������, � ���������������� �����

    // ���� ������������
    std::cout << "Enter x = ";
    std::cin >> x;

    y = x * x;  // ��������� (x * x), ��������� ����� ��������� -> y
    std::cout << "x * x = " << y;

    return 0;
}

/*
���������� - ������� ��������� ���� (������ ���������) � ����������
 ��� (���-����)

���������� - ����������� ������� ������
 - ������ ����� ����������. ��������� - ���� �� �����
 - � ����� ����� �� ������� ���������
 - ������ ���������� ������ �������� ����������

��� ������ - ���������� �:
 - �������, ���������� ��� �������� ������
 - ������� �������������� (�������� ������ � �������� � �������)
 - ���������� ��������� � ������� ����� ����
 = � �������� ��������������
  432     101 = 5
  |||     |||
  ||1     ||1
  |10     |2 
  100     4

  ������� ��������� - ��������, ��� ������� ��������� ���������
  ������ ���� ��������� � ���������� ������� ����.
  ��������� ��������� - � ������� ��������������� �����, ��������,
  ����� ����� (int) ����� ��������� � ���������� �������� ���� (double)
  ��� �������������� ������������� ��������.

  ����������� ��������� - ���������� �� ������ ��� ��� ������ ���������.
  ������������ ��������� - ����� �������� ���

  ���������� (statement) - ������������� ���������� ������ �
  ����� ����������������.

  ��������� - ����������, ������� ���������

*/