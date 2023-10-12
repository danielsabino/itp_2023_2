#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id_cartela;
    int tam_cartela;
    int numeros[100];
    int marcacao[100];
} Cartela;

int repetido(int numero, int max, int numeros[]){
    for(int i = 0; i < max; i++){
        if(numero == numeros[i]){
            return 1;
        }
    }
    return 0;
}

void inicializa(int idx, Cartela jogadores[], int id, int tam, int qtd_bolas){
    jogadores[idx].id_cartela = id;
    jogadores[idx].tam_cartela = tam;
    srand(id);
    for(int i = 0; i < tam; i++){
        int sorteado = rand() % qtd_bolas + 1;
        while(repetido(sorteado, i, jogadores[idx].numeros)){
            sorteado = rand() % qtd_bolas;
        }
        jogadores[idx].numeros[i] = sorteado;
    }
}

int sorteia(int max, int seed){
    srand(seed);
    return rand() % max + 1;    
}

int marcar(Cartela jogador, int numero){
    int tam = jogador.tam_cartela;
    for(int i = 0; i < tam; i++){
        if(jogador.numeros[i] == numero){
            jogador.marcacao[i] = 1;
        }
    }
    for(int i = 0; i < tam; i++){
        if(!(jogador.marcacao[i] == 1)){
            return 0;
        }
    }
    return 1;    
}

void imprimir(Cartela jogadores[], int qtd){
    for(int i = 0; i < qtd; i++){
        for(int j = 0; j < jogadores[i].tam_cartela; j++){
            printf("%d ", jogadores[i].numeros[j]);
        }
        printf("\n");
    }
}

void imprime_cartela(int numeros[], int qtd){
    for(int i = 0; i < qtd; i++){
        printf("%d ", numeros[i]);
    }
}

void imprime_vencedor(Cartela jogadores[], int idx){
    printf("Bingo! Cartela %d: ", idx);
    for(int i = 0; i < jogadores[idx].tam_cartela; i++){
        printf("%d ", jogadores[idx].numeros[i]);
    }
    printf("\n");
}

int main(){

    // tam_cartela: tamanho da cartela
    // tam_globo: tamanho do globo
    // seed_sorteio: semente usada para geração dos números do sorteio
    // jogadores: vetor contendo as cartelas dos jogadores
    // entrada: usada para armazenar os valores de entrada
    // id: ids das cartelas iniciais
    // comecou: indica que o jogo deve iniciar
    // count_jog: indica a quantidade de jogadores
    // couint_bolas: indica o número de bolas sorteadas
    // vencedor: indica o índice do vencedor
    // bingo: indica que alguém ganhou
    int tam_cartela, tam_globo, seed_sorteio;
    Cartela jogadores[30];
    char entrada[20];
    int id, comecou = 0, count_jog = 0, count_bolas = 0;
    int vencedor, bingo = 0;

    // Leitura dos parâmetros iniciais
    scanf("%d %d %d", &tam_cartela, &tam_globo, &seed_sorteio);

    // Declaração do globo de bolas
    int globo[tam_globo];

    // Leitura dos ids das cartelas
    do{
        scanf(" %[^\n]", entrada);
        if(strcmp(entrada, "Comecou o jogo!") == 0){
            comecou = 1;
        }
        else{
            id = atoi(entrada);            
            inicializa(count_jog, jogadores, id, tam_cartela, tam_globo);
            count_jog++;
        }
    }while(!comecou);
    
    imprimir(jogadores, count_jog);
    // Sorteia números enquanto não houver vencedor
    srand(seed_sorteio);
    while(!bingo){
        int numero = rand() % tam_globo + 1;
        //printf("Numero sorteado: %d\n", numero);
        if(!repetido(numero, count_bolas, globo)){
            // Marcar o número em todas as cartelas
            for(int i = 0; i < count_jog; i++){
                bingo = marcar(jogadores[i], numero);
                vencedor = i;
                break;
            }
        }
    }
    imprime_vencedor(jogadores, vencedor);
 
    return 0;
}