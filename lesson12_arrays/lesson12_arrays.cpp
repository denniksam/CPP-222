
#include <iostream>

int main() {
    const size_t N = 20;  // size_t - ��� ��� �������� 
    int arr[N];  // ��� �������� ������� ������� ����� ��������� (�� ����������)
    
    srand(time(0));  // ����������� ���������� ���

    for (size_t i = 0; i < N; i++)
    {
        arr[i] = rand() % 101 - 50;
    }

    for (size_t i = 0; i < N; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    // ������ �� ������ � ���������� ��������:
    // 1. ���������� ���-�� ������������� ����� � ������� arr.
    size_t cnt = 0;
    for (size_t i = 0; i < N; i++) {
        if (arr[i] > 0) {
            ++cnt;
        }
    }
    std::cout << "Positive elements: " << cnt << std::endl;

    // 2. ���������� ���-�� �������������, � ����� (��������) ������� ���������
    size_t neg = 0;
    size_t countZeroes = 0;  // casing - ���������� ���������� ���� � ��������
                             // lowerCamelCase - ������ � ���������, ��������� � �������
                             // CapitalCamelCase, php_style, CONST_STYLE
    for (size_t i = 0; i < N; i++)
    {
        if (arr[i] < 0) {
            neg++;
        }
        if (arr[i] == 0)
            ++countZeroes;
    }
    std::cout << "Negative elements: " << neg << std::endl;
    std::cout << "There are " << countZeroes << " zero elements." << std::endl;

    // 3. ����� ������ � ��������� ������������� �������� � �� �������. ���� �� ���� - �������
    //    ��� ������ (� ��� ������, � ��� ���������). ���� ������������� ���,
    //    ��� � ������� (��� �������������)
    // 3�: ������ �������������
    size_t first_neg_index;
    for (first_neg_index = 0; first_neg_index < N; first_neg_index++) {
        if (arr[first_neg_index] < 0) {
            break;
        }
    }
    if (first_neg_index == N) {  // ���� ������ ��� ��-�� � ����� �� �������� break
        std::cout << "There are no negative elements." << std::endl;
    }
    else {  // �������� break
        std::cout << "First negative element: " << arr[first_neg_index]
            << " has index " << first_neg_index << std::endl;            
    }
    // 3�: ��������� �������������
    // ����� ���� - ��� �� ����, �� � ����� � ������.
    // �����������: ��� size_t �� ����� ������� ������������� �����, �������
    //  ����� ������ ������ ��� ��������� ����: ������ ��� ��-�� ��� ����� �������������
    // �������� ��������� ������: ������ ���� � ������ �����������, � �������� �����
    //  ���������� � �������� �������
    size_t k;
    size_t last_neg_index;
    for (k = 0; k < N; ++k) {           // ���� � ������ �����������
        last_neg_index = N - 1 - k;
        if (arr[last_neg_index] < 0) {  // arr[N - 1 - k] --> k-� ��-�, �� � �����
            break;                      // k          0  1  2    8  9  10   ����� N = 10
        }                               // N - 1 - k  9  8  7    1  0  -1(4�294�967�295)
    }
    if (k == N) {  // ���� ������ ��� ��-�� � ����� �� �������� break
        std::cout << "There are no negative elements." << std::endl;
    }
    else {  // �������� break
        std::cout << "Last negative element: " << arr[last_neg_index]
            << " has index " << last_neg_index << std::endl;
    }

    // ������� ��� �������� ������� (����� ������), ������� ��������� ����� ������
    //   � ��������� �������������� ���������� (���� ��������� �������� �� ��������)
    if (first_neg_index != N /* && k != N*/)
    {
        for (size_t i = first_neg_index + 1; i < last_neg_index; i++)
            std::cout << arr[i] << " ";
    }
    return 0;
}

int main1()
{
    // �������� �������
    int arr1[10];   // ��� ���[������]
    // � ������ "�����������" ����� �� 10 ����� ���� int

    // ���������� �������
    arr1[0] = 10;   // ������ � ������ ������� - ���[������]
    arr1[1] = 11;
    arr1[2] = 12;
    arr1[3] = 13;
    arr1[4] = 14;

    // "���������" ������ - ������� �� �����
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << arr1[i] << ' ';
    }
    std::cout << std::endl << arr1 << std::endl;

    return 0;
}
/*
    �������
     ���������������� (����-��-�����)
     ���������� (��� �������� ������ ����)
     ��������� ������.
    � ����� �������, ������ - ��� ����������, �� ���� ����������� ��������,
     ���������� �� �������� ������ (��� ����, ������ - �����)
    � ������ �������, ������ �������� ����� ����� ��������� ����������,
     ����������� �������� ��������� ������ (������ ����)

    <--- array --->   �������� int array[5] - �������� 5 �����
    [ ][ ][ ][ ][ ]
    ���������� -  ������ ������� ����� ������ �� ������� �� ����� � ����
    ������ - ��������, ������������ ������� ���� ��������� �� ������ �������
      ��� ���� ����� ������� � ������ ������.
    !! ��������� ������ int array[5] ����� ������
    array[0] - array[1] - array[2] - array[3] - array[4]
*/