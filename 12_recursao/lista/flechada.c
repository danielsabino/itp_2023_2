#include <stdio.h>
#include <stdlib.h>

typedef struct item{
  char nome[20];
  int valor;
  int peso;
} Item;

void monta_inventario(Item* todos, Item* temp, Item* melhor, int total, int selecionados, int* tam_melhor, int limite, int peso_atual){
  //Inventário cheio
  if(peso_atual == limite){
    int novo, atual;

    novo = atual = 0;

    for(int i=0; i<selecionados; i++)
      novo += temp[i].valor;

    for(int i=0; i<*tam_melhor; i++)
      atual += melhor[i].valor;

    if(novo > atual){
      for(int i=0; i<selecionados; i++)
        melhor[i] = temp[i];

      *tam_melhor = selecionados;
    }
  }
  //Tenta botar mais alguma coisa
  else{
    for(int i=0; i<total; i++){
      if(todos[i].peso > 0 && todos[i].peso + peso_atual <= limite ){
        //Inclui o item
        peso_atual += todos[i].peso;
        temp[selecionados] = todos[i];
        todos[i].peso = 0;
        selecionados++;

        monta_inventario(todos, temp, melhor, total, selecionados, tam_melhor, limite, peso_atual);

        //Na volta, desfaz para testar novas combinações
        selecionados--;
        todos[i] = temp[selecionados];
        peso_atual -= todos[i].peso;
      }
    }
    //Se não consegue botar mais ninguém, verifica se o estado atual é melhor do que o que existe na sacola até então
    int novo, atual;

    novo = atual = 0;

    for(int i=0; i<selecionados; i++)
      novo += temp[i].valor;

    for(int i=0; i<*tam_melhor; i++)
      atual += melhor[i].valor;

    if(novo > atual){
      for(int i=0; i<selecionados; i++)
        melhor[i] = temp[i];

      *tam_melhor = selecionados;
    }
  }
}

int main(){
  int qtd, selecionados = 0, maior = 0;
  int limite;

  scanf("%d %d", &qtd, &limite);

  Item carrinho[qtd];
  Item melhor[qtd];
  Item aux[qtd];

  for(int i=0; i<qtd; i++){
    scanf(" %s %d %d", carrinho[i].nome, &carrinho[i].valor, &carrinho[i].peso);
  }

  monta_inventario(carrinho, aux, melhor, qtd, 0, &selecionados, limite, 0);

  if(selecionados){
    int valor = 0;
    printf("Inventario final:\n");
    for(int i=0; i<selecionados; i++){
      printf("Item: %s\n", melhor[i].nome);
      valor += melhor[i].valor;
    }
    printf("Valor total: %d\n", valor);
  }
  else{
    printf("Nada para carregar...\n");
  }

  return 0;
}