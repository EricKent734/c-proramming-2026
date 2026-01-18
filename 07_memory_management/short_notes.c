#include <stdio.h>
#include <stdlib.h>

int main() {

  // malloc: It asks the OS for a specific number of bytes. It returns a pointer
  // to the start of that block
  int *ptr = malloc(5 * sizeof(int)); // Reserves space for 5 integers ;

  // calloc: Like malloc, but it initializes all the memory to zero
  int *ptr = calloc(5, sizeof(int)); // 5 integers, all set to 0;

  // realloc: if your array is full and you need more space, realloc grows (or
  // shrinks) the block.
  ptr = realloc(ptr, 10 * sizeof(int)); // now has room for 10;

  // free: This tells the OS: "I'm done with this memory. You can have it back."
  free(ptr);

  return 0;
}
