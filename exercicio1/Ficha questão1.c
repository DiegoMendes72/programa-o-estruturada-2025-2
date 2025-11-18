#include <stdio.h>
#include <string.h>

#define TAM 26
#define TAM_NOME 100

struct Estado {
    char nome[TAM_NOME];
    int veiculos;
    int acidentes;
};

void lerStr(char s[], int tam);
void preencherEstados(struct Estado v[], int tam);
void maiorMenorAcidentes(struct Estado v[], int tam, int *pMaior, int *pMenor);
double percentual(struct Estado v[], int pos);
double mediaAcidentes(struct Estado v[], int tam);
void acimaDaMedia(struct Estado v[], int tam, double media);

int main() {
    struct Estado estados[TAM];
    int posMaior, posMenor;

    preencherEstados(estados, TAM);
    maiorMenorAcidentes(estados, TAM, &posMaior, &posMenor);

    printf("Maior número de acidentes: %s (%d)\n", estados[posMaior].nome, estados[posMaior].acidentes);
    printf("Menor número de acidentes: %s (%d)\n", estados[posMenor].nome, estados[posMenor].acidentes);

    printf("\nPercentuais:\n");
    for (int i = 0; i < TAM; i += 1) {
        double p = percentual(estados, i);
        printf("%s: %.2f%%\n", estados[i].nome, p);
    }

    double media = mediaAcidentes(estados, TAM);
    printf("\nMédia de acidentes do país: %.2f\n", media);

    printf("\nEstados acima da média:\n");
    acimaDaMedia(estados, TAM, media);

    return 0;
}

void lerStr(char s[], int tam) {
    fgets(s, tam, stdin);
    int t = strlen(s);
    if (s[t - 1] == '\n') {
        s[t - 1] = '\0';
    }
}

void preencherEstados(struct Estado v[], int tam) {
    char lixo[TAM_NOME];
    for (int i = 0; i < tam; i += 1) {
        printf("Nome do estado:\n");
        lerStr(v[i].nome, TAM_NOME);
        printf("Número de veículos:\n");
        scanf("%d", &v[i].veiculos);
        printf("Número de acidentes:\n");
        scanf("%d", &v[i].acidentes);
        lerStr(lixo, TAM_NOME);
    }
}

void maiorMenorAcidentes(struct Estado v[], int tam, int *pMaior, int *pMenor) {
    *pMaior = 0;
    *pMenor = 0;
    for (int i = 1; i < tam; i += 1) {
        if (v[i].acidentes > v[*pMaior].acidentes) {
            *pMaior = i;
        }
        if (v[i].acidentes < v[*pMenor].acidentes) {
            *pMenor = i;
        }
    }
}

double percentual(struct Estado v[], int pos) {
    return (v[pos].acidentes * 100.0) / v[pos].veiculos;
}

double mediaAcidentes(struct Estado v[], int tam) {
    int soma = 0;
    for (int i = 0; i < tam; i += 1) {
        soma += v[i].acidentes;
    }
    return soma / (double) tam;
}

void acimaDaMedia(struct Estado v[], int tam, double media) {
    for (int i = 0; i < tam; i += 1) {
        if (v[i].acidentes > media) {
            printf("%s\n", v[i].nome);
        }
    }
}