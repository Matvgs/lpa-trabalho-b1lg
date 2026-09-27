# Trabalho B1 - Lógica de Programação e Algoritmos

## Descrição
Este projeto é um Simulador de Entregas desenvolvido em linguagem C, executado em terminal.
O programa processa solicitações de entrega de uma empresa fictícia, solicitando ao usuário a
distância, o peso, a modalidade, a contratação de serviço adicional de proteção e a quantidade de
tentativas adicionais de cada entrega. A partir desses dados, o programa valida as entradas, calcula
o valor final de cada entrega seguindo a ordem de cálculo definida no roteiro e, ao final da sessão de
atendimento, apresenta um resumo com as estatísticas das entregas processadas.

## Funcionalidades
- Processamento de múltiplas entregas em uma mesma execução, repetindo o fluxo enquanto o usuário desejar (`desejaContinuar`).
- Cálculo do valor-base conforme a faixa de distância percorrida (`obterValorBase`).
- Cálculo do subtotal inicial somando o valor-base à parcela variável por quilômetro (`TARIFA_KM`).
- Cálculo do percentual de adicional de peso sobre o subtotal inicial (`obterPercentualPeso`).
- Cálculo do percentual de adicional de modalidade (Econômica, Expressa ou Prioritária) sobre o subtotal inicial (`obterPercentualModalidade`).
- Acréscimo de valor fixo referente ao serviço adicional de proteção, quando contratado (`PROTECAO`).
- Acréscimo de valor por tentativa adicional de entrega (`VALOR_TENTATIVA`).
- Validação de todas as entradas numéricas do domínio, com nova solicitação em caso de valor inválido:
  - distância maior que zero (`obterDistancia`);
  - peso maior que zero (`obterPeso`);
  - modalidade entre 1 e 3 (`obterModalidade`);
  - proteção igual a 0 ou 1 (`obterProtecao`);
  - tentativas adicionais maior ou igual a zero (`obterTentativas`);
  - opção de continuar igual a 0 ou 1 (`desejaContinuar`).
- Apresentação do valor final de cada entrega, formatado com duas casas decimais (`exibirResultado`).
- Ao encerrar a sessão, apresentação do resumo final (`exibirResumo`) contendo:
  - quantidade total de entregas processadas;
  - valor total calculado na sessão;
  - valor médio das entregas;
  - quantidade de entregas Econômicas, Expressas e Prioritárias;
  - maior e menor valor de entrega registrados.

## Organização da solução
O programa foi dividido em funções com responsabilidades específicas, evitando concentrar a lógica
na função `main`, que atua apenas coordenando o fluxo geral (loop de processamento, atualização dos
acumuladores e chamada das demais funções). A solução foi organizada da seguinte forma:

- **Funções de captura e validação de entrada** (`obterDistancia`, `obterPeso`, `obterModalidade`, `obterProtecao`, `obterTentativas`, `desejaContinuar`): cada uma utiliza uma estrutura `do-while` para solicitar o dado repetidamente até que um valor válido seja informado, retornando o valor validado para quem a chamou.
- **Funções de cálculo de faixas e percentuais** (`obterValorBase`, `obterPercentualPeso`, `obterPercentualModalidade`): recebem o dado relevante por parâmetro (distância, peso ou modalidade) e retornam o valor-base ou o percentual correspondente à faixa, por meio de estruturas de decisão encadeadas.
- **Função de cálculo do valor final** (`calcularValorFinal`): recebe todos os dados da entrega por parâmetro, chama as funções de faixa e percentual, e aplica a ordem de cálculo definida no roteiro (subtotal → adicional de peso → adicional de modalidade → proteção → tentativas adicionais), retornando o valor final da entrega.
- **Funções de apresentação** (`exibirResultado`, `exibirResumo`): responsáveis apenas por formatar e exibir, respectivamente, o valor de cada entrega e o resumo da sessão, sem realizar cálculos.
- **Função `main`**: controla o laço de repetição das entregas, chama as funções de entrada e cálculo, atualiza os contadores e acumuladores (total de entregas, valor total, quantidade por modalidade, maior e menor valor) e, ao final, chama `exibirResumo`.

Constantes (`TARIFA_KM`, `PROTECAO`, `VALOR_TENTATIVA`) foram utilizadas para os valores fixos das
regras de negócio, evitando números "mágicos" espalhados pelo código. Não foram utilizadas variáveis
globais; toda a comunicação entre as funções ocorre por parâmetros e valores de retorno.

## Compilação
```bash
gcc -o simulador_entregas src/main.c
```

## Execução
```bash
./simulador_entregas
```

## Uso de Inteligência Artificial

- Utilizei IA para:
   -Corrigir um erro que n conseguia corrigir
        Prompt: tem um erro nesse código que faz o código fechar após indicar a distânçia, como resolver.
        O que foi aproveitado: vi o erro no código e consertei ele.

   -Me explicar como fazer um README
        Prompt: me diga o que é um readme e como fazer um.
        O que foi aproveitado: aprendi a fazer um readme e fiz o meu com base no que a IA ensinou.

## Fontes consultadas
Tutoriais:
COMO USAR O GITHUB DESKTOP - GUIA COMPLETO PARA INICIANTES - https://www.youtube.com/watch?v=y_3hJcw0dns
COMO CRIAR SEUS READMEs? GUIA DO README COMPLETO - https://www.youtube.com/watch?v=k4Rsy8GbKE0

Documentação:
Usei códigos das aulas de lógica e de pratica profissional.
Biblioteca em C - https://www.ibm.com/docs/pt-br/debug-for-zos/16.0.x?topic=programs-c-reserved-keywords

Outros:
Usei a consulta de IA mencionada antes.



Trabalho Lógica de Programação - Matheus Victor Galvão da Silva(UC2610182)
