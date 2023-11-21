
#include <stdio.h>
#include <string.h>

void read_set(int n, char prefix[n][11]){
	for(int i=0;i<n;i++){
		scanf("%10s", &prefix[i]);
	}
}

int start_index(char word [], int n, char prefix[n][11]){
	int total = strlen(word);
	for(int i=0;i<n;i++){
		int len = strlen(prefix[i]);
		if(total >= len && strncmp(word, prefix[i], len) == 0){
			return len;
		}
	}
	return 0;
}

int end_index(char word [], int n, char sufix[n][11]){
	int total = strlen(word);
	for(int i=0;i<n;i++){
		int len = strlen(sufix[i]);
		if(total >= len && strcmp(word + total - len, sufix[i]) == 0){
			return total - len;
		}
	}
    return total;
}

int main(void){
	int n;
	scanf("%d", &n);
	char prefix [n][11];
	read_set(n, prefix);
	
	int m;
	scanf("%d", &m);
	char sufix [m][11];
	read_set(m, sufix);
	
	char buffer [101];
	char printer [101];
	scanf("%s", buffer);
	while (strcmp("-1", buffer) != 0){
		int start = start_index(buffer, n, prefix);
		int end = end_index(buffer, m, sufix);
		if(start != end){
			buffer[end] = '\0';
			printf("%s\n", buffer + start);
		}
		scanf("%s", buffer);
	}
}
