#include <stdio.h>
#include <string.h>

int search(char t[], char p[]) {
    int n = strlen(t);
    int m = strlen(p);
    
    int v[n];
    for(int i = 0; i < n; i++) {
        v[i] = 0;
        for(int j = m-1; j >= 0; j--) {
            if (t[i] ==  p[j]) {
                v[i] = 1;
                break;
            }
        }
    }
    for(int i = 0; i <= n-m; i++) {
        for(int j = 0; j < m; j++) {
            printf("%c ", t[i+j]);
            if (t[i+j] != p[j]) {
                printf("não\n");
                if (!v[i+j]) {
                    i += j;
                }
                break;
            }
            else if (j == m-1) {
                printf("sim\n");
                return i;
            }
        }
    }
    return -1;
}

int main() {
    char text[50];
    char pattern[50];
    scanf("%s %s", text, pattern);
    
    int p = search(text, pattern);
    if (p < 0) {
        printf("Não achei o padrão\n");
    }
    else {
        printf("Achei o padrão no índice %i\n", p);
    }
}