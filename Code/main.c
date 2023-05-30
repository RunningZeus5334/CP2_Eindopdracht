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
string name;
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

struct character readragged(int argc, char *argv[], struct character); // read ragged array function
void JSON_Fetch(char *spellname /*name of the spell to fetch*/);
void Json_Parser(struct character);
void functionfree(struct character);

int main(int argc, char *argv[]) {
  struct character player1;
  player1 = readragged(argc, &*argv, player1); // reading ragged array
//  Json_Parser(player1);
  Greeting(); 
  int function_called=1;
  while (function_called){
  function_called = StartFunq(GetFunq());
  }


  functionfree(player1);
  return 0;
  
}


int Read_Input(){

  return 5;
}

//----------------------------------------
// read function
struct character readragged(int argc, char *argv[], struct character player1) {


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
          sscanf(argv[j + i], "%[^.]", player1.spells[j].index);
          JSON_Fetch( player1.spells[j].index);
          printf("%s\n", player1.spells[j].index);
          }

      }
      else if (strcmp(argv[i], "-h") == 0) {
      printf("test3\n");
     }
    }
  }
return player1;
}


void Json_Parser(struct character player1){
   
for(int k = 2 ; k < 20; k++){  
  for (int i = 0 ; i < 2; i++){
  if(player1.spells[k].index == NULL)
    break;
    
  }
  printf("%s\n",player1.spells[k].index);
FILE *filePointer = fopen(player1.spells[k].index, "r"); // Open file for reading
  if (filePointer == NULL) // Check if file is succesfully opened
  {
    perror("File opening failed"); // Print error
    exit(1);                     // Stop program
  }
  char buffer[1024];    // Prepare a line buffer
  char *parsing = NULL; // Prepare helper pointer for strsep
  int counter = 0;      // Prepare helper counter for printing
  while (!feof(filePointer)) // Keep reading file till EndOfFile is reached
  {
    if (fgets(buffer, sizeof(buffer), filePointer) ==
        NULL) // Read one line (stops on newline or eof), will return NULL on
              // eof or fail
    {
      fclose( filePointer );
      break; // Stop reading
    }
    parsing = buffer; // Point to buffer (reset)
    char *token = strsep(&parsing, "\"");
    while (token) // If token exists
    {
     // printf("token = %s\n",token);
    
      token = strsep(&parsing, "\""); // Find next token
                                      //  printf("%s\n", buffer);
      if (token != NULL) {
        //printf("token2 = %s\n",token);
       // printf("%s\n",buffer);
      //  printf("token = %s\n\n",token);
        if (strcmp(token, "desc") == 0) {
          char *desc = strtok(&parsing[2], "]");
          player1.spells[k].desc = (char*)calloc(strlen(desc), sizeof(char));
          strcpy(player1.spells[k].desc, desc);
          printf("decs = %s\n\n", player1.spells[k].desc);
        }
         else if (strcmp(token, "higher_level") == 0) {
          char *higher_level = strtok(&parsing[0], "]");
          player1.spells[k].higher_level = (char*)calloc(strlen(higher_level), sizeof(char));
          strcpy(player1.spells[k].higher_level, higher_level);
          printf("higher_level = %s\n\n", player1.spells[k].higher_level);
        }
        
         else if (strcmp(token, "range") == 0) {
          
          char *range = strtok(&parsing[2], ",");
          player1.spells[k].range = (char*)calloc(strlen(range), sizeof(char));
          strcpy(player1.spells[k].range, range);
          printf("range = %s\n\n", player1.spells[k].range);
        }
        
        //printf("token = %s\n\n",token);

           }
         }
       }
    }
  }
}


void functionfree(struct character player1){

for(int8_t i = 2; i < 3; i++ ){
if(player1.spells[i].desc != NULL){free(player1.spells[i].desc);}  
if(player1.spells[i].index != NULL){free(player1.spells[i].index);}
if(player1.spells[i].name != NULL){free(player1.spells[i].name);}
if(player1.spells[i].range != NULL){free(player1.spells[i].range);}
if(player1.spells[i].higher_level != NULL){free(player1.spells[i].higher_level);}
}
}

