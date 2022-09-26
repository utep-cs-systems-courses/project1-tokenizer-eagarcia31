#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char user_input[100];
  char **tokens;
  puts("\n\n\nWelcome to the Tokenizer");
  puts("Your Available options are:\n\t1. Type a string to store it\n\t2. Type 'q' to exit");
  while(1) {
    printf("> ");
    fgets(user_input, 100, stdin);
    if(user_input[0] == 'q') {
      //exit program better. ask
      puts("Exiting program");
      break;
    }
    //adds History
    puts("String successfully stored.");
    puts(user_input);
  }
}
