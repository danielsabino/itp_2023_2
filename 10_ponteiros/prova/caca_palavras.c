#include <stdio.h>
#include <string.h>
#include <ctype.h>

void imprimePalavra (char *c, int salto, int tam) {
    if (c==NULL) {
        printf("Palavra nao encontrada\n");
        return;
    }
    for (int i=0; i<tam; i++) {
        printf("%c", *c);
        c+=salto;
    }
    printf(", salto:%d\n", salto);
}

int deu_match(char *palavra, char matriz[10][10], int l, int c, int passo_l, int passo_c){
    int tam = strlen(palavra);
    
    for(int i = 0; i < tam; i++){
        if(l > 10 || c > 10){
            return 0;
        }
        if(tolower(palavra[i]) != tolower(matriz[l][c])){
            return 0;
        }
        l += passo_l;
        c += passo_c;
    }
    return 1;
}

char * localizar(char matriz[10][10], char *palavra, int *salto){
    int tam = strlen(palavra);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            // Horizontal direita
            if(deu_match(palavra, matriz, i, j, 0, 1)){
                *salto = 1; 
                return &matriz[i][j];
            }
            // Horizontal esquerda
            if(deu_match(palavra, matriz, i, j, 0, -1)){
                *salto = -1; 
                return &matriz[i][j];
            }
            // Vertical inferior
            if(deu_match(palavra, matriz, i, j, 1, 0)){
                *salto = 10; 
                return &matriz[i][j];
            }
            // Vertical superior
            if(deu_match(palavra, matriz, i, j, -1, 0)){
                *salto = -10; 
                return &matriz[i][j];
            }
            // Diagonal primária inferior
            if(deu_match(palavra, matriz, i, j, 1, 1)){
                *salto = 11; 
                return &matriz[i][j];
            }
            // Diagonal primária superior
            if(deu_match(palavra, matriz, i, j, -1, -1)){
                *salto = -11; 
                return &matriz[i][j];
            }
            // Diagonal secundária inferior
            if(deu_match(palavra, matriz, i, j, -1, -1)){
                *salto = 9; 
                return &matriz[i][j];
            }
            // Diagonal secundária superior
            if(deu_match(palavra, matriz, i, j, -1, -1)){
                *salto = -9; 
                return &matriz[i][j];
            }

        }
    }
    return NULL;
}


int main(){
    // n: quantidade de palavras a procurar
    // matriz: contém a matriz de palavras
    int n;
    char matriz[10][10];
    int salto;

    // Leitura do número de palavras a procurar
    scanf("%d", &n);

    // Matriz para guardar as palavras a procurar
    char palavras[n][11];

    // Leitura das palavras a procurar
    for(int i = 0; i < n; i++){
        scanf("%s", palavras[i]);
    }
    
    // Leitura da matriz de letras
    for(int i = 0; i < 10; i++){
        scanf("%s", matriz[i]);
    }

    // Verifica a localização das palavras
    for(int i = 0; i < n; i++){        
        char * local = localizar(matriz, palavras[i], &salto);        
        imprimePalavra(local, salto, strlen(palavras[i]));
    }

    return 0;
}