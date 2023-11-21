#include <stdio.h>

// Função que determina o level de acordo com a velocidade
int level(int v){
    if(v < 10){
        return 1;
    }
    else if(v < 20){
        return 2;
    }
    else{
        return 3;
    }
}

int main(){
    // Variáveis
    // n: número de lesmas
    // velocidade: guarda a velocidade da lesma atualmente lida
    // l: level da lesma atual
    // maior: maior level das lesmas
    int n, velocidade, maior = 0;

    // Leitura do número de lesmas
    scanf("%d", &n);

    // Leitura das velocidades das lesmas
    for(int i=0; i<n;i++){
        scanf("%d", &velocidade);        
        // Compara com o maior até o momento
        if(velocidade > maior){
            maior = velocidade;
        }        
    }
    // Imprime a saída chamando a função que determina o level da lesma mais rápida
    printf("Level %d\n", level(maior));
    return 0;
}