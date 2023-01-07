#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MISTAKES 6  // maximum number of mistakes allowed

int main() {
  // array of possible words to choose from
  const char *words[] = {"apple", "banana", "orange", "strawberry", "mango"};

  // choose a random word from the array
  srand(time(0));
  const char *word = words[rand() % 5];

  int word_length = strlen(word);
  char guessed_letters[26] = {0};  // stores the letters that have been guessed
  char current_state[50] = {0};   // stores the current state of the word being guessed
  int mistakes = 0;                // number of mistakes made so far

  // initialize the current_state to be a series of underscores, one for each letter in the word
  for (int i = 0; i < word_length; i++) {
    current_state[i] = '_';
  }

  // continue the game until the word is fully guessed or the maximum number of mistakes is reached
  while (strcmp(word, current_state) != 0 && mistakes < MAX_MISTAKES) {
    printf("Current state: %s\n", current_state);
    printf("Enter a letter: ");

    char ch;
    scanf(" %c", &ch);

    // check if the letter has already been guessed
    if (guessed_letters[ch - 'a']) {
      printf("You have already guessed the letter '%c'. Try again.\n", ch);
      continue;
    }

    // mark the letter as guessed
    guessed_letters[ch - 'a'] = 1;

    // check if the letter is in the word
    int letter_in_word = 0;
    for (int i = 0; i < word_length; i++) {
      if (word[i] == ch) {
        current_state[i] = ch;
        letter_in_word = 1;
      }
    }

    if (!letter_in_word) {
      printf("Sorry, the letter '%c' is not in the word.\n", ch);
      mistakes++;
    }
  }

  if (mistakes == MAX_MISTAKES) {
    printf("You lost! The word was '%s'.\n", word);
  } else {
    printf("Congratulations, you won! The word was '%s'.\n", word);
  }

  return 0;
}
