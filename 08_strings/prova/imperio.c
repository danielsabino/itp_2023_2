#include <stdio.h>
#include <string.h>

#define TAMCHAVE 4
#define TAMMAXMENSAGEM 200

///Conjunto de simbolos
const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};

/**
 * Encontra o indice de um caractere no conjunto de simbolos.
 * Retorna -1 caso o caractere nao exista no conjunto de simbolos.
 */
int achaindice(char c) {
	for (int i=0; i<40; i++) if (S[i]==c) return i;
	return -1;
}

/**
 * Retorna o caractere do conjunto de simbolos correspondente
 * a um indice informado.
 */
char achasimbolo(int i) {
    while (i<0) i+=40;
    return S[i%40];
}

/**
 * Calcula a distancia positiva entre dois caracteres no 
 * conjunto de simbolos. Retorna -1 caso o caractere nao
 * exista no conjunto de simbolos.
 */ 
int distanciasimbolos(char c, char d) {
	int indice_c = achaindice(c);
	int indice_d = achaindice(d);
	if (indice_c < 0 || indice_d < 0) return -1;

	int distancia=indice_c-indice_d;
	if (distancia<0) distancia+=40;
	return distancia;
}

/**
 * Calcula a chave utilizada para encriptar a mensagem
 * CT com base em um fragmento KP da mensagem original.
 * Retorna 1 caso a chave seja encontrada ou 0 em caso
 * contrario.
 */
int descobrechave(char CT[], char KP[], int chave[]) {
    int tamKP=strlen(KP);
	int tamCT=strlen(CT);
    int chavedecifrada=0;
	int indicemaximo=tamCT-tamKP;

	for (int i=0; i<=indicemaximo && !chavedecifrada; i++) {
		int match=1;
		for (int j=0; j<TAMCHAVE && match; j++) {
			int poschave=(i+j)%TAMCHAVE;
			chave[poschave]=distanciasimbolos(CT[i+j], KP[j]);
			for (int k=j+TAMCHAVE; k<tamKP && match; k+=TAMCHAVE)
				if (chave[poschave]!=distanciasimbolos(CT[i+k], KP[k]))
					match=0;
			
		}
		chavedecifrada=match;
	}
	return chavedecifrada;
}

/**
 * Decifra (descriptografa) a mensagem CT utilizando a chave
 * informada.
 */
void decifra(char CT[], int chave[]) {
	for (int i=0; CT[i]!=0; i++)
		CT[i]=achasimbolo(achaindice(CT[i])-chave[i%TAMCHAVE]);
}	


int main() {
	int chave[TAMCHAVE];

	// Texto plano conhecido (known-plaintext)
	char KP[]="QUE A FORCA ESTEJA COM VOCE";
	
	// Mensagem cifrada (ciphertext)
	char CT[TAMMAXMENSAGEM];

	fgets(CT,TAMMAXMENSAGEM,stdin);
	CT[strlen(CT)-1]=0;     // para remover o \n ao final da mensagem
		
	int chavedescoberta=descobrechave(CT,KP,chave);

	if (chavedescoberta) {
		for (int i=0; i<TAMCHAVE; i++) printf("%d", chave[i]);
		printf("\n");
		decifra(CT,chave);
		printf("%s\n", CT);
	}
	else printf("Mensagem nao e da Resistencia!\n");
}
