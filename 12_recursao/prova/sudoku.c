#include <stdio.h>
#include <stdlib.h>

void imprime(int matriz[9][9]){    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(matriz[i][j]){
                printf("%d", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

int pode(int val, int x, int y, int matriz[9][9]){
    int l, c;
    // Se não existe elemento igual na linha
    for(int i = 0; i < 9; i++){
        if(matriz[x][i] == val){
            return 0;
        }
    }
    // Se não existe elemento igual na coluna
    for(int i = 0; i < 9; i++){
        if(matriz[i][y] == val){
            return 0;
        }
    }
    // Se não existe elemento igual no quadrante
    l = (x/3)*3;
    c = (y/3)*3;
    for(int i = l; i < l+3; i++){
        for(int j = c; j < c+3; j++){
            if(matriz[i][j] == val){
                return 0;
            }
        }
    }
    // É possível inserir
    return 1;
}

int preenche(int x, int y, int matriz[9][9]){    
    // Preencheu todas as linhas e todas as colunas
    if(x == 8 && y == 9){
        return 1;
    }
    // Se a linha foi toda preenchida, passa para a próxima linha
    if(y == 9){
        x++;
        y = 0;
    }
    // Se já existe um número, passa para a próxima coluna
    if(matriz[x][y]){
        // printf("Preenchido!\n");
        return preenche(x, y+1, matriz);
    }
    // Se o campo é para ser preenchido    
    for(int i = 1; i <= 9; i++){
        // Preenche cada linha
        if(pode(i, x, y, matriz)){
            matriz[x][y] = i;
            if(preenche(x, y+1, matriz)){
                return 1;
            }
        }
        matriz[x][y] = 0;
    }
    return 0;
}

int main(){
    // matriz: matriz com valores do sudoku
    // tmp: recebe caracter lido da entrada
    int matriz[9][9];
    char tmp;
    // Leitura da matriz de entrada
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf(" %c", &tmp);
            if(tmp == '*')
                matriz[i][j] = 0;
            else{
                matriz[i][j] = tmp - '0';
            }
            
        }
    }
    if(preenche(0,0,matriz)){
        imprime(matriz);
    }
    else{
        printf("Não tem solução!\n");
    }
    return 0;
}