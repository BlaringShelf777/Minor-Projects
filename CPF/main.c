#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define CPFSIZE 11

char *createRandCpf(int size);
void printfCpf(char *cpf);
int validCpf(char *cpf);

int main(){
    // char *cpf = createRandCpf(CPFSIZE);
    // printfCpf(cpf);
    // free(cpf);

    if (validCpf("04049223090"))
        printf("VALID");
    else 
        printf("NOT");

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
}

int validCpf(char *cpf){
    int dig1 = 0, dig2 = 0;

    for (int i = 0, j = CPFSIZE; i < CPFSIZE; i++){
        dig2 += (cpf[i] - '0') * j;
        if (j - 1 > 2)
            dig1 += (cpf[i] - '0') * (j - 1);
        j--;
    }
    dig1 = (dig1 * 10) % 11; dig2 = (dig2 * 10) % 11;
    dig1 = dig1 == 10 ? 0 : dig1; dig2 = dig2 == 10 ? 0 : dig2;

    return cpf[9] - '0' == dig1 && cpf[10] - '0' == dig2;
}

//0 * 11 + 4 * 10 + 0 * 9 + 4 * 8 + 9 * 7 + 2 * 6 + 2 * 5 + 3 * 4 + 0 * 3 + 9 * 2

//0 * 10 + 4 * 09 + 0 * 8 + 4 * 7 + 9 * 6 + 2 * 5 + 2 * 4 + 3 * 3 + 0 * 2






