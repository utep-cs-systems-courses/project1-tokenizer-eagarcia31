#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

static void process_input(char *user_input, List *history, int history_length) {
  if(user_input[1] == ' ' || user_input[1] == '\0' || user_input[1] == 'h'){
    printf("\tHISTORY:\n");
    print_history(history);
    printf("*******************************************\n");
  }
  else if(user_input[1] == 'q') {
    free_history(history);
    puts("EXITING TOKENIZER");
    exit(EXIT_SUCCESS);
  }
  else {
    int asked_index = atoi(user_input + 1);
    if(asked_index > 0) {
      char *str = get_history(history, asked_index - 1);
      if(!str) {
	puts("NO HISTORY FOUND");
	return;
      }
      char **tokens = tokenize(str);
      print_tokens(tokens);
      free_tokens(tokens);
    }
    else{
      puts("INVALID INDEX");
      return;
    }
  }
}

int main(){
  char user_input[100];
  List *history = init_history();
  char **tokens;
  int history_length = 0;
  puts("\n\n\nWelcome to the Tokenizer");
  puts("Your Available options are:\n\t1. Type a string to store it\n\t2. Type '!h' or '!' to display previous entries\n\t3.Type '!q' to exit the program\n");
  while(1) {
    printf("> ");
    fgets(user_input, 100, stdin);
    if(user_input[0] == '!') {
      process_input(user_input, history, history_length);
    }
    else{
      add_history(history, user_input);
      puts("String successfully stored.");
      puts(user_input);
      history_length+=1;
    }
  }
}
