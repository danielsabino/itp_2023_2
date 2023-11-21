#include <stdio.h>

void imprime(int m, int n, char mapa[m][n]){
    printf("Mapa final:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}

int analisa(int px, int py, int m, int n, char mapa[m][n]){
    int bolinha = 0;   

    // Se a posição está dentro dos limites do mapa
    if(px >= 0 && px < m && py >= 0 && py < n){        
        // Se é a posição onde se encontra o Pacman
        if(mapa[px][py] == 'C'){
            bolinha += analisa(px + 1, py, m, n, mapa);
            bolinha += analisa(px - 1, py, m, n, mapa);
            bolinha += analisa(px, py + 1, m, n, mapa);
            bolinha += analisa(px, py - 1, m, n, mapa);
            return bolinha;
        }
        // Se é posição contém uma bolinha
        else if(mapa[px][py] == '.'){
            bolinha++;
            mapa[px][py] = ' ';
            bolinha += analisa(px + 1, py, m, n, mapa);
            bolinha += analisa(px - 1, py, m, n, mapa);
            bolinha += analisa(px, py + 1, m, n, mapa);
            bolinha += analisa(px, py - 1, m, n, mapa);
            return bolinha;
        }
        // Se é posição contém uma parede ou um fantasma
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

int main(){
    // m, n: tamanho do mapa
    // px, py: linha e coluna do pacman
    // bolinhas: número de bolinhas comidas
    int m, n, px, py;
    int bolinhas;

    // Leitura do tamanho do mapa
    scanf("%d %d", &m, &n);

    // mapa: mapa do jogo
    char mapa[m][n];

    // Leitura do mapa
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf(" %c", &mapa[i][j]);    
            if(mapa[i][j] == 'C'){
                px = i;
                py = j;
            }
        }
    }
    bolinhas = analisa(px, py, m, n, mapa);
    printf("Total de bolinhas devoradas: %d\n", bolinhas);
    imprime(m, n, mapa);
    return 0;
}