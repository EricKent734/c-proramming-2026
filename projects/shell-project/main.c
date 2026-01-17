#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
void init_shell() {
  printf("\n\n*** Welcome to My Shell ***\n");
  printf("Type commands below:\n\n");
}

// Read User Input;
// Use getline() to read user input dynamically:

char *read_input() {
  char *input = NULL;
  size_t len = 0;
  getline(&input, &len, stdin);
  return input;
}

// parse input;
// Split the input into tokens (command and arguments) using strtok():

void parse_input(char *input, char **args) {
  int i = 0;
  args[i] = strtok(input, " \n");
  while (args[i] != NULL) {
    i++;
    args[i] = strtok(NULL, " \n");
  }
}

// Execute commands;
// Use fork() and execvp() to execute commands:

void execute_command(char **args) {
  pid_t pid = fork();
  if (pid == 0) { // Child process
    if (execvp(args[0], args) < 0) {
      perror("Error executing command");
    }
    exit(0);
  } else if (pid > 0) { // Parent process
    wait(NULL);         // Wait for child process to finish
  } else {
    perror("Fork failed");
  }
}

// Main Loop;

int main() {
  char *input;
  char *args[100];
  init_shell();
  while (1) {
    printf(">>> ");
    input = read_input();
    parse_input(input, args);
    if (strcmp(args[0], "exit") == 0) { // Exit condition
      free(input);
      break;
    }
    execute_command(args);
    free(input);
  }
  return 0;
}
