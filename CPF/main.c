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
    
    if (validCpf(cpf))
        printfCpf(cpf);
    else
        printf("Invalid CPF.");

    return 0;
}

// Creates a CPF randomly:
char *createRandCpf(int size){
    char *cpf = (char *) malloc(sizeof(char) * (size + 1));

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        cpf[i] = '0' + rand() % 10;

    return cpf;
}

// Prints a CPF with format
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

// Validates a CPF
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

// Creates a CPF by an algorithm 
char *createCpf(){
    char *cpf = (char *) malloc(sizeof(char) * (CPFSIZE + 1));
    int dig1 = 0, dig2 = 0;

    //creates the CPF's 10 firt digits
    srand(time(NULL));
    for (int i = 0, j = 10; i < 9; i++){
        cpf[i] = '0' + rand() % 10;
        dig1 += (cpf[i] - '0') * j;
        dig2 += (cpf[i] - '0') * (j + 1);
        j--;
    }
    dig1 = (dig1 * 10) % 11; dig1 = dig1 == 10 ? 0 : dig1;
    cpf[9] = '0' + dig1;
    // Creates the last DIgit
    dig2 += dig1 * 2;
    dig2 = (dig2 * 10) % 11; dig2 = dig2 == 10 ? 0 : dig2;
    cpf[10] = '0' + dig2;

    return cpf;
}





