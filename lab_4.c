#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <math.h>

int Menu();
int **matrix_input(int*, int);
void matrix_output(int, int, int**);
int **matrix_gen(int*, int, int**);
void matrix_free(int**, int);

int main(void) {
	setlocale(LC_ALL, "RUS");
	int **mas1, **mas2, rows, new_rows, *rows_adress, col, Q, check, check_2;
    mas1= NULL;
    mas2 = NULL;
    rows = 1;
    check = 0;
    check_2 = 0;
	do {
			Q = Menu();
			switch(Q) {
					case 1:
								system("cls");
                                matrix_free(mas1, rows);
								matrix_free(mas2, rows);
                                printf("Введите кол-во столбцов матрицы (целые положительные числа)\n");
                                do {
                                    scanf("%d", &col);
                                    if (col<=0){
                                        printf("Кол-во стобцов это целые положительные числа, Введите кол-во повторно!\n");
                                    }
                                } while (col<=0);
								rows_adress = &rows;
								mas1 = matrix_input(rows_adress, col);
								check = 1;
								check_2 = 0;
								break;

					case 2:
								system("cls");
								if(check) {
									 printf("Контрольный вывод элементов массива\n");
									 matrix_output(rows, col, mas1);
                                }
								else {
                                     printf("Для начала введите матрицу, выбрав 1 пункт в меню!\n");
                                }
                                system("pause");
                                break;

					case 3:
								system("cls");
								new_rows = rows;
								rows_adress = &new_rows;
								if(check) {
									 mas2 = matrix_gen(rows_adress, col, mas1);
									 printf("Результат сформирован\n");
									 check_2 = 1;
                                }
                                else {
                                     printf("Результат не может быть сформирован\n");
                                     printf("Для начала введите матрицу, выбрав 1 пункт в меню!\n");
                                }
                                system("pause");
                                break;

					case 4:
								system("cls");
								if(check != 1) {
									printf("Для начала введите матрицу, выбрав 1 пункт в меню!\n");
								}
								else {
                                    if(check_2 != 1) {
                                        printf("Результат не сформирован\n");
                                    }
                                    else {
                                        printf("Вывод сформированной матрицы:\n\n Если поле пустое, значит ни одна строка исходной матрицы не удовлетворяет условию.\n Попробуйте изменить параметры.\n");
                                        matrix_output(new_rows,col, mas2);
                                    }
                                }
                                system("pause");
                                break;
					case 5:
								system("cls");
								puts("Завершение работы программы.");
								system("pause");
								break;
					default:
									printf("Что-то пошло не так, введите пункт меню повторно\n");
									system("pause");
            }
    } while (Q != 5);
    matrix_free(mas1, rows);
    matrix_free(mas2, rows);

    return 0;
}


int Menu() {
		int Q;
		system("cls");
		puts("Главное меню");
		puts("1 - Ввод матрицы");
		puts("2 - Показать введённую матрицу");
		puts("3 - Обработка исходной матрицы ");
		puts("4 - Показать обработанную матрицу");
		puts("5 - Выход");
		printf("Введите номер пункта - ");
		scanf("%d", &Q);
		printf("\n");

        return Q;
}


int **matrix_input(int* rows, int col) {
	int i, j, **mas, min_in_row;

    mas = (int**)malloc(*rows*sizeof(int*));
    min_in_row = 2147483647;
    printf("Введите элементы первой строки матрицы\n");

    for (i = 0; i < col; i++) {
        *(mas+i) = (int*)malloc(col*sizeof(int));
        scanf("%d", &mas[0][i]);
        if ((fabs(mas[0][i])) < min_in_row)
            min_in_row = fabs(mas[0][i]);
    }
    *rows = min_in_row;
    mas = (int**)realloc(mas, *rows*sizeof(int*));
    for (i = 1; i < *rows; i++) {
        *(mas+i) = (int*)malloc(col*sizeof(int));
        printf("Введите элементы %d строки матрицы через пробел\n", i+1);
        for (j = 0; j < col; j++){
            scanf("%d", &mas[i][j]);
        }
    }

    return mas;
}


void matrix_output(int rows, int col, int** mas){
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j<col; j++) {printf("%d ", mas[i][j]);}
    }
    puts("\n");
}


int **matrix_gen(int* rows, int col, int** mas1) {
    int i, j, **mas2 = NULL, left, right, flag1, flag2, temp, string;
    flag1 = 0;
    flag2 = 0;
    printf("Введите интервал (два целых положительных числа)\n");
    do {
        printf("Введите левую границу интервала\n");
        scanf("%d", &left);
        if ((left > 0) && (left <= col)){
            flag1 = 1;
        }
        else{
            printf("Некорректное значение. Введите повторно\n");
        }
    } while (flag1 != 1);

    do{
        printf("Введите правую границу интервала\n");
        scanf("%d", &right);
        if ((right > left) && (right <= (col+1))){
            flag2 = 1;
        }
        else {
            printf("Некорректное значение. Введите повторно\n");
        }
    } while (flag2 != 1);

	string = 0;
    mas2 = (int**)malloc(1*sizeof(int*));
    for (i = 0; i < *rows; i++){
        temp = 0;
        for (j = (left - 1); j < (right-1); j++){
            if (mas1[i][j] <= mas1[i][j+1]){
                temp++;
            }
        }
        if (temp == (right-left)){
             mas2 = (int**)realloc(mas2, (string+1)*sizeof(int*));
            *(mas2+string) = (int*)malloc(col*sizeof(int));
            for (j = 0; j < col; j++){
                mas2[string][j] = mas1[i][j];
            }
            string++;
        }
     }
    *rows = string;

    return mas2;
}


void matrix_free(int** mas, int rows){
    if (mas!=NULL){
		 for (int i = 0; i<rows; i++){
			 free(*(mas+i));
		 }
         free(mas);
         mas = NULL;
    }
}
