#include <stdio.h>

#define TARIFA_KM 1.20
#define VALOR_PROTECAO 7.50
#define VALOR_TENTATIVA 4.00

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

double obterValorBase(double distancia) {
    if (distancia <= 5) {
        return 8.00;
    } else if (distancia <= 15) {
        return 12.00;
    } else if (distancia <= 30) {
        return 18.00;
    } else {
        return 25.00;
    }
}

double obterPercentualPeso(double peso) {
    if (peso <= 2) {
        return 0.00;
    } else if (peso <= 5) {
        return 0.05;
    } else if (peso <= 10) {
        return 0.10;
    } else {
        return 0.20;
    }
}

double obterPercentualModalidade(int modalidade) {
    if (modalidade == 1) {
        return 0.00;
    } else if (modalidade == 2) {
        return 0.15;
    } else {
        return 0.30;
    }
}

double calcularValorFinal(
    double distancia,
    double peso,
    int modalidade,
    int protecao,
    int tentativas
) {
    double valorBase;
    double subtotal;
    double adicionalPeso;
    double adicionalModalidade;
    double adicionalProtecao;
    double adicionalTentativas;

    valorBase = obterValorBase(distancia);

    subtotal = valorBase + (distancia * TARIFA_KM);

    adicionalPeso = subtotal * obterPercentualPeso(peso);

    adicionalModalidade =
        subtotal * obterPercentualModalidade(modalidade);

    if (protecao == 1) {
        adicionalProtecao = VALOR_PROTECAO;
    } else {
        adicionalProtecao = 0.00;
    }

    adicionalTentativas = tentativas * VALOR_TENTATIVA;

    return subtotal
           + adicionalPeso
           + adicionalModalidade
           + adicionalProtecao
           + adicionalTentativas;
}

int main(void) {

    double distancia;
    double peso;
    double valorEntrega;

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

    valorEntrega = calcularValorFinal(
        distancia,
        peso,
        modalidade,
        protecao,
        tentativas
    );

    printf("\n====================================\n");
    printf("        DADOS DA ENTREGA\n");
    printf("====================================\n");

    printf("Distancia: %.2f km\n", distancia);
    printf("Peso: %.2f kg\n", peso);
    printf("Modalidade: %d\n", modalidade);
    printf("Protecao: %d\n", protecao);
    printf("Tentativas adicionais: %d\n", tentativas);

    printf("\nValor da entrega: R$ %.2f\n", valorEntrega);

    return 0;
}

