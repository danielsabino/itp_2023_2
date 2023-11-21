#include <stdio.h>

int main(){

    // Variáveis
    // n, m: tamanho da matriz
    // cobertos: número de setores férteis cobertos
    // descobertos: número de setores férteis descobertos
    // norte, sul, leste, oeste: indicado para verificar ou não os setores correspondentes
    int n, m;
    int cobertos = 0, descobertos = 0;
    int norte, sul, leste, oeste;

    // Leitura do tamanho do campo
    scanf("%d %d", &n, &m);

    // Declaração do campo. Usa mais duas linhas e duas colunas para facilitar a verificação    
    int campo[n][m];
    // Leitura do campo
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            
                scanf("%d", &campo[i][j]);
            
        }
    }

    norte = sul = leste = oeste = 1;
    for(int i=0;i<n;i++){
        // Habilita a verificação dos setores norte e sul dependendo da posição do setor atual
        if(i == 0) norte = 0; else norte = 1;
        if(i == n-1) sul = 0; else sul = 1;
        
         for(int j=0;j<m;j++){
            int setor_coberto = 0;
            // Habilita a verificação dos setores leste e oeste dependendo da posição do setor atual
            if(j == 0) oeste = 0; else oeste = 1;
            if(j == m-1) leste = 0; else leste = 1;
            
            if(campo[i][j] == 1){
                if(norte){
                    if(campo[i-1][j] == 2){
                        setor_coberto = 1;
                    }
                }
                if(sul){
                    if(campo[i+1][j] == 2){
                        setor_coberto = 1;
                    }
                }
                if(leste){
                    if(campo[i][j+1] == 2){
                        setor_coberto = 1;
                    }
                }
                if(oeste){
                    if(campo[i][j-1] == 2){
                        setor_coberto = 1;
                    }                    
                }
                if(setor_coberto){
                    cobertos++;
                }
                else{
                    descobertos++;
                }
            }           
         }
    }

    printf("%d %d\n", cobertos, descobertos);

    return 0;
}