#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history() {
  List *list = (List*) malloc(sizeof(List));
  if(!list) {
    fprintf(stderr, "Method: init_history Error with memory allocation");
    exit(EXIT_FAILURE);
  }
  return list;
}

int str_len(char *str){
  char *pointer = str;
  while(pointer != '\0') {
    pointer += 1;
  }
  return pointer - str;
}

void add_history(List *list, char *str){
  Item *new_item = (Item*) malloc(sizeof(Item));
  Item *item = list ->root;
  Item *previous_item;
  int index;
  int str_length = str_len(*str);
  new_item -> str = copy_str(str, str_length);

  if(!item) {
    list->root = new_item;
    new_item->id = 1;
  }
  else {
    index=0;
    while(item) {
      previous_item = item;
      item = item->next;
      index += 1;
    }
    previous_item->next = new_item;
    new_item->id = index + 1;
  }
}

char *get_history(List *list, int i){
  Item *current_item = list->root;
  while(current_item) {
    if(current_item->id == i+1) {
      return current_item->str;
    }
    current_item = current_item->next;
  }
}

void print_history(List *list){
  Item *current_item = list->root;
  while(current_item) {
    printf("\t[%d] - %s\n", current_item->id, current_item->str);
    current_item = current_item->next;
  }
}

void free_history(List *list){
  Item *current_item = list->root;
  Item *prev_item;
  while(current_item) {
    prev_item = current_item;
    current_item = current_item->next;
    free(prev_item->str);
    free(prev_item);
  }
  free(list);
}
