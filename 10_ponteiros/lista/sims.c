#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int simula_sims(int *fome, int *sede, int *banheiro, int *sono, int *tedio){
    char acao[50];

    //fgets(acao, 15, stdin);
    //acao[strlen(acao)] = '\0';
    scanf(" %[^\n]", acao);
    
    if(strcmp(acao,"comer") == 0){
        (*fome) += 30;
        (*banheiro) -= 15;
        
        (*sede) -= 5;
        (*sono) -= 5;
        (*tedio) -= 5;
    }
    else if(strcmp(acao,"beber") == 0){
        (*sede) += 30;
        (*banheiro) -= 20;

        (*fome) -= 5;
        (*sono) -= 5;
        (*tedio) -= 5;
    }
    else if(strcmp(acao, "dormir") == 0){
        (*sono) += 80;
        (*tedio) += 30;
        (*fome) -= 30;
        (*sede) -= 30;
        (*banheiro) -= 30;
    }
    else if(strcmp(acao, "se aliviar") == 0){
        (*banheiro) += 100;
        
        (*sede) -= 5;
        (*fome) -= 5;
        (*sono) -= 5;
        (*tedio) -= 5;

    }
    else if(strcmp(acao, "jogar videogame") == 0){
        (*tedio) += 80;
        (*sono) -= 20;        
        (*fome) -= 20;
        (*sede) -= 20;
        (*banheiro) -= 20;
    }
    *fome = *fome > 100 ? 100 : *fome;
    *sede = *sede > 100 ? 100 : *sede;
    *banheiro = *banheiro > 100 ? 100 : *banheiro;
    *sono = *sono > 100 ? 100 : *sono;
    *tedio = *tedio > 100 ? 100 : *tedio;

    *fome = *fome < 0 ? 0 : *fome;
    *sede = *sede < 0 ? 0 : *sede;
    *banheiro = *banheiro < 0 ? 0 : *banheiro;
    *sono = *sono < 0 ? 0 : *sono;
    *tedio = *tedio < 0 ? 0 : *tedio;

    //printf("\nfome: %d - sede: %d - banheiro: %d - sono: %d - tedio: %d\n", *fome, *sede, *banheiro, *sono , *tedio);

    if((*fome) <= 0) {printf("Game Over! Morreu de fome\n"); return 0;}
    else if(*fome > 0 && *fome <= 15) {printf("Alerta: fome está com valor baixo\n");}

    if(*sede <= 0) {printf("Game Over! Morreu de sede\n"); return 0;}
    else if(*sede > 0 && *sede <= 15) {printf("Alerta: sede está com valor baixo\n");}

    if((*banheiro) <= 0) {printf("Game Over! Morreu apertado...\n"); return 0;}
    else if((*banheiro) > 0 && (*banheiro) <= 15) {printf("Alerta: banheiro está com valor baixo\n"); }

    if(*sono <= 0) {printf("Game Over! Morreu dormindo...\n"); return 0;}
    else if(*sono > 0 && *sono <= 15) {printf("Alerta: sono está com valor baixo\n");}

    if(*tedio <= 0) {printf("Game Over! Morreu deprimido...\n"); return 0;}
    else if(*tedio > 0 && *tedio <= 15) {printf("Alerta: tédio está com valor baixo\n");}

   return 1;
    
}

void imprime_relatorio(int fome, int sede, int banheiro, int sono, int tedio){
    printf("Status final:\n");
    printf("Fome: %d\n", fome);
    printf("Sede: %d\n", sede);
    printf("Banheiro: %d\n", banheiro);
    printf("Sono: %d\n", sono);
    printf("Tédio: %d\n", tedio);
}


int main(){
    int fome, sede, banheiro, sono, tedio;
    int acoes;
    scanf("%d %d %d %d %d", &fome, &sede, &banheiro, &sono, &tedio);
    scanf("%d", &acoes);
    for(int i = 0; i<acoes; i++){
        int ret = simula_sims(&fome, &sede, &banheiro, &sono, &tedio);
        if(ret == 0) break;
    }
    imprime_relatorio(fome, sede, banheiro, sono, tedio);
    return 0;
}