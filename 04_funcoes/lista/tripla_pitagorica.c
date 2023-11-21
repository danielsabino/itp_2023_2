#include <stdio.h>

int min(int a, int b, int c){
    if(a <= b && a <= c)
        return a;
    if(b <= a && b <= c)
        return b;
    if(c <= a && c <= b)
        return c;
}

int calcula_mdc(int a, int b, int c){
    int menor, mdc;
    menor = min(a,b,c);
    for(int i=1; i<menor; i++){
        if((a % i == 0) && (b % i == 0) && (c % i) == 0)
            mdc = i;
    }
    return mdc;    
}

int tripla_primitiva(int a, int b, int c){
    int teste_a = 0, teste_b = 0, teste_c = 0;
    int mdc;
    if(a*a == b*b + c*c)
        teste_a = 1;
    if(b*b == a*a + c*c)
        teste_b = 1;
    if(c*c == a*a + b*b)
        teste_c = 1;
    
    mdc = calcula_mdc(a,b,c);

    if(teste_a || teste_b || teste_c){
        if (mdc == 1)
            return 1;
        else
            return 2;
    }
    else
        return 3;
}

int main(){
    int a,b,c;
    int tripla;

    scanf("%d %d %d", &a, &b, &c);

    tripla = tripla_primitiva(a,b,c);
    
    if(tripla == 1)
        printf("tripla pitagorica primitiva\n");
    else if(tripla == 2)
        printf("tripla pitagorica\n");
    else
        printf("tripla\n");

    return 0;
}