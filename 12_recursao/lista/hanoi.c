#include <stdio.h>

void move(int n, int from, int dest, int aux, int *mov){
    if(n == 0){
        return;
    }
    (*mov)++;
    move(n-1, from, aux, dest, mov);    
    printf("Move o disco em %d para %d\n", from, dest);    
    move(n-1, aux, dest, from, mov);
}

int main(){
    int n, mov = 0;
    scanf("%d", &n);

    move(n, 1, 3, 2, &mov);
    printf("Total de movimentos: %d\n", mov);
    return 0;
}