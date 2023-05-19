#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct spellcard {
  char *spel;
};
// structs for the player with pointers
struct playerstats {
  int *spellslots[9];
  int *level;
  int *spelamount;
  struct spellcard *amount;
};

void readragged(int argc, char *argv[], struct playerstats); // read raaged array function


int main(int argc, char *argv[]) {

  
  struct playerstats player1;
  readragged(argc, &*argv, player1); // reading ragged array


}










//----------------------------------------
// read function
void readragged(int argc, char *argv[], struct playerstats player1) {

  for (int i = 0; i < argc; i++) {

    if (argv[i] != NULL) {
      if (strcmp(argv[i], "-s") == 0) {
        for (int j = 1; j <= 9; j++) {
          if (strcmp(argv[j + i], "-l") == 0 ||
              (strcmp(argv[j + i], "-h") == 0 || argv[j + i] == NULL)) {
            break;
          }
          player1.spellslots[j] = calloc(1, sizeof(int));
          *player1.spellslots[j] = atoi(argv[j + i]);
          printf("%d\n", *player1.spellslots[j]);
        }
      } else if (strcmp(argv[i], "-l") == 0) {
        int count = 0;
        for (int j = 1; j < 20; j++) {
          if (strcmp(argv[j + i], "-h") == 0 || argv[j + i] == NULL) {
            break;
          }
          if (j == 1) {
            player1.level = calloc(1, sizeof(int));
            *player1.level = atoi(argv[j + i]);
            printf("%d\n", *player1.level);
          } else
            count++;
        }
        player1.spelamount = calloc(1, sizeof(int));
        *player1.spelamount = count;
        player1.amount = (struct spellcard *)calloc(*player1.spelamount, sizeof(struct spellcard));
        for (int j = 2; j <2+ *player1.spelamount; j++) {
          player1.amount[j].spel = (char *)calloc(strlen(argv[j + i]) + 1, sizeof(char));
          strcpy(player1.amount[j].spel, argv[j + i]);
          printf("%s\n", player1.amount[j].spel);
        }
      }
     else if (strcmp(argv[i], "-h") == 0) {
      printf("test3\n");
     }
    }
  }
}
