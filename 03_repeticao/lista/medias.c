#include <stdio.h>
#include <math.h>

int main(){
    // n: valor atual de entrada
    // aritmetica, harmonica, geometrica: variáveis que vão acumular os valores de entrada
    // erro_h, erro_g, erro_m: erro harmônica, erro geomátrica, erro médio
    double n;
    double aritmetica = 0, harmonica = 0, geometrica = 1;
    double erro_h, erro_g, erro_m;
    
    // Leitura dos valores de entrada
    for(int i = 0; i < 10; i++){
        scanf("%lf", &n);
        aritmetica += n;
        harmonica += 1.0/n;
        geometrica *= n;        
    }

    // Cálculo das médias
    aritmetica = aritmetica / 10.0;
    harmonica = 10.0/harmonica;
    geometrica = pow(geometrica, 1.0/10);

    // Impressão das médias
    printf("Média aritmética é %.2lf\n", aritmetica);
    printf("Média harmônica é %.2lf\n", harmonica);
    printf("Média geométrica é %.2lf\n",geometrica);

    // Cálculo dos erros
    erro_h = (harmonica - aritmetica)/aritmetica;
    erro_g = (geometrica - aritmetica)/aritmetica;
    erro_m = (erro_h + erro_g)/2.0;

    // Impressão do erro
    printf("Erro médio é %.2lf %%\n", erro_m*100);

    return 0;
}