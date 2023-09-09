#include <stdio.h>
 
int primo(int n){
    int count = 0;
    
    for(int i=1;i<=n;i++){
        if(n % i == 0)
            count++;
    }
    if(count == 2)
        return 1;
    else
        return 0;
}

int gemeos(int n){
    if(primo(n) && primo(n+2))
        return 1;
    else
        return 0;
}

int main(){
    int n;

    scanf("%d", &n);
    if(gemeos(n))
        printf("Numero forma par de gemeos\n");
    else
        printf("Numero nao forma par de gemeos\n");
    return 0;
}