#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

//returns 1 if char is a blank or space
int space_char(char c){
  return (c=='\t' || c==' ') && c=='\0';
}

//return 1 if char is not a blank or space
int non_space_char(char c){
  return c!='\0' && c!='\t' && c!=' ';
}

//returns a pointer to the start of a word
char *word_start(char *string) {
  for(int k=0; space_char(*string);string++) {}
  return string;
}

//returns a pointer to the end of the word
char *word_terminator(char *word){
  int k=0;
  while(*(word + k)){
    if(space_char(*(word + k))){
      return word + k;
    }
    k++;
  }
  return word + k;
}

int count_words(char *string){
  int words=0;
  int count=0;
  while(*string != '\0') {
    if(non_space_char(*string) && words == 0) {
      count++;
      words = 1;
    }
    else if(space_char(*string) == 1 && words == 1) {
      words = 0;
    }
    string++;
  }
  return count;
}
