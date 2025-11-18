#include <stdio.h>
#include <string.h>

#define TAM 100
#define TAM_STR 100

struct Conta {
    int numero;
    char nome[TAM_STR];
    char cpf[TAM_STR];
    char telefone[TAM_STR];
    double saldo;
};

void lerStr(char s[], int t);
int buscar(struct Conta v[], int qtd, int num);
void cadastrarConta(struct Conta v[], int *qtd, int num);
void consultarSaldo(struct Conta v[], int qtd, int num);
void depositar(struct Conta v[], int qtd, int num);
void sacar(struct Conta v[], int qtd, int num);
void listarContas(struct Conta v[], int qtd);

int main() {
    struct Conta contas[TAM];
    int qtd = 0;
    int opcao, num;

    while (1) {
        printf("\n1-Cadastrar\n2-Consultar Saldo\n3-Depositar\n4-Sacar\n5-Listar\n6-Sair\n");
        scanf("%d", &opcao);
        char lixo[TAM_STR];
        lerStr(lixo, TAM_STR);

        if (opcao == 6) break;

        if (opcao == 1) {
            printf("Número da conta:\n");
            scanf("%d", &num);
            lerStr(lixo, TAM_STR);
            cadastrarConta(contas, &qtd, num);
        }
        if (opcao == 2) {
            printf("Número da conta:\n");
            scanf("%d", &num);
            lerStr(lixo, TAM_STR);
            consultarSaldo(contas, qtd, num);
        }
        if (opcao == 3) {
            printf("Número da conta:\n");
            scanf("%d", &num);
            lerStr(lixo, TAM_STR);
            depositar(contas, qtd, num);
        }
        if (opcao == 4) {
            printf("Número da conta:\n");
            scanf("%d", &num);
            lerStr(lixo, TAM_STR);
            sacar(contas, qtd, num);
        }
        if (opcao == 5) {
            listarContas(contas, qtd);
        }
    }

    return 0;
}

void lerStr(char s[], int t) {
    fgets(s, t, stdin);
    int x = strlen(s);
    if (s[x - 1] == '\n') {
        s[x - 1] = '\0';
    }
}

int buscar(struct Conta v[], int qtd, int num) {
    if (qtd == 0) return -1;
    for (int i = 0; i < qtd; i += 1) {
        if (v[i].numero == num) return i;
    }
    return -2;
}

void cadastrarConta(struct Conta v[], int *qtd, int num) {
    int r = buscar(v, *qtd, num);
    if (r >= 0) {
        printf("Número de conta repetido\n");
        return;
    }
    v[*qtd].numero = num;
    printf("Nome:\n");
    lerStr(v[*qtd].nome, TAM_STR);
    printf("CPF:\n");
    lerStr(v[*qtd].cpf, TAM_STR);
    printf("Telefone:\n");
    lerStr(v[*qtd].telefone, TAM_STR);
    printf("Saldo inicial:\n");
    scanf("%lf", &v[*qtd].saldo);
    char lixo[TAM_STR];
    lerStr(lixo, TAM_STR);
    *qtd += 1;
}

void consultarSaldo(struct Conta v[], int qtd, int num) {
    int r = buscar(v, qtd, num);
    if (r < 0) {
        printf("Conta não cadastrada\n");
    } else {
        printf("Saldo: %.2f\n", v[r].saldo);
    }
}

void depositar(struct Conta v[], int qtd, int num) {
    int r = buscar(v, qtd, num);
    if (r < 0) {
        printf("Conta não cadastrada\n");
    } else {
        double valor;
        printf("Valor do depósito:\n");
        scanf("%lf", &valor);
        v[r].saldo += valor;
        printf("Depósito realizado\n");
    }
}

void sacar(struct Conta v[], int qtd, int num) {
    int r = buscar(v, qtd, num);
    if (r < 0) {
        printf("Conta não cadastrada\n");
    } else {
        double valor;
        printf("Valor do saque:\n");
        scanf("%lf", &valor);
        if (valor <= v[r].saldo) {
            v[r].saldo -= valor;
            printf("Saque realizado\n");
        } else {
            printf("Saldo insuficiente\n");
        }
    }
}

void listarContas(struct Conta v[], int qtd) {
    for (int i = 0; i < qtd; i += 1) {
        printf("%d - %s - %s\n", v[i].numero, v[i].nome, v[i].telefone);
    }
}