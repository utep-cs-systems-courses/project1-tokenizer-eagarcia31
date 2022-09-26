#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history() {
  List *list = (List*) calloc(1, sizeof(List));
  if(!list) {
    //Needs to exit program
  }
  return list;
}

void add_history(List *list, char *str){
  //add
}

char *get_history(List *list, int id){
  //add
}

void print_history(List *list){
  //add
}

void free_history(List *list){
  //add
}
