#include <stdio.h>
#include <string.h>

#define TAM 10

void imprimirLetraPorLetra(char str[]);
void imprimirTabelaAsc(char str[]);

int main(){
    char nome[TAM] = "Ola Turma!";

    imprimirLetraPorLetra(nome);
    printf("\n\n");
    imprimirTabelaAsc(nome);
    return 0;
}

void imprimirLetraPorLetra(char str[]){
    int tam = strlen(str);
    for(int i = 0; i < TAM; i += 1){
       printf("'%c' %3d\n", str[i], str[i]);
   }
}

void imprimirTabelaAsc(char str[]){
    int tam = strlen(str);
    for(int i = 32; i < 128; i += 1){
        printf("'%c' %3d\n", str[i], str[i]);
    }
}