#include <stdio.h>

double obterDistancia(void) {
    double distancia;

    do {
        printf("Digite a distancia da entrega (km): ");
        scanf("%lf", &distancia);

        if (distancia <= 0) {
            printf("Erro: a distancia deve ser maior que zero.\n");
        }

    } while (distancia <= 0);

    return distancia;
}

double obterPeso(void) {
    double peso;

    do {
        printf("Digite o peso da entrega (kg): ");
        scanf("%lf", &peso);

        if (peso <= 0) {
            printf("Erro: o peso deve ser maior que zero.\n");
        }

    } while (peso <= 0);

    return peso;
}

int obterModalidade(void) {
    int modalidade;

    do {
        printf("\nModalidades:\n");
        printf("1 - Economica\n");
        printf("2 - Expressa\n");
        printf("3 - Prioritaria\n");
        printf("Escolha a modalidade: ");
        scanf("%d", &modalidade);

        if (modalidade < 1 || modalidade > 3) {
            printf("Erro: modalidade invalida.\n");
        }

    } while (modalidade < 1 || modalidade > 3);

    return modalidade;
}

int obterProtecao(void) {
    int protecao;

    do {
        printf("Deseja contratar protecao? (1 = Sim / 0 = Nao): ");
        scanf("%d", &protecao);

        if (protecao != 0 && protecao != 1) {
            printf("Erro: digite apenas 0 ou 1.\n");
        }

    } while (protecao != 0 && protecao != 1);

    return protecao;
}

int obterTentativas(void) {
    int tentativas;

    do {
        printf("Digite a quantidade de tentativas adicionais: ");
        scanf("%d", &tentativas);

        if (tentativas < 0) {
            printf("Erro: a quantidade nao pode ser negativa.\n");
        }

    } while (tentativas < 0);

    return tentativas;
}

int main(void) {

    double distancia;
    double peso;

    int modalidade;
    int protecao;
    int tentativas;

    printf("====================================\n");
    printf("       SIMULADOR DE ENTREGAS\n");
    printf("====================================\n\n");

    distancia = obterDistancia();
    peso = obterPeso();
    modalidade = obterModalidade();
    protecao = obterProtecao();
    tentativas = obterTentativas();

    printf("\n====================================\n");
    printf("        DADOS DA ENTREGA\n");
    printf("====================================\n");

    printf("Distancia: %.2f km\n", distancia);
    printf("Peso: %.2f kg\n", peso);
    printf("Modalidade: %d\n", modalidade);
    printf("Protecao: %d\n", protecao);
    printf("Tentativas adicionais: %d\n", tentativas);

    printf("\nDados recebidos com sucesso!\n");

    return 0;
}

