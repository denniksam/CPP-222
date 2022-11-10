#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void to_lower(char* str) {
    // ������ ��� ������� ����� �� �����, ������ ������� �� ��������
    // ������� A-Z ����� ���� 65-90, a-z : 97-122, ������� ����� - 32
    if (str == NULL) return;

    size_t length = strlen(str);
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;   // 'a' - 'A';
        }
    }
}

int word_count(char* str, const char* word) {
    // ������� ���-�� ��������� ����� word � ������ str
    // ����: ���� ������ ���������� place = strstr() -> �������� ���������
    // �� ������ ��������� (place). ����� �������� ����� c �������
    // ����� (���������� �������) place = strstr(place+1, word)
    if (str == NULL || word == NULL) return -1;

    int res = 0;
    char* place;
    place = strstr(str, word);  // TODO: ���������� � ������
    if (place != NULL)
    {
        res++;
        while (place = strstr(place + 1, word)) res++;
    }
    return res;
}

int main() {
    // strstr - ����� ������ � ������
    // ������� - ��������� �� ������ ���������� ��� NULL ���� ��� ����������
    // ������: ����� ����. ������������ ������ ������.
    //  ��������� ��������� ���� �� � ��������� ������ ����� 'bomb'
    const size_t BUFFER_SIZE = 100;
    char* str = new char[BUFFER_SIZE];
    puts("Enter string: ");
    std::cin.getline(str, BUFFER_SIZE);
    // ����� ��������� ����������� � ������� ��������
    to_lower(str);
    // ���� ��������
    if (strstr(str, "bomb") != NULL) {
        printf("Word 'bomb' found in phrase %d times", 
            word_count(str, "bomb"));
        
    }
    else {
        printf("Phrase clear");
    }

    return 0;
}

int main2() {
    // �������: ������������ ������ ������, ����� ��� ��������� ��������
    const size_t BUFFER_SIZE = 100;
    char* str = new char[BUFFER_SIZE];
    puts("Enter string: ");
    std::cin.getline(str, BUFFER_SIZE);
    // for (int i = strlen(str) - 1; i >= 0; i--) // ������ �����
    // {                                          // ������2 - 
    //     putchar(str[i]);                       // "�����������"
    // }                                          // ������ str
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++)
    {
        // ����������� ������ - �������� ������� (������-���������)
        //  (������-�������������) ...
        // str[0]<->str[len-1]   str[1]<->str[len-2]
        // str[i]<->str[len-1-i]
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
    puts(str);
    return 0;
}

int main1()
{
    printf("Hello World!\n");
    printf("Hello %s!\n", "World");
    // for(int x = 10; x < 100; ++x)
    int x = 30;
    printf("num = %03d, char = %c, hex = %x \n", x, x, x);
    float y = 1.0 / 3;
    char* str = new char[100];
    sprintf(str, "y = %.2f\n", y);
    printf(str);
    puts("Enter number: ");
    scanf("%d", &x);
    printf("x = %d", x);

    return 0;
}
/*
printf - print format, placeholder - ����� ��� �����������
printf("Hello %s!\n", "World");
               |          |
           placeholder   ������ ��� �����������
%d - decimal
%c - char
%s - string
%x - hex
%f - float

sprintf - ������ ��� ������������ ������
*/
