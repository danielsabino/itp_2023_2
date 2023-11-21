#include <stdio.h>

typedef struct {
  int id;
  char name[31];
  int quant;
} Party;

int add_vote(int num_parties, Party parties[num_parties],int vote) {
  for(int i = 0; i < num_parties; i++) {
    if (parties[i].id == vote) {
      parties[i].quant++;
      return 1;
    }
  }
  return 0;
}

int compute_votes(
  int num_votes, int votes[num_votes],
  int num_parties, Party parties[num_parties],
  Party *most_voted, Party *second_most_voted
) {
  int valid_votes = 0;
  for(int i = 0; i < num_votes; i++) {
    valid_votes += add_vote(num_parties, parties, votes[i]);
  }
  *most_voted = parties[0];
  for(int i = 1; i < num_parties; i++) {
    if (parties[i].quant > most_voted->quant) {
      *most_voted = parties[i];
    }
  }
  int count = 0;
  for(int i = 0; i < num_parties; i++) {
    if (parties[i].id != most_voted->id && parties[i].quant > count) {
      *second_most_voted = parties[i];
      count = parties[i].quant;
    }
  }
  return valid_votes;
}


int main() {
  int n, m;
  Party first, second;
  
  scanf("%i", &n);
  Party parties[n];
  for(int i = 0; i < n; i++) {
    scanf("%i", &parties[i].id);
    scanf("%s", parties[i].name);
    parties[i].quant = 0;
  }

  scanf("%i", &m);
  int votes[m];
  for(int i = 0; i < m; i++) {
    scanf("%i", &votes[i]);
  }
  int valids = compute_votes(m, votes, n, parties, &first, &second);
  printf("VENCEDOR: %s (%i votos = %.2f%%)\n", first.name, first.quant, 100*(float)first.quant/valids);
  printf("VICE: %s (%i votos = %.2f%%)\n", second.name, second.quant, 100*(float)second.quant/valids);

  return 0;
}