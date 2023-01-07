#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//
#define MAX_MISTAKES 6  

int main() {
  //
  const char *words[] = {"famnit", "bioinformatics", "dorm", "seaside", "computerpracticum"};

  //
  srand(time(0));
  const char *word = words[rand() % 5];

  int word_length = strlen(word);
  char guessed_letters[26] = {0};  //letters that have been guessed
  char current_state[50] = {0};   // current state of the word being guessed
  int mistakes = 0;                // number of mistakes made so far

  //
  for (int i = 0; i < word_length; i++) {
    current_state[i] = '_';
  }

  //
  while (strcmp(word, current_state) != 0 && mistakes < MAX_MISTAKES) {
    printf("Current state: %s\n", current_state);
    printf("Enter a letter: ");

    char ch;
    scanf(" %c", &ch);

    //
    if (guessed_letters[ch - 'a']) {
      printf("You have already guessed the letter '%c'. Try again.\n", ch);
      continue;
    }

    //nned a new part
    
    //
    guessed_letters[ch - 'a'] = 1;

   
    //
    if (!letter_in) {
      printf("Sorry, the letter '%c' is not in the word.\n", ch);
      mistakes++;
    }
  }
    //
  if (mistakes == MAX_MISTAKES) {
    printf("IM SORRY, you lose! The word that you needed to guess was '%s'.\n", word);
  } else {
    printf("WOW, you won! The word indeed was: '%s'.\n", word);
  }

  return 0;
}
