/* learning about memory allocation using
 * the malloc function */

// code snippet 1:
//
//
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Enter size: ");
  scanf("%d", &n);

  // 1. ALLOCATE
  int *arr = malloc(n * sizeof(int));

  // 2. CHECK (Always check if malloc failed)
  if (arr == NULL) {
    printf("Memory allocation failed!");
    return 1;
  }

  // 3. USE
  for (int i = 0; i < n; i++) {
    arr[i] = i * 2;
    printf("%d ", arr[i]);
  }

  // 4. FREE
  free(arr);
  arr = NULL; // Good practice: prevent "dangling pointers"

  return 0;
}

// Code snippet 2 : about Malloc:
// using char
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
  char *mem_alloc;
  // memory allocated dynamically
  mem_alloc = malloc(15 * sizeof(char));

  if (mem_alloc == NULL) {
    printf("Couldn't able to allocate requested memory\n");
  } else {
    strcpy(mem_alloc, "w3schools.in");
  }

  printf("Dynamically allocated memory content : %s\n", mem_alloc);
  free(mem_alloc);
}
