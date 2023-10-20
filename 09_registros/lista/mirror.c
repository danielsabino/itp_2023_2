#include <stdio.h>

typedef struct img{
    int w, h;
    int pixels[20][20];
}Img;

void imprimir(Img imagem){
    printf("%d %d\n", imagem.w, imagem.h);
    for(int i = 0; i < imagem.h; i++){
        for(int j = 0; j < imagem.w; j++){
            printf("%d  ", imagem.pixels[i][j]);
        }
        printf("\n");
    }
}

Img reflete(Img img_in){
    Img img_out;
    img_out.h = img_in.h;
    img_out.w = img_in.w;

    for(int i = 0; i < img_in.h; i++){
        for(int j = 0; j < img_in.w; j++){
            if(i < img_in.h / 2){
                img_out.pixels[i][j] = img_in.pixels[img_in.w - 1 - i][j];
            }
            else{
                img_out.pixels[i][j] = img_in.pixels[i][j];
            }
            
        }
    }
    return img_out;
}

int main(){
    // img_in: imagem lida da entrada
    // img_out: imagem refletida
    Img img_in, img_out;

    // Leitura das dimensões da imagem
    scanf("%d %d", &img_in.w, &img_in.h);

    // Leitura dos valores de pixel da imagen
    for(int i = 0; i < img_in.h; i++){
        for(int j = 0; j < img_in.w; j++){
            scanf("%d", &img_in.pixels[i][j]);
        }
    }

    // Chama função para refletir imagem
    img_out = reflete(img_in);
    // Imprime o tamanho e a imagem    
    imprimir(img_out);

    return 0;
}