#include <stdio.h>
#include <locale.h>
#define N 20

int main() {
	setlocale(LC_ALL, "russian");
	int matrix[N][N+1];
	int repeat, input, i, j, amount, str, col, number;
	/*  repeat - переменная для повтора программы;
        input - переменная для отслеживания введенного размера матрицы;
        i, j - служебные переменные для циклов;
        amount - переменная-счетчик количества единиц в строке;
        str, col - входные данные о размере матрицы;
        number - переменная для обработки текущего элемента матрицы;
    */

	do {
		printf("Введите количество строк и столбцов матрицы.\nЗначения не могут превышать %d.\n", N);
        do{
            scanf("%d %d", &str, &col);
            if ((str > N) | (str <= 0) | (col > N) | (col <= 0)) {
                printf("Введённые значения некорректны. Повторите ввод\n");
                str = 0;
                col = 0;
            }
            else {
                input = 1;
            }
        } while (input != 1);

        printf("Введите элементы матрицы. Допустимные значения 0 и 1\n");
        for (i = 0; i < str; i++) {
            j = 0;
            do {
                scanf("%d", &number);
                if ((number == 1) | (number == 0)) {
                    matrix[i][j] = number;
                    j++;
                }
                else {
                    printf("Элемент не удовлетворяет условию. Повторите ввод.\n");
                }
            } while (j < col);
        }

        printf("Контрольный вывод матрицы:\n");
        for (i = 0; i < str; i++){
            for (j = 0; j < col; j++){
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        for (i = 0; i < str; i++){
            amount = 0;
            for (j = 0; j < col; j++){
                if (matrix[i][j] == 1){
                    amount++;
                }
            }
            if (amount % 2 == 1){
                    matrix[i][col] = 1;
            }
            else {
                matrix[i][col] = 0;
            }
        }

        printf("Вывод результата:\n");
        for (i = 0; i < str; i++){
            for (j = 0; j <= col; j++){
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

		printf("Для повторного выполнения программы введите 1.\nДля завершения работы введите 0.\n");
		scanf("%d", &repeat);
		printf("\n");
	} while (repeat == 1);

    return 0;
}
