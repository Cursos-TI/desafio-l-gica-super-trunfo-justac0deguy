#include <stdio.h>
#include <string.h>

int main() {
    // Declaração de dados das cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;

    // Entrada de dados da carta 1
    printf("Digite o estado da carta 1 (letra A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o codigo da carta 1 (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade da carta 1: ");
    scanf(" %[^\n]", cidade1);
    printf("Digite a populacao da cidade 1: ");
    scanf("%d", &populacao1);
    printf("Digite a area da cidade 1: ");
    scanf("%f", &area1);
    printf("Digite o PIB da cidade 1: ");
    scanf("%f", &pib1);
    printf("Digite o numero de pontos turisticos da cidade 1: ");
    scanf("%d", &pontos1);

    // Entrada de dados da carta 2
    printf("Digite o estado da carta 2 (letra A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o codigo da carta 2 (ex: B02): ");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade da carta 2: ");
    scanf(" %[^\n]", cidade2);
    printf("Digite a populacao da cidade 2: ");
    scanf("%d", &populacao2);
    printf("Digite a area da cidade 2: ");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade 2: ");
    scanf("%f", &pib2);
    printf("Digite o numero de pontos turisticos da cidade 2: ");
    scanf("%d", &pontos2);

    // Cálculo de atributos derivados
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pib_per_capita1 = pib1 / populacao1;
    float pib_per_capita2 = pib2 / populacao2;

    // Exibição
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f\n", densidade1);
    printf("PIB per capita: %.2f\n", pib_per_capita1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f\n", densidade2);
    printf("PIB per capita: %.2f\n", pib_per_capita2);

    // MENU INTERATIVO
    int opcao;
    printf("\nEscolha uma opcao de comparacao:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("6 - PIB per capita\n");
    printf("7 - Comparar dois atributos\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    int vitorias1 = 0, vitorias2 = 0;

    switch (opcao) {
        case 1:
            if (populacao1 > populacao2)
                printf("Carta vencedora: %s (%s)\n", codigo1, cidade1);
            else if (populacao2 > populacao1)
                printf("Carta vencedora: %s (%s)\n", codigo2, cidade2);
            else
                printf("Empate na populacao!\n");
            break;
        case 2:
            if (area1 > area2)
                printf("Carta vencedora: %s (%s)\n", codigo1, cidade1);
            else if (area2 > area1)
                printf("Carta vencedora: %s (%s)\n", codigo2, cidade2);
            else
                printf("Empate na area!\n");
            break;
        case 3:
            if (pib1 > pib2)
                printf("Carta vencedora: %s (%s)\n", codigo1, cidade1);
            else if (pib2 > pib1)
                printf("Carta vencedora: %s (%s)\n", codigo2, cidade2);
            else
                printf("Empate no PIB!\n");
            break;
        case 4:
            if (pontos1 > pontos2)
                printf("Carta vencedora: %s (%s)\n", codigo1, cidade1);
            else if (pontos2 > pontos1)
                printf("Carta vencedora: %s (%s)\n", codigo2, cidade2);
            else
                printf("Empate nos pontos turisticos!\n");
            break;
        case 5:
            if (densidade1 < densidade2)
                printf("Carta vencedora: %s (%s)\n", codigo1, cidade1);
            else if (densidade2 < densidade1)
                printf("Carta vencedora: %s (%s)\n", codigo2, cidade2);
            else
                printf("Empate na densidade!\n");
            break;
        case 6:
            if (pib_per_capita1 > pib_per_capita2)
                printf("Carta vencedora: %s (%s)\n", codigo1, cidade1);
            else if (pib_per_capita2 > pib_per_capita1)
                printf("Carta vencedora: %s (%s)\n", codigo2, cidade2);
            else
                printf("Empate no PIB per capita!\n");
            break;
        case 7: {
            int att1, att2;
            printf("Escolha o primeiro atributo (1 a 6): ");
            scanf("%d", &att1);
            printf("Escolha o segundo atributo (1 a 6): ");
            scanf("%d", &att2);

            float val1_c1 = 0, val1_c2 = 0, val2_c1 = 0, val2_c2 = 0;

            // Atribui os valores dos atributos escolhidos
            val1_c1 = (att1 == 1) ? populacao1 :
                      (att1 == 2) ? area1 :
                      (att1 == 3) ? pib1 :
                      (att1 == 4) ? pontos1 :
                      (att1 == 5) ? densidade1 :
                      (att1 == 6) ? pib_per_capita1 : 0;

            val1_c2 = (att1 == 1) ? populacao2 :
                      (att1 == 2) ? area2 :
                      (att1 == 3) ? pib2 :
                      (att1 == 4) ? pontos2 :
                      (att1 == 5) ? densidade2 :
                      (att1 == 6) ? pib_per_capita2 : 0;

            val2_c1 = (att2 == 1) ? populacao1 :
                      (att2 == 2) ? area1 :
                      (att2 == 3) ? pib1 :
                      (att2 == 4) ? pontos1 :
                      (att2 == 5) ? densidade1 :
                      (att2 == 6) ? pib_per_capita1 : 0;

            val2_c2 = (att2 ==
