#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "russian");
    int number, amount, dividers, i, repeat;
        /* number � ����������, �������� ��������� �����,
        amount - ������� ������� ����� � ������������������,
        dividers � ������� ��������� �����,
        i - ������� ��� �����,
        repeat - ���������� ��� ���������� ���������*/
    do {
    amount = 0;
    printf("������� ������������������ �����:\n");
        do {
            scanf("%d", &number);
            if (number > 0) {
                dividers = 0;
                for (i = 2; i*i <= number; i++) {
                    if (number % i == 0)
                        dividers++;
                }
                if (dividers == 0)
                    ++amount;
            }
            else {
                if (number != 0)
                    printf("����� ������ ���� �������������.\n");
                else
                    printf("���� ������������������ ��������.\n");
            }
        } while ( number != 0);
        printf("���������� ������� ����� � ������������������:\n%d\n", amount);
        printf("��� ����������� ������ ��������� ������� 1.\n��� ���������� ������ ��������� ������� 0.\n");
        scanf("%d", &repeat);
    } while (repeat == 1);

    return 0;
}
