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
        printf("\n1 - Economica\n");
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

int main(void) {

    double distancia;
    double peso;
    int modalidade;

    printf("=== SIMULADOR DE ENTREGAS ===\n\n");

    distancia = obterDistancia();
    peso = obterPeso();
    modalidade = obterModalidade();

    printf("\nDados recebidos com sucesso!\n");
    printf("Distancia: %.2f km\n", distancia);
    printf("Peso: %.2f kg\n", peso);
    printf("Modalidade: %d\n", modalidade);

    return 0;
}