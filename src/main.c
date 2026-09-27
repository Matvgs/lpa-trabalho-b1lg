#include <stdio.h>

#define TARIFA_KM 1.20
#define PROTECAO 7.50
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
        adicionalProtecao = PROTECAO;
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


void exibirResultado(double valor) {
    printf("\n-----------------------------\n");
    printf("Valor da entrega: R$ %.2f\n", valor);
    printf("-----------------------------\n\n");
}


int desejaContinuar(void) {
    int opcao;

    do {
        printf("Deseja processar outra entrega? (1 = Sim / 0 = Nao): ");
        scanf("%d", &opcao);

        if (opcao != 0 && opcao != 1) {
            printf("Erro: digite apenas 0 ou 1.\n");
        }

    } while (opcao != 0 && opcao != 1);

    return opcao;
}


void exibirResumo(
    int totalEntregas,
    double valorTotal,
    int economicas,
    int expressas,
    int prioritarias,
    double maiorValor,
    double menorValor
) {
    printf("\n====================================\n");
    printf("         RESUMO DA SESSAO\n");
    printf("====================================\n");

    printf("Total de entregas: %d\n", totalEntregas);
    printf("Valor total: R$ %.2f\n", valorTotal);

    if (totalEntregas > 0) {
        printf("Valor medio: R$ %.2f\n",
               valorTotal / totalEntregas);
    } else {
        printf("Valor medio: R$ 0.00\n");
    }

    printf("Entregas Economicas: %d\n", economicas);
    printf("Entregas Expressas: %d\n", expressas);
    printf("Entregas Prioritarias: %d\n", prioritarias);

    if (totalEntregas > 0) {
        printf("Maior valor: R$ %.2f\n", maiorValor);
        printf("Menor valor: R$ %.2f\n", menorValor);
    } else {
        printf("Maior valor: R$ 0.00\n");
        printf("Menor valor: R$ 0.00\n");
    }

    printf("====================================\n");
}


int main(void) {

    double distancia;
    double peso;
    double valorEntrega;
    double valorTotal = 0.00;
    double maiorValor = 0.00;
    double menorValor = 0.00;

    int modalidade;
    int protecao;
    int tentativas;

    int totalEntregas = 0;
    int economicas = 0;
    int expressas = 0;
    int prioritarias = 0;

    int continuar;

    printf("====================================\n");
    printf("       SIMULADOR DE ENTREGAS\n");
    printf("====================================\n");

    do {
        printf("\n--- Nova entrega ---\n");

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

        exibirResultado(valorEntrega);

        
        totalEntregas++;
        valorTotal += valorEntrega;

        
        if (modalidade == 1) {
            economicas++;
        } else if (modalidade == 2) {
            expressas++;
        } else {
            prioritarias++;
        }

        if (totalEntregas == 1) {
            maiorValor = valorEntrega;
            menorValor = valorEntrega;
        } else {
            if (valorEntrega > maiorValor) {
                maiorValor = valorEntrega;
            }

            if (valorEntrega < menorValor) {
                menorValor = valorEntrega;
            }
        }

        continuar = desejaContinuar();

    } while (continuar == 1);

    exibirResumo(
        totalEntregas,
        valorTotal,
        economicas,
        expressas,
        prioritarias,
        maiorValor,
        menorValor
    );

    return 0;
}