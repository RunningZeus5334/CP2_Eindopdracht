#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
  }
  p->level = 5;
};
