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

//returns the number of words counted
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

char *copy_str(char *input, short length) {
  char *output = (char*) malloc(sizeof(char) * length + 1);

  if(!output){
    exit(EXIT_FAILURE);
  }

  char *c = output;

  for(short k=0; k < length; k++) {
    *c = *input;
    if(*c=='\0'){
      break;
    }
    c++;
    input++;
  }
  *c=='\0';
  return output;
}

char **tokenize(char* string) {
  int words = count_words(string);
  char **tokens = malloc(sizeof(char*) * (words+1));

  if(!tokens) {
    exit(EXIT_FAILURE);
  }

  string = word_start(string);
  for(int k=0; k < words; k++) {
    char* terminator = word_terminator(string);
    tokens[k] = copy_str(string, terminator - string);
    string = word_start(terminator);
  }

  char **terminator = tokens + words;
  *terminator = 0;
  return tokens;
}

void print_tokens(char **tokens) {
  for(char** token = tokens; *token != 0; token++) {
    printf("\t[%ld] %s\n", token - tokens, *token);
  }
}

void free_tokens(char **tokens) {
  int k = 0;
  //frees elements within tokens
  while(tokens[k]) {
    free(tokens[k]);
    k++;
  }
  //frees an empty tokens
  free(tokens);
}
