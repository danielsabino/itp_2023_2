#include <stdio.h>

int main(){
    // Variáveis
    // temperatura: temperatura informada pelo usuário
    // escala: escala da temperatura informada
    // temp_c, temp_f, temp_k: temperaturas nas escalas celsius, farenheit e kelvin
    float temperatura;
    char escala;
    float temp_c, temp_f, temp_k;

    // Leitura da entrada
    scanf("%f %c", &temperatura, &escala);

    // Conversão dos se entrada for Celsius
    if(escala == 'C'){
        temp_c = temperatura;
        temp_f = temperatura * 1.8 + 32;
        temp_k = temperatura + 273.15;
    }
    if(escala == 'F'){
        temp_f = temperatura;
        temp_c = (temperatura - 32)/1.8;
        temp_k = temp_c + 273.15;
    }
    if(escala == 'K'){
        temp_k = temperatura;
        temp_c = temperatura - 273.15;
        temp_f = temp_c * 1.8 + 32;
    }
    printf("Celsius: %.2f\n", temp_c);
    printf("Farenheit: %.2f\n", temp_f);
    printf("Kelvin: %.2f\n", temp_k);

    return 0;
}