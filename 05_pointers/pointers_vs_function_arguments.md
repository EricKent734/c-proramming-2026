

# 📘 Notes: Pointers and Function Arguments (Section 5.2)

- In C, **function arguments are passed by value**.  
  - This means the called function receives copies of the arguments, not the originals.  
  - Therefore, a function cannot directly modify variables in the caller.  

- Example: A simple `swap(a, b)` function fails if written with value parameters:  
  - It only swaps local copies of `a` and `b`.  
  - The caller’s variables remain unchanged.  

- To modify caller variables, **pointers must be passed**:  
  - Call with `swap(&a, &b);`  
  - Inside the function, parameters are declared as pointers (`int *px, int *py`).  
  - The dereference operator `*` is used to access and modify the actual values.  

- **Pointer arguments** allow functions to:  
  - Access variables in the calling function.  
  - Modify them directly.  

- Example: `getint` function (similar to `scanf`) uses pointers:  
  - Returns a status code (EOF, 0, or positive).  
  - Stores the converted integer into the caller’s variable via a pointer.  
  - This allows two pieces of information to be communicated back:  
    - The integer value.  
    - The status (end of file, invalid input, or success).  

- Usage pattern:  
  - `for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) ;`  
  - Essential to pass the **address** of `array[n]` so `getint` can store the integer.  

- Return values of `getint`:  
  - `EOF` → end of file.  
  - `0` → next input is not a number.  
  - Positive integer → valid number found.  

---

# 💻 Code Snippets

```c
// WRONG: swap using call by value
void swap(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}
```

```c
// Correct: swap using pointers
void swap(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}
```

```c
// Example usage of getint with pointer arguments
int n, array[SIZE], getint(int *);

for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;   // fills array with integers from input
```

```c
// Implementation of getint
#include <ctype.h>
int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))   // skip whitespace
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);   // not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}
```

---

