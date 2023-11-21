#include <stdio.h>

int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index){
    
    // conectado: indica se o usuário está conectado    
    int conectado = 0;

    // Percorre as células verificando
    for(int i = 0; i < n; i++){
        // Se a célula não é a central
        if(cells[i]){
            // Verifica se o usuário está dentro do alcance da possível célula esquerda
            if(cells[i] < user && cells[i] + distance >= user){
                *left_index = i;
                conectado = 1;
            }
            // Verifica se o usuário está dentro do alcance da possível célula direita
            if(cells[i] > user && cells[i] - distance <= user){
                *right_index = i;
            }
        }
    }
    return conectado;
}

int main(){
    // n: número de celulas
    // d: distância de alcance das células
    // u: posição do usuário
    // left_index, right_index: posições das células limite de alcance do usuário
    // conectado: indica se o usuário está conectado ou não
    int n, d, u;
    int left_index, right_index;
    int conectado;

    // Leitura do número de células, distância das células e posição do usuário
    scanf("%d %d %d", &n, &d, &u);

    // Vetor de células
    int cells[n];

    // Leitura dos posições das células
    for(int i = 0; i < n; i++){
        scanf("%d", &cells[i]);
    }

    // Verifica se o usuário está conectado e quais as células dentro do seu alcance
    conectado = get_range(n, cells, d, u, &left_index, &right_index);

    // Imprime a saída
    if(conectado){
        for(int i = left_index; i <= right_index; i++){
            printf("%d ", cells[i]);
        }
    }
    else{
        printf("USUARIO DESCONECTADO");
    }
    printf("\n");

}