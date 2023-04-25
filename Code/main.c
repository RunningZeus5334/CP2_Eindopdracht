#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct character {
  uint8_t level;
  uint8_t spells[]; // spell level //amount of spells
};

// make form json file structs
// read ragged array
void readargv(int argc, char *argv[], struct character *p);

int main(int argc, char *argv[]) {
  struct character player;

  readargv(argc, argv, &player);
  printf("Done\n");
  printf("%d\n", player.level);

  return 0;
}

void readargv(int argc, char *argv[], struct character *p) {

  for (int i = 0; i < argc; i++) {
    printf("%s/n", argv[i]);

    if (strncmp(argv[i], "-s", 2)) {
      p->spells[0] = atoi(argv[i + 1]);
      p->spells[1] = atoi(argv[i + 2]);
      p->spells[2] = atoi(argv[i + 3]);
      p->spells[3] = atoi(argv[i + 4]);
      p->spells[4] = atoi(argv[i + 5]);
      p->spells[5] = atoi(argv[i + 6]);
      p->spells[6] = atoi(argv[i + 7]);
      p->spells[7] = atoi(argv[i + 8]);
      p->spells[8] = atoi(argv[i + 9]);
      p->spells[9] = atoi(argv[i + 10]);
    }
  }
};
