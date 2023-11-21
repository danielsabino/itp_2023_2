#include <stdio.h>

int calcular_aposta(int largura, int altura, int bandeira[altura][largura], char cor){
    // Variáveis
    // salto: que indica o salto a ser dado na bandeira para ir para a cor desejada
    // inicio: indica o início na largura da bandeira que deve ser considerado
    // tamanho: indica a largura da faixa a ser explorada
    // soma = acumula o valor da aposta
    int salto, inicio, tamanho, soma = 0;
    switch (cor){    
        case 'G':
            salto = 0;
            break;
        case 'Y':
            salto = 1;
            break;
        case 'R':
            salto = 2;
            break;        
    }
    
    tamanho = largura / 3;
    inicio = tamanho * salto;

    for(int i=inicio;i<inicio+tamanho;i++){
        for(int j=0;j<altura;j++){
            soma += bandeira[j][i];
        }
    }
    return soma;
}

// void imprimir(int bandeira[altura][largura]){
   
// }

int main(){
    // Declaração de variáveis
    // largura: largura da bandeira
    // altura: altura da bandeira
    // inicial: valor inicial para definir os valores da bandeira
    // cor: determina a cor que vai ser usada na aposta
    // mudanca: indica quando a cor da bandeira muda
    // atual: determinar o valor a ser preenchido em cada local da bandeira
    // aposta: valor calculado da aposta
    int largura, altura, inicial;
    char cor;
    int mudanca, atual, aposta;

    // Leitura dos valores de entrada
    scanf("%d %d %c", &largura, &inicial, &cor);

    // Determina a altura da bandeira de acordo com a largura
    altura = largura * 2 / 3;
    // Declaração da matriz que armazena a bandeira
    int bandeira[altura][largura];

    mudanca = largura / 3;
    atual = inicial + 1;

    // Preencher a bandeira com os valores
    for(int j=0;j<largura;j++){
        for(int i=0;i<altura;i++){
            bandeira[i][j] = atual;
        }
        if((j+1) % mudanca == 0){
            atual++;
        }
    }
    aposta = calcular_aposta(largura, altura, bandeira, cor);
    printf("%d\n", aposta);

    return 0;
}