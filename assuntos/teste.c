#include <stdio.h>

int main() {
    int idade;
    double peso, altura, imc;

    printf("digite a sua idade:\n ");
    scanf("%d", &idade);

    printf("Digite o seu peso: \n");
    scanf("%lf", &peso);

    printf("Digite a sua altura: \n");
    scanf("%lf", &altura);

    imc = peso / (altura * altura);

    return 0;
}