#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromo(char *);
char * remove_espacos(char *);
int verifica(char *, int, int);

int main(){
    // entrada: texto de entrada
    // eh_palindromo: guarda se o texto é ou não palíndromo
    char entrada[100];
    int eh_palindromo;
    
    // Leitura do texto de entrada
    scanf(" %[^\n]", entrada);

    eh_palindromo = palindromo(entrada);
    if(eh_palindromo){
        printf("O texto \"%s\" é palíndromo\n", entrada);
    }
    else{
        printf("O texto \"%s\" não é palíndromo\n", entrada);
    }

    return 0;
}

int palindromo(char *entrada){
    char * sem_espacos;

    sem_espacos = remove_espacos(entrada);
    return verifica(sem_espacos, strlen(sem_espacos), 0);
}

int verifica(char * sem_espacos, int len, int i){
    if(i <= len){
        if(sem_espacos[i] != sem_espacos[len-i-1]){
            return 0;
        }
        else{
            return verifica(sem_espacos, len, ++i);
        }
    }
    return 1;
}

char * remove_espacos(char * str){
    int len, j = 0;
    char * nova;

    len = strlen(str);

    nova = (char *)malloc(sizeof(char) * len + 1);
    strcpy(nova, str);

    
    for(int i = 0; i <= len; i++){
        if(str[i] != ' '){
            nova[j++] = str[i];
        }
    }
    return nova;
}

