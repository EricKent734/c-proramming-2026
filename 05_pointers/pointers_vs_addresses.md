

---

# 📘 Notes: Pointers and Addresses (Section 5.1)

- Memory is organized as an array of consecutively numbered cells.  
- Different data types occupy different numbers of bytes:
  - `char` → 1 byte  
  - `short` → 2 bytes  
  - `long` → 4 bytes (commonly)  
- A **pointer** is a variable that stores the address of another variable.  
- The **address-of operator** `&` gives the memory location of a variable.  
  - Example: `p = &c;` assigns the address of `c` to pointer `p`.  
- The **dereference operator** `*` accesses the value stored at the address a pointer holds.  
- Pointers are typed:  
  - `int *ip;` → pointer to `int`  
  - `double *dp;` → pointer to `double`  
  - `char *cp;` → pointer to `char`  
- Special case: `void *` can hold any pointer type but cannot be dereferenced.  
- Operators `*` and `&` bind more tightly than arithmetic operators.  
  - Example: `y = *ip + 1;` adds 1 to the value pointed to by `ip`.  
- Incrementing values via pointers:
  - `*ip += 1;`  
  - `++*ip;`  
  - `(*ip)++;` (parentheses required to avoid incrementing the pointer itself).  
- Pointers can be copied: assigning one pointer to another makes them point to the same location.  

---

# 💻 Code Snippets

```c
// Example: Declaring and using pointers
int x = 1, y = 2, z[10];
int *ip;          /* ip is a pointer to int */

ip = &x;          /* ip now points to x */
y = *ip;          /* y is now 1 */
*ip = 0;          /* x is now 0 */
ip = &z[0];       /* ip now points to z[0] */
```

```c
// Declaration syntax
int *ip;          // *ip is an int
double *dp, atof(char *);  // *dp and atof(s) return double
```

```c
// Using pointers in expressions
*ip = *ip + 10;   // increments value pointed to by ip
y = *ip + 1;      // assigns value pointed to by ip + 1
*ip += 1;         // increments value pointed to by ip
++*ip;            // increments value pointed to by ip
(*ip)++;          // increments value pointed to by ip (parentheses required)
```

```c
// Copying pointers
int *iq;
iq = ip;          // iq now points to whatever ip points to
```

---


