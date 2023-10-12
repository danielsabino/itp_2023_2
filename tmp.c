#include <stdio.h>

int main()
{
    int a;
 
    int x;
    int k;
    
    scanf("%d", &a);
    
    k = 100000;
    
    while(a>0){
        
        x = a%k;
        k = k/10;
        x = (x - (a%k)) / k;

        if(x != 0){
        
        printf("%d\n", x);
        }
        
    }
    
    return 0;
}
