#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ik mag geen c++ dus:
#define FALSE 0
#define TRUE 1
typedef char* string;
typedef uint8_t boolean;

typedef enum{V,S,M}component_types;
typedef enum{sphere,cone,cylinder,line,cube}effect_area_types;

typedef struct{
string index;
string name;
string url;
}spellclass;

typedef struct{

}damage;

typedef struct{
int size;
effect_area_types type;
}effectarea;


/*
the struct for all the spells
*/
typedef struct{
spellclass spellname;
string desc;
string higher_level;
string range;
component_types components;
string material;
effectarea area_of_effect;
boolean ritual;
string duration;
boolean concentration;
string casting_time;
int level;
string attack_type;
spellclass school;
spellclass classes;
spellclass subclasses;
}spell;


struct character {
  uint8_t level;
  uint8_t spells[]; // spell level //amount of spells
};


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
// make form json file structs
// read ragged array
void readragged(int argc, char *argv[], struct playerstats); // read ragged array function
void JSON_Fetch(char *spellname /*name of the spell to fetch*/);


int main(int argc, char *argv[]) {
  struct character player;
  
  struct playerstats player1;
  readragged(argc, &*argv, player1); // reading ragged array


  //Read_Input();
  JSON_Fetch("vicious-mockery");


  return 0;
}


int Read_Input(){

  return 5;
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

void JSON_Fetch(char *spellname){
char CLI_buffer[1000];
snprintf(CLI_buffer, sizeof(CLI_buffer),"curl https://www.dnd5eapi.co/api/spells/%s", spellname);
FILE *fp;
char JSON_FILE[3000];
fp = popen(CLI_buffer, "r");
  
if (fp == NULL) {
  printf("Error opening CLI_buffer\n");
  return;
}else{
  fgets(JSON_FILE, sizeof(JSON_FILE)-1, fp);
  //printf(JSON_FILE);
  system("clear");    
  FILE *JSON;
  char filename[30];
  sprintf(filename, "%s.json", spellname);
  JSON = fopen("json.json", "w");
  fprintf(JSON, JSON_FILE);
  fclose(JSON);
  }
}


