#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int extrair_data(char *data, int *dia, int *mes, int *ano){
    // tam: tamanho da string;
    // campos: matriz que armazena nas linhas os campos da data
    // num_campo: indica o campo a ser preechido no momento
    // pos_campo: indica a posição do campo a ser preenchida
    int tam;
    char campos[3][10];
    int num_campo = 0, pos_campo = 0;

    tam = strlen(data);
    
    for(int i = 0; i < tam; i++){
        if(data[i] == '/' || data[i] == '-'){
            campos[num_campo][pos_campo] = '\0';
            num_campo++;
            pos_campo = 0;
        }
        else{
            campos[num_campo][pos_campo] = data[i];
            pos_campo++;
        }        
    }
    campos[2][pos_campo] = '\0';
    
    // Verificações
    if(strlen(campos[0]) > 2 || strlen(campos[1]) > 2 || strlen(campos[2]) > 4){
        return 0;
    }

     *dia = atoi(campos[0]);
     *mes = atoi(campos[1]);
     *ano = atoi(campos[2]);

    return 1;
}

int main(){
    // data: data lida da entrada
    // check: verifica se há uma data válida na entrada
    // dia, mes, ano: armazenam o dia, mês e ano extraídos da data
    char data[20];
    int check;
    int dia = 0, mes = 0, ano = 0;
    
    // Leitura da entrada
    scanf(" %s", data);

    // Chamada da função que faz a extração dos campos da entrada
    check = extrair_data(data, &dia, &mes, &ano);

    if(check){
        printf("%02d/%02d/%4d\n", dia, mes, ano);
    }
    else{
        printf("INVALIDO!\n");
    }
    return 0;
}