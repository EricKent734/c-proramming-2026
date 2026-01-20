Here’s a **detailed summary** of Chapter 6 – *Structures* along with the **key code snippets** for clarity:

---


### 1. **Definition of Structures**
- A **structure** is a collection of variables (possibly of different types) grouped under one name.
- Equivalent to **records** in other languages (e.g., Pascal).
- Useful for organizing complex data in large programs by treating related variables as a single unit.

---

### 2. **Examples of Structures**
- **Payroll record**: employee details like name, address, SSN, salary.
- **Graphics**: 
  - A **point** = (x, y).
  - A **rectangle** = two points (diagonal corners).

---

### 3. **ANSI Standard Enhancements**
- Structures can now be:
  - **Assigned** (copied).
  - **Passed to functions**.
  - **Returned by functions**.
- Structures and arrays can be **initialized automatically**.

---

### 4. **Basics of Structures**
- Declared using the `struct` keyword.
- Members are variables inside the structure.
- A **structure tag** (like `point`) names the type for reuse.
- Members can share names across different structures without conflict.

---

### 5. **Declaration and Initialization**
- Declaring a structure type:
  ```c
  struct point {
      int x;
      int y;
  };
  ```
- Declaring variables of that type:
  ```c
  struct point pt;
  ```
- Initializing a structure:
  ```c
  struct point maxpt = { 320, 200 };
  ```

---

### 6. **Accessing Members**
- Use the **dot operator (`.`)**:
  ```c
  printf("%d,%d", pt.x, pt.y);
  ```
- Example: computing distance from origin:
  ```c
  double dist, sqrt(double);
  dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
  ```

---

### 7. **Anonymous Structures**
- Structures can be declared without a tag:
  ```c
  struct { int x; int y; } a, b, c;
  ```
- Similar to declaring multiple integers:
  ```c
  int x, y, z;
  ```

---

### 8. **Nested Structures**
- Structures can contain other structures:
  ```c
  struct rect {
      struct point pt1;
      struct point pt2;
  };
  ```
- Example usage:
  ```c
  struct rect screen;
  screen.pt1.x;   // Access x of pt1 inside screen
  ```

---

## 💻 Key Code Snippets

```c
// Basic structure definition
struct point {
    int x;
    int y;
};

// Declaring a variable of type struct point
struct point pt;

// Initializing a structure
struct point maxpt = { 320, 200 };

// Accessing members
printf("%d,%d", pt.x, pt.y);

// Computing distance from origin
double dist, sqrt(double);
dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);

// Anonymous structure declaration
struct { int x; int y; } a, b, c;

// Nested structure example
struct rect {
    struct point pt1;
    struct point pt2;
};

struct rect screen;
screen.pt1.x;  // Access nested member
```

---

