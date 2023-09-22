#include <stdio.h>

int main(){
    // n: número de amigos 
    // vencedor_bola: ganhador da bola de ouro
    // total: valor total apostado
    // banca: valor reservado para comes e bebes
    // total_ganhadores: valor investido pelos ganhadores
    // subtotal: valor somado após a divisão dos prêmios 
    // num_ganhadores: número de acertadores do bolão
    // subtotal2: valor usado para contabilizar o valor distribuído durante a distribuição dos prêmios.
    int n, vencedor_bola,  num_ganhadores = 0;
    float total = 0.0, banca = 0.0, total_ganhadores = 0.0, subtotal = 0.0, subtotal2 = 0.0;
    
    // Leitura do número de amigos para poder dimensionar os vetores seguintes.
    scanf("%d", &n);

    // Vetores para guardar o valor das apostas e os índices;
    float apostas[n];
    int indices[n];

    // Vetor para armazenar os índices dos ganhadores do bolão
    int idx_ganhadores[n];

    for(int i=0;i<n;i++){
        // Faz a leitura dos valores de aposta e dos índice
        scanf("%f %d", &apostas[i], &indices[i]);
        // Aproveita para calcular o valor total apostado
        total += apostas[i];
    }
    // Leitura do jogador vencedor da bola de ouro
    scanf("%d", &vencedor_bola);

    // Verifica quantos ganhadores existem no bolão, armazena os índices dos vencedores e o total destinado pelos vencedores.
    for(int i=0;i<n;i++){
        if(indices[i] == vencedor_bola){
            idx_ganhadores[num_ganhadores] = i;
            num_ganhadores++;            
            total_ganhadores += apostas[i];
        }
    }

    // Calcula o valor destinado à banca
    banca = (int)(total * 0.1);
    // Valor a ser distribuído para os ganhadores
    subtotal = total - banca;

    // Impressão da saída
    printf("Total: R$ %d\n", (int)total);

    if(num_ganhadores > 0){
        for(int i=0;i<num_ganhadores;i++){
            float individual;
            individual = apostas[idx_ganhadores[i]]/total_ganhadores * subtotal;
            printf("Apostador %d: R$ %d\n", idx_ganhadores[i] + 1, (int)individual);
            subtotal2 += (int)individual;
        }
    }
    else{
        total_ganhadores = subtotal;
        for(int i=0;i<n;i++){
            float individual;
            individual = apostas[i]/total * subtotal;
            printf("Apostador %d: R$ %d\n", i + 1, (int)individual);
            subtotal2 += (int)individual;
        }
    }
    
    // Atualiza o valor destinado a banca considerando possíveis truncamentos.
    banca = total - subtotal2;
    printf("Bebidas e petiscos: R$ %d\n", (int)banca);

    return 0;
}