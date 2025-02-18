#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Carta
{
    char nome[50];
    int populacao;
    int area;
    int pib;
    int pontosTuristicos;
};

// Declaração dos métodos utilizados:
struct Carta cadastrarCarta(); // Método para cadastrar uma carta.
void cls(); // Método para limpar a tela do terminal utilizando um comando ANSI (foi o que funcionou melhor)
void exibirCarta(struct Carta carta); // Metodo para exibir uma carta.
int clean_scanf(const char *format, void *arg); // Método criado para evitar problemas de buffer no scanf.
void clean_fgets(char *str, int size); // Método criado para evitar problemas de buffer no fgets.


int main() {
    cls();
    struct Carta carta = cadastrarCarta();
    cls();

    exibirCarta(carta);    

    printf("\n\n Pressione ENTER para encerrar o programa.\n");
    getchar();    

    return 0;
}
int clean_scanf(const char *format, void *arg) {  
    int result = scanf(format, arg);
    while (getchar() != '\n');
    return result;
}

void clean_fgets(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}

void cls() {
    printf("\033[H\033[J");
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