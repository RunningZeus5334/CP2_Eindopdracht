#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json.h"
#include "inputoutput.h"



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
int size;
effect_area_types type;
}effectarea;




/*
the struct for all the spells
*/
typedef struct{
string index;
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
  uint8_t *level;
  uint8_t *num_spells; // spell level //amount of spells
  spell spells[];
}character;

// make form json file structs
// read ragged array
void readragged(int argc, char *argv[], struct character); // read ragged array function
void JSON_Fetch(char *spellname /*name of the spell to fetch*/);

int main(int argc, char *argv[]) {
  struct character player1;
  
  readragged(argc, &*argv, player1); // reading ragged array

  Greeting(); 
  int function_called=1;
  while (function_called){
  function_called = StartFunq(GetFunq());
  }
  


  return 0;
}


int Read_Input(){

  return 5;
}

//----------------------------------------
// read function
void readragged(int argc, char *argv[], struct character player1) {

  for (int i = 0; i < argc; i++) {

    if (argv[i] != NULL) {
      if (strcmp(argv[i], "-s") == 0) {
        for (int j = 1; j <= 9; j++) {
          if (strcmp(argv[j + i], "-l") == 0 ||
              (strcmp(argv[j + i], "-h") == 0 || argv[j + i] == NULL)) {
            break;
          }
          player1.num_spells = calloc(1, sizeof(int));
          player1.num_spells[j] = atoi(argv[j + i]);
          printf("%d\n", player1.num_spells[j]);
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
 
          player1.num_spells = calloc(1, sizeof(int));
          *player1.num_spells = count;
          for (int j = 2; j <2+ *player1.num_spells; j++) {
          player1.spells[j].index = (char *)calloc(strlen(argv[j + i]) + 1, sizeof(char));
          char tmp[50];
          sscanf(argv[j + i], "%[^.] \0.json", player1.spells[j].index);
          JSON_Fetch( player1.spells[j].index);
          printf("%s\n", player1.spells[j].index);

      }
      else if (strcmp(argv[i], "-h") == 0) {
      printf("test3\n");
     }
    }
  }
}

