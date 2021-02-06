#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define CPFSIZE 11

char *createRandCpf(int size);

int main(){
    
    char *cpf = createRandCpf(CPFSIZE);
    printf("> %s\n", cpf);


    return 0;
}

// Create CPF:

char *createRandCpf(int size){
    char *cpf = (char *) malloc(sizeof(char) * size);

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        cpf[i] = '0' + rand() % 10;

    return cpf;
}