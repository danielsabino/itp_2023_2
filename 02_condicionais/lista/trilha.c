#include <stdio.h>

int main(){
    // t: numero de trilhas feitas
    // saude: saude da pessoa para o caso de avaliação
    int t, saude;

    // Leitura da entrada
    scanf("%d", &t);

    // Verificações
    // Se iniciante
    if (t < 5){
        printf("Iniciante\n");
    }
    // Se maior que isso, necessário avaliação
    // Necessário leitura de novo valor    
    else{
        scanf("%d", &saude); 
        // Se intermediário
        if(t < 20){
            if(saude == 0){
                printf("Iniciante\n");
            }
            else{
                printf("Intermediário\n");
            }
        }
        else if(t >= 20){
            if(saude == 0){
                printf("Intermediário\n");
            }
            else{
                printf("Avançado\n");
            }
        }

    }
    return 0;
}