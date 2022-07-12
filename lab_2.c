#include <stdio.h>
#include <locale.h>
#define N 10

int main() {
    setlocale(LC_ALL, "russian");
    int range[N];
    int repeat, i, sum, counter, less_than_sum, end_of_range, counter_pos, exit, result;
    /*repeat - вспомогательная переменная для повторения работы программы
      i - вспомогательная переменная для циклов
      sum - сумма элементов последовательности
      counter - счетчик элементов последовательности
      less_than_sum - булева переменная для прекращения ввода последовательности
      end_of_range - булева переменная для определения выхода за максимальную длину последовательности
      counter_pos - счетчик положительных элементов последовательности
      exit - булева переменная для прекращения работы программы
      result - переменная с результатом работы  */

    do {
        printf("Введите последовательность чисел.\nКоличество элементов последовательности не может превышать %d.\n", N);
        do {
            counter = 0;
            counter_pos = 0;
            end_of_range = 0;
            sum = 0;
            less_than_sum = 0;
            exit = 0;
            do {
                if (counter != N) {
                    scanf("%d", &range[counter]);
                    if (counter < 2) {
                        sum += range[counter];
                    }
                    else if (range[counter] < sum) {
                        less_than_sum = 1;
                    }
                    else {
                        sum += range[counter];
                    }
                    counter++;
                }
                else {
                    end_of_range = 1;
                }
            } while ((less_than_sum != 1) && (end_of_range != 1));
            if (end_of_range != 1) {
                printf("Конец последовательности.\n");
                result = 1;
                for (i = 0; i < counter; i++) {
                    if (range[i] > 0) {
                        result *= range[i];
                        counter_pos++;
                    }
                }
                printf("Вывод элементов последовательности:\n");
                for (i = 0; i < counter; i++) {
                    printf("%d ", range[i]);
                }
                printf("\n");
                if (counter_pos > 1) {
                    printf("Произведение положительных чисел последовательности равно %d.\n", result);
                    exit = 1;
                }
                else if (counter_pos == 1) {
                    printf("В последовательности был всего один положительный элемент (%d).\n",result);
                    exit = 1;
                }
                else {
                    printf("В последовательности не было положительных элементов.\n");
                    exit = 1;
                }
            }
            else {
                printf("Количество элементов последовательности превысило максимум (%d).\n", N);
                exit = 1;
            }
        } while (exit != 1);
        printf("Для повторного выполнения программы введите 1.\nДля завершения работы введите 0.\n");
        scanf("%d", &repeat);
        printf("\n");
    } while (repeat == 1);

    return 0;
}
