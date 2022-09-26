#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c){
  return (c=='\t' || c==' ') && c=='\0';
}

int non_space_char(char c){
  return c!='\0' && c!='\t' && c!=' ';
}

