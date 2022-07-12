#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "russian");
    int number, amount, dividers, i, repeat;
        /* number Ц переменна€, хран€ща€ введенное число,
        amount - счетчик простых чисел в последовательности,
        dividers Ц счетчик делителей числа,
        i - счетчик дл€ цикла,
        repeat - переменна€ дл€ повторени€ программы*/
    do {
    amount = 0;
    printf("¬ведите последовательность чисел:\n");
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
                    printf("„исло должно быть положительным.\n");
                else
                    printf("¬вод последовательности закончен.\n");
            }
        } while ( number != 0);
        printf(" оличество простых чисел в последовательности:\n%d\n", amount);
        printf("ƒл€ продолжени€ работы программы введите 1.\nƒл€ завершени€ работы программы введите 0.\n");
        scanf("%d", &repeat);
    } while (repeat == 1);

    return 0;
}
