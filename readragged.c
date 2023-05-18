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
  struct spellcard *amount;
};

void readragged(int argc, char *argv[], struct playerstats); //read raaged array function

int main(int argc, char *argv[]) {
 struct playerstats player1; 
  readragged(argc, &*argv,  player1);  // reading ragged array


}






//----------------------------------------
// read function
void readragged(int argc, char *argv[], struct playerstats player1) {

  for (int i = 0; i < argc; i++) {
   

    if (argv[i] != NULL) {
      if (strcmp(argv[i], "-s") == 0) {
        for(int j = 1; j <= 9; j++){
          if (strcmp(argv[j+i], "-l") == 0 ||(strcmp(argv[j+i], "-h") == 0 || argv[j+i] == NULL)){
            printf("we breaking now\n");
            break;
          } 
          printf("%s\n", argv[j+i]);
          player1.spellslots[j] = calloc(1, sizeof(int));
          *player1.spellslots[j] = atoi(argv[j+i]);
          printf("%d\n", *player1.spellslots[j]);
        }
      } else if (strcmp(argv[i], "-l") == 0) {
        int count = 0;
        for(int j = 1; j < 20){
          if (strcmp(argv[j+i], "-h") == 0 || argv[j+i] == NULL){
            printf("we breaking now\n");
            break;
          }
        if(j == 1){  
        player1.level = calloc(1, sizeof(int));
        *player1.level = atoi(argv[j+i]);
        } 
        else
        count++;
        }
        for (int j = 0; j < count; j++){
          
        }
        
      }
      
        printf("test2\n");
      } else if (strcmp(argv[i], "-h") == 0) {
        printf("test3\n");
      }
    }
  }
}
