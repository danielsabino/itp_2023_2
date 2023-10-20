#include <stdio.h>

int main(){
    // Variáveis
    // n: número de produtos do cardápio    
    // produto: struct para armazenar o produto
    // codigo_pedido: número do produto no pedido
    // qtd_pedido: quantidade de produtos no pedido
    // total: valor total do pedido
    typedef struct produto{
        int codigo;
        char descricao[100];
        float preco;
    }Produto;
    int n;
    int codigo_pedido, qtd_pedido;
    float total = 0.0;

    // Leitura do número de produtos
    scanf("%d", &n);

    // Declaração do cardápio com os produtos
    // cardapio: armazena os produtos
    Produto cardapio[n];

    // Leitura dos produtos que vão compor o cardápio
    for(int i=0;i<n;i++){
        scanf("%d\n", &cardapio[i].codigo);
        //fgets(cardapio[i].descricao, 100, stdin); 
        scanf("%[^\n]s", cardapio[i].descricao);
        scanf("%f", &cardapio[i].preco);
    }

    // Leitura do pedidos enquanto o código de leitura é diferente de zero
    do
    {
        scanf("%d", &codigo_pedido);
        if(codigo_pedido > 0){
            scanf("%d", &qtd_pedido);
            for(int i=0;i<n;i++){
                if(cardapio[i].codigo == codigo_pedido){
                    total += cardapio[i].preco * qtd_pedido;
                }
            }
        }
    } while (codigo_pedido != 0);
    
    // Imprime o total
    if(total > 0){
        printf("%.2f\n", total);
    }
    
    return 0;
}