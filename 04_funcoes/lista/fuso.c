#include <stdio.h>

void fuso(int s, int t, int f){
    int chegada;
    
    chegada = s + t + f;

    if(chegada == 24)
        chegada = 0;
    if(chegada > 24)
        chegada = chegada - 24;
    if(chegada < 0)
        chegada = chegada + 24;
    
    printf("Hora de saída: %d\n", s);
    printf("Hora de chegada: %d\n", chegada);    
}

int main(){
    int s,t,f;
    scanf("%d %d %d", &s, &t, &f);
    fuso(s,t,f);
    return 0;
}