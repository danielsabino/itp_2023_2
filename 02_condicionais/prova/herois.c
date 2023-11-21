#include <stdio.h>

int main(){
    // Variáveis
    // qtd: quantidade de herois enviados
    // classe: indica a classe dos herois enviados
    // ameaca: nível de ameaça do monstro
    // vitoria: indica se vai haver vitoria ou não
    int qtd, classe, ameaca;
    int vitoria = 0;

    // Leitura da entrada
    scanf("%d %d %d", &qtd, &classe, &ameaca);

    // Testes para saber se haverá vitória
    if(qtd > 0){
        switch (ameaca)
        {
        case 1:
            if(classe >= 2 || qtd >= 3){
                vitoria = 1;
            }
            break;
        case 2:
            if(classe >= 3 || (classe == 2 && qtd >= 3)){
                vitoria = 1;
            }
            break;
        case 3:
            if(classe >= 4 || (classe == 3 && qtd >= 3)){
                vitoria = 1;
            }
            break;
        case 4:
            if(classe >= 5 || (classe == 4 && qtd >= 3)){
                vitoria = 1;
            }
            break;
        case 5:
            if(classe >= 5){
                vitoria = 1;
            }
            break;    
        default:
            break;
        }
    }    
    if(vitoria){
        printf("Heróis vencerão!\n");
    }
    else{
        printf("Melhor chamar Saitama!\n");
    }
    return 0;
}