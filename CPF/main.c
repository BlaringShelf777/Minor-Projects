#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define CPFSIZE 11

char *createRandCpf(int size);
void printfCpf(char *cpf);
int validCpf(char *cpf);
char *createCpf();

int main(){
    char *cpf = createCpf();
    
    if (validCpf("04049223090"))
        printfCpf(cpf);
    else
        printf("Invalid CPF.");

    return 0;
}

// Create CPF:

char *createRandCpf(int size){
    char *cpf = (char *) malloc(sizeof(char) * (size + 1));

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        cpf[i] = '0' + rand() % 10;

    return cpf;
}

void printfCpf(char *cpf){
    // Prints a standard CPF format: xxx.xxx.xxx-xx
    for (int i = 0; i < CPFSIZE; i++){
        switch (i){
            case 9:
                printf("-%c", cpf[i]);
            break;
            case 3:
            case 6:
                printf(".%c", cpf[i]);
            break;
            default:
                printf("%c", cpf[i]);
            break;
        }
    }
    printf("\n");
}

int validCpf(char *cpf){
    int dig1 = 0, dig2 = 0;

    for (int i = 0, j = CPFSIZE; i < CPFSIZE - 1; i++){
        dig2 += (cpf[i] - '0') * j;
        if (j - 1 > 1)
            dig1 += (cpf[i] - '0') * (j - 1);
        j--;
    }
    dig1 = (dig1 * 10) % 11; dig2 = (dig2 * 10) % 11;
    dig1 = dig1 == 10 ? 0 : dig1; dig2 = dig2 == 10 ? 0 : dig2;

    return cpf[9] - '0' == dig1 && cpf[10] - '0' == dig2;
}

char *createCpf(){
    char *cpf = (char *) malloc(sizeof(char) * (CPFSIZE + 1));
    int dig1 = 0, dig2 = 0;

    srand(time(NULL));
    for (int i = 0, j = 10; i < 9; i++){
        cpf[i] = '0' + rand() % 10;
        dig1 += (cpf[i] - '0') * j;
        j--;
    }
    dig1 = (dig1 * 10) % 11; dig1 = dig1 == 10 ? 0 : dig1;
    cpf[9] = '0' + dig1;
    for (int i = 0, j = 11; i < 10; i++){
        dig2 += (cpf[i] - '0') * j;
        j--;
    }
    dig2 = (dig2 * 10) % 11; dig2 = dig2 == 10 ? 0 : dig2;
    cpf[10] = '0' + dig2;

    return cpf;
}





