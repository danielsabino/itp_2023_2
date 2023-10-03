#include <stdio.h>

int main(){
    // Declaração de variáveis
    // n e m: tamanho do mapa
    // local_x, local_y: local do Jedi
    // regaste: indica se vai haver restate ou não
    // count: contador de bombas
    int n, m;
    int local_x, local_y;
    int resgate = 1;
    int count = 0;

    // Leitura do tamanho do mapa e da última posição do Jedi
    scanf("%d %d", &n, &m);
    scanf("%d %d", &local_x, &local_y);

    // Declaração da variável que armazena o mapa
    // O valor maior é para incluir linhas e colunas neutras nas bordas do mapa
    int mapa[n+2][m+2];

    // Leitura do mapa
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            scanf("%d", &mapa[i][j]);
        }
    }
    // Adaptação do mapa para incluir bordas que facilitam na verificação das bombas
    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            if(i == 0 || i == n + 1 || j == 0 || j == m + 1){
                mapa[i][j] = 0;
            }
        }
    }

    // Varredura do mapa para verificar locais das bombas e se atingiu Jedi
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            // Variável para indicar a presença de bomba
            int bomba = 1;
            // Varrer vizinhança para verificar a existência de bombas
            for(int k=i-1;k<=i+1;k++){
                for(int l=j-1;l<=j+1;l++){
                    if(k != i || l != j){
                        if(mapa[i][j] <= mapa[k][l]){
                            bomba = 0;
                        }
                    }
                    
                }
            }
            if(bomba){
                count++;
                printf("Local %d: %d %d\n", count, i, j);
                if(local_x == i && local_y == j){
                    resgate = 0;
                }
            }
           
        }
    }
    if(resgate){
        printf("Ao resgate!\n");
    }
    else{
        printf("Descanse na Força...\n");
    }

    return 0;
}