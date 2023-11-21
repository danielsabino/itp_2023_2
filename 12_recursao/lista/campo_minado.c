#include <stdio.h>
#include <string.h>

//Simulação do Campo Minado
void processa_jogada(int lin, int col, int campo[lin+2][col+2], int x, int y, int* result){
  int cont = 0;

  if(campo[x][y] == -1){
    campo[x][y] = 12;
    *result = -1;
    return;
  }
  else if(campo[x][y] != 0)
    return;
  else{
    for(int i = x-1; i<=x+1; i++)
      for(int j = y-1; j<=y+1; j++)
        if(campo[i][j] == -1 || campo[i][j] == 11 || campo[i][j] == 12)
          cont++;

    campo[x][y] = cont;

    if(cont == 0){
      campo[x][y] = 9;
      if(x-1 > 0 && y-1 > 0) processa_jogada(lin, col, campo, x-1, y-1, result);
      if(x-1 > 0 && y+1 <=col) processa_jogada(lin, col, campo, x-1, y+1, result);
      if(x-1 > 0) processa_jogada(lin, col, campo, x-1, y, result);
      if(y-1>0) processa_jogada(lin, col, campo, x, y-1, result);
      if(y+1 <= col) processa_jogada(lin, col, campo, x, y+1, result);
      if(x+1 <= lin && y-1 > 0) processa_jogada(lin, col, campo, x+1, y-1, result);
      if(x+1 <= lin) processa_jogada(lin, col, campo, x+1, y, result);
      if(x+1 <= lin && y+1 <= col) processa_jogada(lin, col, campo, x+1, y+1, result);
    }
  }
}

void imprime_campo(int lin, int col, int campo[lin+2][col+2]){
  for(int i = 0; i<col+2; i++)
    printf("=");
  printf("\n");
  for(int i = 1; i<=lin; i++){
    for(int j=1; j<=col; j++)
      switch(campo[i][j]){
        case 0:
        case -1: printf("*");break;
        case 9: printf("0"); break;
        case 11: printf("B");break;
        case 12: printf("X");break;
        default: printf("%d", campo[i][j]);
      }
    printf("\n");
  }
}

void impressao_final(int lin, int col, int campo[lin+2][col+2]){
  int res = 0;
  for(int i=1; i<=lin; i++)
    for(int j=1; j<=col; j++)
      if(campo[i][j] == 0)
        processa_jogada(lin, col, campo, i, j, &res);
      else if (campo[i][j] == -1)
        campo[i][j] = 11;
  
  imprime_campo(lin, col, campo);
}

int main(){
  int lin, col, bombas, x, y, jogadas, res = 0;
  char jogada[20] = {0};

  scanf("%d %d", &lin, &col);

  int campo[lin+2][col+2];

  for(int i=0; i<lin+2; i++)
    for(int j=0; j<col+2; j++)
      campo[i][j] = 0;

  scanf("%d", &bombas);

  for(int i=0; i<bombas; i++){
    scanf("%d %d", &x, &y);
    campo[x][y] = -1;
  }

  scanf("%d", &jogadas);

  for(int i=0; i<jogadas; i++){
    scanf(" %s %d %d", jogada, &x, &y);

    if(strcmp(jogada, "Clica") == 0)
      processa_jogada(lin, col, campo, x, y, &res);
    else if(strcmp(jogada, "Marca") == 0)
      campo[x][y] = 11;

    if(res == -1)
      break;

    imprime_campo(lin, col, campo);
  }

  if(res != -1)
    printf("Você sobreviveu!\n");
  else
    printf("CABUUUUM!\nGame Over....\n");

  impressao_final(lin, col, campo);

  return 0;
}