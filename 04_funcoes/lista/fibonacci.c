#include <stdio.h>

long long int fibonacci(int n){
    long long int n1 = 1, n2 = 1, n3;

    if(n == 1 || n == 2){
        return 1;
    }
    else{
        for(int i=3; i<=n; i++){
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
}

void imprimir_fibonacci(int n){
    long long int n_termo;

    n_termo = fibonacci(n);
    printf("%lld\n", n_termo);
}

int main(){
    int n;

    scanf("%d", &n);
    
    imprimir_fibonacci(n);

    return 0;
}