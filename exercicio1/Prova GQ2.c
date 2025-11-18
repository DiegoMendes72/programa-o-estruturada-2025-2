#include <stdio.h>
#include <string.h>

#define TAM 100

struct Categoria {
    int codigo;
    char nome[50];
};

struct Produto {
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria;
    int preco;
};

void cadastrarCategoria(struct Categoria v[], int *qtd);
void imprimirCategorias(struct Categoria v[], int qtd);
void cadastrarProduto(struct Produto vp[], int *qtdProdutos, struct Categoria vc[], int qtdCategorias);
void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias);
void selectionSortPorDescricao(struct Produto v[], int qtd);
void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x);

int main() {
    struct Categoria categorias[TAM];
    struct Produto produtos[TAM];

    int qtdCategorias = 0;
    int qtdProdutos = 0;

    cadastrarCategoria(categorias, &qtdCategorias);
    imprimirCategorias(categorias, qtdCategorias);

    cadastrarProduto(produtos, &qtdProdutos, categorias, qtdCategorias);
    imprimirProdutos(produtos, qtdProdutos, categorias, qtdCategorias);

    printf("\nOrdenando produtos por descricao...\n");
    selectionSortPorDescricao(produtos, qtdProdutos);
    imprimirProdutos(produtos, qtdProdutos, categorias, qtdCategorias);

    char busca[256];
    printf("\nDigite a descricao do produto para buscar: ");
    scanf(" %[^\n]", busca);
    buscaBinariaPorDescricao(produtos, qtdProdutos, busca);

    return 0;
}

void cadastrarCategoria(struct Categoria v[], int *qtd) {
    if (*qtd >= TAM) {
        printf("Nao ha espaco para cadastrar mais categorias.\n");
        return;
    }

    int codigoDigitado;
    printf("Digite o codigo da categoria: ");
    scanf("%d", &codigoDigitado);

    int i;
    for (i = 0; i < *qtd; i += 1) {
        if (v[i].codigo == codigoDigitado) {
            printf("Codigo ja existe.\n");
            return;
        }
    }

    v[*qtd].codigo = codigoDigitado;

    printf("Digite o nome da categoria: ");
    scanf(" %[^\n]", v[*qtd].nome);

    *qtd += 1;
}

void imprimirCategorias(struct Categoria v[], int qtd) {
    int i;
    for (i = 0; i < qtd; i += 1) {
        printf("Codigo: %d - Nome: %s\n", v[i].codigo, v[i].nome);
    }
}

void cadastrarProduto(struct Produto vp[], int *qtdProdutos, struct Categoria vc[], int qtdCategorias) {
    if (*qtdProdutos >= TAM) {
        printf("Nao ha espaco para cadastrar mais produtos.\n");
        return;
    }

    int codigoCategoria;
    printf("Digite o codigo do produto: ");
    scanf("%d", &vp[*qtdProdutos].codigo);

    printf("Digite o titulo do produto: ");
    scanf(" %[^\n]", vp[*qtdProdutos].titulo);

    printf("Digite a descricao do produto: ");
    scanf(" %[^\n]", vp[*qtdProdutos].descricao);

    printf("Digite o codigo da categoria: ");
    scanf("%d", &codigoCategoria);

    int encontrou = 0;
    int i;
    for (i = 0; i < qtdCategorias; i += 1) {
        if (vc[i].codigo == codigoCategoria) {
            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        printf("Categoria nao encontrada. Produto nao cadastrado.\n");
        return;
    }

    vp[*qtdProdutos].categoria = codigoCategoria;

    printf("Digite o preco do produto em centavos (ex: 1999 = R$19.99): ");
    scanf("%d", &vp[*qtdProdutos].preco);

    *qtdProdutos += 1;
}

void imprimirProdutos(struct Produto vp[], int qtdProdutos,
                      struct Categoria vc[], int qtdCategorias) {

    int i, j;
    for (i = 0; i < qtdProdutos; i += 1) {
        printf("\nCodigo: %d\n", vp[i].codigo);
        printf("Titulo: %s\n", vp[i].titulo);
        printf("Descricao: %s\n", vp[i].descricao);

        char nomeCategoria[50] = "Nao encontrada";
        for (j = 0; j < qtdCategorias; j += 1) {
            if (vc[j].codigo == vp[i].categoria) {
                strcpy(nomeCategoria, vc[j].nome);
                break;
            }
        }

        printf("Categoria: %s\n", nomeCategoria);

        double precoReal = vp[i].preco / 100.0;
        printf("Preco: R$ %.2f\n", precoReal);
    }
}

void selectionSortPorDescricao(struct Produto v[], int qtd) {
    int i, j, min;
    for (i = 0; i < qtd - 1; i += 1) {
        min = i;
        for (j = i + 1; j < qtd; j += 1) {
            if (strcmp(v[j].descricao, v[min].descricao) < 0) {
                min = j;
            }
        }
        if (min != i) {
            struct Produto temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x) {
    int inicio = 0;
    int fim = qtd - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(x, v[meio].descricao);

        if (cmp == 0) {
            printf("Produto encontrado:\n");
            printf("Codigo: %d\n", v[meio].codigo);
            printf("Titulo: %s\n", v[meio].titulo);
            printf("Descricao: %s\n", v[meio].descricao);
            return;
        }

        if (cmp < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    printf("Produto nao encontrado.\n");
}