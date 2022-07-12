#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

char* str_input();
char* symb_input();

int main() {
    setlocale(LC_ALL, "rus");

    char *string = NULL;
    char *dividers = NULL;
    char *vowels = NULL;
    int vowels_count[6], i, j, repeat;

    do {
        fflush(stdin);
        system("cls");

        for(i = 0; i<6; i++)
            vowels_count[i]=0;

        printf("������� �������� ������:\n");
        string = str_input();
        puts("");
        printf("������� ������ ������������:\n");
        dividers = symb_input();
        puts("");
        printf("������� ������� �����:\n");
        vowels = symb_input();

        for(j = 0; j < strlen(vowels); j++){
            for (i = 0; i < strlen(string); i++){
                if (vowels[j] == string[i])
                    vowels_count[j] += 1;
            }
        }

        puts("");
        printf("��������� �������� ���������� �������� �������:\n");
        for(i = 0; i < strlen(vowels); i++){
            printf("%c ", vowels[i]);
            for(j = 0; j < vowels_count[i]; j++)
                printf("*");
            printf("\n");
        }

        puts("");
        printf("��� ��������� ������ � ���������� ������� 1\n");
        scanf("%d", &repeat);

        free(string);
        string = NULL;
        free(dividers);
        dividers = NULL;
        free(vowels);
        vowels = NULL;

    }while(repeat == 1);

    return 0;
}


char* str_input(){
    char* current_str = NULL;
    int n, w;
    w = 0;

    for(n = 0; w != 1; n ++){
        current_str =(char*)realloc(current_str, (n+1)*sizeof(char));
        *(current_str+n) = getchar();
        if(*(current_str+n) == '\n'){
                w = 1;
                current_str[n] = '\0';
        }
    }

    return current_str;
}


char* symb_input(){
    char* symbols = NULL;
    int n, w;
    char current;
    n = 0;
    w = 0;

    do{
        symbols =(char*)realloc(symbols, (n+1)*sizeof(char));
        current = getchar();
        if(current == '\n' || current == ' '){
            if(current == '\n'){
                w = 1;
                symbols[n] = '\0';
            }
        }
        else{
            symbols[n] = current;
            n++;
        }
    }while(w != 1);

    return symbols;
}
