#include <stdio.h>
#include <string.h>

void encontra_inicio_fim(char * email, int * inicio, int * fim){
    int achou = 0, tamanho;

    tamanho = strlen(email);    
    for(int i=0;i<tamanho; i++){
        if(email[i] == '@'){
            *inicio = i;
            achou = 1;
        }
        else if(email[i] == '.' && achou){
            *fim = i;
            break;
        }
    }
}

int main(void){
    char email[51];
    int inicio, fim;

    scanf(" %s", email);

    while(strcmp(email, "FIM")){        
        encontra_inicio_fim(email, &inicio, &fim);

        for(int i=inicio+1;i<fim;i++){
            printf("%c", email[i]);
        }
        
        printf("\n");
        scanf(" %s", email);
    }

    return 0;
}