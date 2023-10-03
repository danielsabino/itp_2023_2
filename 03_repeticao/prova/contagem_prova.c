#include <stdio.h>

int main(){
    // Variáveis
    // num_equipes: quantidade de equipes na competição
    // total_c, total_s, total_l: quantidade total de atletas em cada modalidade
    // total: quantidade total de atletas em todas as modalidades
    // modalidade: modalidade atual sendo lida da entrada
    int num_equipes = 0;
    int total_c = 0, total_s = 0, total_l = 0, total = 0;
    char modalidade;
    
    // Leitura da quantidade de equipes
    scanf("%d\n", &num_equipes);

    // Leitura das modalidades de cada equipe
    for(int i=0;i<num_equipes;i++){
        do{
            scanf("%c", &modalidade);
            if(modalidade == 'C'){
                total_c++;
                total++;                
            }
            else if(modalidade == 'S'){
                total_s++;
                total++;
            }
            else if(modalidade == 'L'){
                total_l++;
                total++;
            }
        }while(modalidade != 'F');
    }

    // Impressão da saída
    printf("%d %d %d %d\n", total_c, total_s, total_l, total);
    return 0;
}