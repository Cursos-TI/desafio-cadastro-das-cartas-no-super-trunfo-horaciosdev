#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

struct Carta
{
    char nome[50];
    int populacao;
    int area;
    int pib;
    int pontosTuristicos;
};

struct Carta cadastrarCarta();
void exibirCarta(struct Carta carta);
int clean_scanf(const char *format, void *arg);
void clean_fgets(char *str, int size);


int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    struct Carta carta = cadastrarCarta();


    // Exibição dos Dados das Cartas:
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    exibirCarta(carta);    
    

    // Aguarda uma tecla ser encerrada para finalizar o programa.
    printf("\n\n Pressione uma tecla para encerrar o programa.\n");
    getchar();    

    return 0;
}
int clean_scanf(const char *format, void *arg) {  
    int result = scanf(format, arg); // Tenta ler a entrada  
    while (getchar() != '\n');       // Limpa o buffer de entrada  
    return result;                   // Retorna o resultado do scanf  
}

void clean_fgets(char *str, int size) {
    fgets(str, size, stdin); // Lê a string
    str[strcspn(str, "\n")] = 0; // Remove o '\n' no final
}

struct Carta cadastrarCarta() {
    struct Carta novaCarta;
    printf("# Cadastro de Cidades #\n");
    printf("-----------------------\n");
    printf("Qual o nome da cidade?\n=> ");
    clean_fgets(novaCarta.nome, sizeof(novaCarta.nome));

    printf("Qual a populacao da cidade?\n=> ");
    clean_scanf("%i", &novaCarta.populacao);

    printf("Qual a área da cidade?\n=> ");
    clean_scanf("%i", &novaCarta.area);

    printf("Qual o PIB da cidade?\n=> ");
    clean_scanf("%i", &novaCarta.pib);

    printf("Qual a quantidade de pontos turísticos da cidade?\n=> ");
    clean_scanf("%i", &novaCarta.pontosTuristicos);
    return novaCarta;
}

void exibirCarta(struct Carta carta) {
    printf("%s\n", carta.nome);
    printf("%i\n", carta.populacao);
    printf("%i\n", carta.area);
    printf("%i\n", carta.pib);
    printf("%i\n", carta.pontosTuristicos);
}
