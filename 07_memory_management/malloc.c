/*
*
* Certainly! Let’s break down that code block step-by-step. Think of this
process like **renting a hotel room.**

### 1. The Setup (Headers)
```c
#include <stdio.h>
#include <stdlib.h>
```
*   `stdio.h`: Standard Input/Output (for `printf` and `scanf`).
*   **`stdlib.h`**: This is the most important one for memory. It contains the
functions `malloc`, `calloc`, `realloc`, and `free`. Without this, you cannot
manage heap memory.

---

### 2. Asking for the size
```c
int n;
printf("Enter size: ");
scanf("%d", &n);
```
In C, a standard array like `int arr[10];` must have a size fixed when you write
the code. By using memory management, we can ask the user how much memory they
want **while the program is running**.

---

### 3. The Allocation (The "Rental Request")
```c
int *arr = malloc(n * sizeof(int));
```
This is the most critical line. Let's dissect it:
*   **`int *arr`**: We create a pointer. This pointer will store the starting
address of the memory block the OS gives us.
*   **`malloc(...)`**: This stands for "Memory Allocation." It asks the OS for a
chunk of bytes.
*   **`n * sizeof(int)`**: `malloc` only understands **bytes**. If you want to
store 5 integers, you can't just say `malloc(5)`. You have to say "5 times the
size of one integer." On most systems, an `int` is 4 bytes, so this asks for 20
bytes.

---

### 4. The Safety Check
```c
if (arr == NULL) {
    printf("Memory allocation failed!");
    return 1;
}
```
Sometimes, the computer is out of RAM. If `malloc` fails, it returns `NULL` (it
points to nothing). If you try to use a `NULL` pointer, your program will
**crash** (Segmentation Fault). Always check this!

---

### 5. Using the Memory
```c
for (int i = 0; i < n; i++) {
    arr[i] = i * 2;
    printf("%d ", arr[i]);
}
```
Once memory is allocated, you can treat the pointer `arr` exactly like a normal
array. You can use square brackets `[]` to move through the memory slots.

---

### 6. The Cleanup (Giving the keys back)
```c
free(arr);
```
In C, the computer will **never** automatically take back the memory you
requested with `malloc`. If your program runs for a month and you keep calling
`malloc` without `free`, you will eventually use up all the RAM in the computer.
This is called a **Memory Leak**.

Calling `free(arr)` tells the OS: "I am finished with this block; you can give
it to another program."

---

### 7. The Safety Step (Optional but Recommended)
```c
arr = NULL;
```
After you `free(arr)`, the pointer `arr` still holds the address of the memory.
However, you no longer own that memory. This is called a **Dangling Pointer**.
By setting it to `NULL`, you ensure that if you accidentally try to use it
later, the program will crash immediately (which is easy to debug) rather than
corrupting random data (which is very hard to debug).

---

### Summary Analogy:
1.  **`malloc`**: You go to a hotel and ask for a room of a certain size. The
clerk gives you a **key card** (the pointer).
2.  **`if (arr == NULL)`**: The clerk tells you there are no rooms available.
3.  **Using the array**: You go into the room and put your luggage there.
4.  **`free`**: You check out of the hotel and return the key.
5.  **`arr = NULL`**: You throw away your notes about what the room number was
so you don't accidentally try to walk back into a room that someone else is now
staying in.
*/

// code snippet 1
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

//
//
//
//
//
/* Code snippet from google ai : This  should be used for learning purposes*/

//
//
//
// Code snippet 2 : about Malloc:
// using char

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
