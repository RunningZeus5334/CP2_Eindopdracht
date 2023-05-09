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

// make form json file structs
// read ragged array


int main(int argc, char *argv[]) {
  struct character player;


  Read_Input();
  
  return 0;
}


int Read_Input(){

  return 5;
}

