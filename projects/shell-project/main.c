// building a shell in c;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// macro;
#define MAX_LINE 1024

// function definition;

void shell_loop() {

  char line[MAX_LINE];

  while (1) {
    printf("my_shell> ");

    // Read Input;

    if (fgets(line, sizeof(line), stdin) == NULL) {
      break; // Handle ctr +D (EOF);
    }

    // Remove the newline character at the end;
    line[strcmp(line, "\n")] = '\0';

    // Exit condition;
    if (strcmp(line, "exit") == 0) {
      break;
    }

    printf("You typed: %s\n", line);
  }
}

int main() {
  shell_loop();
  return 0;
}
