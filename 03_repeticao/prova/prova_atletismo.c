#include <stdio.h>

int main(){
    // Variáveis
    // limite: tempo mínimo para concorrer
    // tempo: tempo de cada atleta
    // cont: quantidade de atletas aptos
    // series: quantidade de séries necessárias
    float limite, tempo;
    int cont = 0, series;

    // Leitura do tempo mínimo
    scanf("%f", &limite);

    // Loop de leitura dos tempos até que o valor -1 seja digitado
    do{
        scanf("%f", &tempo);
        if(tempo > 0){
            if(tempo <= limite){
                cont++;
            }
        }
    }while(tempo != -1);

    // Cálculo da quantidade de séries
    if(cont % 8 == 0){
        series = cont / 8;
    }
    else{
        series = cont / 8 + 1;
    }

    // Impressão da saída
    printf("%d %d\n", cont, series);
    return 0;
}