#include <stdio.h>

#define TAM 30

void preencherNota1(double vetNota1[], int tam);
void preencherNota2(double vetNota2[], int tam);
void calcularMediaPeso(double vetMedia[], double vetNota1[], double vetNota2[], int tam);
double calcularMedia(double vetMedia[], int tam);
void imprimirNotasEMediaAcimaMedia(double vetMedia[], double MediaTurma, int tam);

int main(){
    double nota1[TAM], nota2[TAM], media[TAM];
    
    preencherNota1(nota1, TAM);
    printf("\n");
    preencherNota2(nota2, TAM);
    printf("\n");
    calcularMediaPeso(media, nota1, nota2, TAM);
    double mediaTurma = calcularMedia(media, TAM);
    printf("A media da turma é %.2f\n", mediaTurma);
    imprimirNotasEMediaAcimaMedia(media, mediaTurma, TAM);
    return 0;
}

void preencherNota1(double vetNota1[], int tam){
    for(int i = 0; i < tam; i += 1){
        printf("Digite a primeira nota do aluno %d: ", i + 1);
        scanf("%lf", &vetNota1[i]);
    }
}

void preencherNota2(double vetNota2[], int tam){
    for(int i = 0; i < tam; i += 1){
        printf("Digite a segunda nota do aluno %d: ", i + 1);
        scanf("%lf", &vetNota2[i]);
    }
}

void calcularMediaPeso(double vetMedia[], double vetNota1[], double vetNota2[], int tam){
    for(int i = 0; i < tam; i += 1){
        vetMedia[i] = ((vetNota1[i] * 2) + (vetNota2[i] * 3))/5.0;
    }
}

double calcularMedia(double vetMedia[], int tam){
    double soma = 0.0;
    for(int i = 0; i < tam; i += 1){
        soma += vetMedia[i];
    }
    return soma / tam;
}

void imprimirNotasEMediaAcimaMedia(double vetMedia[], double MediaTurma, int tam){
    for(int i = 0; i < tam; i += 1){
        if(vetMedia[i] > MediaTurma){
            printf("Aluno %d acima da média: %.2f com: %.2f na média\n", i + 1, MediaTurma, vetMedia[i]);
        }
    }
}