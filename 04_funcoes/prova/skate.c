#include <stdio.h>

int score(int x, int y, int z){
    // Verifica se existem scores repetidos
    if(x == y || x == z){
        return x;
    }
    else if(y == z){
        return y;
    }
    // Se não houver scores repetidos, retorna o valor intermediário
    if(x > y && x < z || x < y && x > z){
        return x;
    }
    else if(y > x && y < z || y < x && y > z){
        return y;
    }
    else{
        return z;
    }
}

int main(){
    // Variáveis
    // x,y,z: valores do skatista para um dia
    // a_1, a_2, a_3: valores do skatista A para os três dias
    // b_1, b_2, b_3: valores do skatista B para os três dias
    // score_a, score_b: scores finais dos skatistas
    int x,y,z;
    int a_1, a_2, a_3, b_1, b_2, b_3;
    int score_a, score_b;

    // Leitura dos valores do skatista A
    // Chama a função para determinar qual o score do dia
    scanf("%d %d %d", &x, &y, &z);    
    a_1 = score(x,y,z);
    scanf("%d %d %d", &x, &y, &z);    
    a_2 = score(x,y,z);
    scanf("%d %d %d", &x, &y, &z);    
    a_3 = score(x,y,z);
    // Chama a função novamente para determinar o score final
    score_a = score(a_1, a_2, a_3);

    // Leitura dos valores do skatista B
    scanf("%d %d %d", &x, &y, &z);    
    b_1 = score(x,y,z);
    scanf("%d %d %d", &x, &y, &z);    
    b_2 = score(x,y,z);
    scanf("%d %d %d", &x, &y, &z);    
    b_3 = score(x,y,z);
    // Chama a função novamente para determinar o score final
    score_b = score(b_1, b_2, b_3);

    // Imprime o resultado
    if(score_a > score_b){
        printf("A\n");
    }
    else if(score_b > score_a){
        printf("B\n");
    }
    else{
        printf("empate\n");
    }
    return 0;
}