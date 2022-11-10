#include <iostream>
#include <cmath>

/* ��: ���� ������ ����� � ��������� ���������� �������
*  �������� ��������. ���������� ��������� ��� ���������
*  � ������, ������� ����������, �������� ������������
*  � ����������� ����������. �����������: ���-�� ����������
*  ����� ����������, ��������� ������ ���� ������ �
*  ������ � ����� ������� ����������
*/

#define sqr(x) (x)*(x)

typedef  float (*algo_t)(int*, size_t);

float mean_alg(int* data, size_t length) {  // ��. ��������������
    if (data == NULL) {
        std::cout << "NULL dereference error";
        return -1;
    }
    float res = 0;
    for (size_t i = 0; i < length; i++) {
        res += data[i];
    }
    return res / length;
}
float mean_harm(int* data, size_t length) {  // ��. �������������
    if (data == NULL) {
        std::cout << "NULL dereference error";
        return -1;
    }
    float res = 0;
    for (size_t i = 0; i < length; i++) {
        res += 1.0 / data[i];
    }
    return length / res;
}
float mean_geo(int* data, size_t length) {  // ��. ��������������
    if (data == NULL) {
        std::cout << "NULL dereference error";
        return -1;
    }
    float res = 1;
    for (size_t i = 0; i < length; i++) {
        res *= data[i];
    }
    return pow(res, 1.0 / length);
}
float mean_sqr(int* data, size_t length) {  // ��. ��������������
    if (data == NULL) {
        std::cout << "NULL dereference error";
        return -1;
    }
    float res = 0;
    for (size_t i = 0; i < length; i++) {
        res += sqr(data[i]);
    }
    return sqrt(res / length);
}
#define AN  4
algo_t* algos = new algo_t[AN]{ mean_alg, mean_harm, mean_geo, mean_sqr };

int main() {
    size_t N = 7;
    int *data = new int[N] { 10, 9, 10, 7, 12, 8, 2 };
    
    for (size_t i = 0; i < AN; i++) {
        std::cout << algos[i](data, N) << std::endl;
    }
    
    delete[] algos;
    delete[] data;
    return 0;
}


//  ������ - ������, ������� ------------------------------

void print_x(int);

int iprint_x(int x) {
    std::cout << x << std::endl;
    return std::cout.good();  // ������ ������ (���������� ��������)
}
void print_c(char c) {
    std::cout << c << std::endl;
}
void print_y(int y) {
    std::cout << y << std::endl;
}

typedef    void (*func_void_int)(int);   // ��������� ����
                             // func_void_int == void (*)(int)

typedef int (*oper_t)(int, int);   // ����. ��:  int fun(int, int)

int add(int x, int y) {
    return x + y;
}
int sub(int x, int y) {
    return x - y;
}

int make_operation(     // ������ �������� ������� � �������
    oper_t operation,   // operation - ��������� �� ���� �� �-���
    int x, int y)       // ��������� ��� �� ������
{
    if (operation == NULL) {
        std::cout << "NULL dereference error";
        return -1;
    }
    return operation(x, y);
}

int main2() {
    oper_t operation;
    std::cout << "Operation (1 - Plus, other - Minus): ";
    int user_input;
    std::cin >> user_input;
    if (user_input == 1) operation = add;
    else operation = sub;
    int x = 5, y = 7;
    std::cout << operation(x, y) << std::endl;
    std::cout << make_operation(operation, x, y) << std::endl;

    return 0;
}


int main1()
{
    void (*f1)(int);
    f1 = print_x;
    f1(10);

    // f1 = iprint_x;  // ��������������� �� ���� ��������
    int (*f2)(int) = iprint_x;  // ������ ��� -- ������ ���������

    // f1 = print_c;  // ��������������� �� ���� ���������
    void(*f3)(char) = print_c;  // ������� �� ���� ���������

    f1 = print_y;  // �� - ��� ��������� ���� �� ������ (y ������ �)

    func_void_int f4;   // ����� �� ���������, ��� f1, 
                        // ������ ����� ��������� ����
    f4 = print_x;

    return 0;
}

void print_x(int x) {
    std::cout << x << std::endl;
}

/* ��������� �� ������� (�������������� ���������)
����������-���������, ���������� ����� �������.
 void (*f1)(int);  -- ���������� ���������� � ������ f1, ��� 
   �������� ��������� �� ������� ���� void, ����������� ���� 
   �������� ���� int
 void - ��� �������� �������
 (int) - ��������(�) ������� (����)
 (*f1) - *-������� ���������, f1-��� ����������

 f1 = print_x;  - ������������: � f1 ����������� ����� print_x

 f1(10);  - ����� ������� �� �� ������ (� �������� ���������)
 ---------------------------
 ��������� �� �. ������ ��� ��� ��������, ��� � ���� ����������.
 ������� ��������� �� ������ ������� (� ������� ������ �-�)
  ������������.

*/
