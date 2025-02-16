#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define uma constante para limpeza do terminal.
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// struct com os dados de uma carta.
struct Carta
{
    char nome[50];
    int populacao;
    int area;
    int pib;
    int pontosTuristicos;
};

struct Carta cadastrarCarta(); // Método para cadastrar uma carta.
void exibirCarta(struct Carta carta); // Método para exibir uma carta.
int clean_scanf(const char *format, void *arg); // Método para fazer um scanf limpo sem problemas com buffer de \n
void clean_fgets(char *str, int size); // Método para fazer um fgets limpo sem problemas com buffer de \n


int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    struct Carta carta = cadastrarCarta();

    // Limpa o terminal
    system(CLEAR);

    // Exibição dos Dados das Cartas:
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    exibirCarta(carta);    
    

    // Aguarda uma tecla ser encerrada para finalizar o programa.
    printf("\n\n Pressione ENTER para encerrar o programa.\n");
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
    printf("###################################\n");
    printf("#         CARTA DE CIDADE         #\n");
    printf("###################################\n");
    printf("Cidade: ------------ %s\n", carta.nome);
    printf("População: --------- %i\n", carta.populacao);
    printf("Área: -------------- %i\n", carta.area);
    printf("PIB: --------------- %i\n", carta.pib);
    printf("Pontos Turísticos: - %i\n", carta.pontosTuristicos);
    printf("###################################\n");
}