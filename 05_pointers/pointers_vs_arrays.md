

# 📘 Notes: Pointers and Arrays (Section 5.3)

- **Strong relationship**: In C, arrays and pointers are closely related.  
  - Any operation done with array subscripting (`a[i]`) can also be done with pointers (`*(a+i)`).  
  - Pointer-based operations are often faster but harder to read for beginners.  

- **Array declaration**:  
  - `int a[10];` defines 10 consecutive integers (`a[0]` … `a[9]`).  

- **Pointer to array elements**:  
  - `int *pa;` declares a pointer to `int`.  
  - `pa = &a[0];` makes `pa` point to the first element.  
  - `*pa` accesses the value of `a[0]`.  

- **Pointer arithmetic**:  
  - `pa + 1` → points to the next element (`a[1]`).  
  - `pa + i` → points to `a[i]`.  
  - `*(pa + i)` → value of `a[i]`.  
  - `pa - i` → points backwards in the array.  

- **Equivalence of arrays and pointers**:  
  - `a[i]` ≡ `*(a+i)`  
  - `&a[i]` ≡ `a+i`  
  - `pa[i]` ≡ `*(pa+i)`  
  - Array name (`a`) is the address of the first element.  
  - `pa = a;` is valid, but `a = pa;` is illegal (array names are not variables).  

- **Arrays as function arguments**:  
  - Passing an array to a function passes the address of its first element.  
  - Inside the function, the parameter is treated as a pointer.  
  - Example: `int strlen(char *s)` treats `s` as a pointer to characters.  

- **Function parameter equivalence**:  
  - `char s[];` and `char *s;` are equivalent in function definitions.  

- **Passing subarrays**:  
  - `f(&a[2]);` or `f(a+2);` → passes pointer to subarray starting at `a[2]`.  
  - Inside `f`, parameter can be declared as either `int arr[]` or `int *arr`.  

- **Backward indexing**:  
  - `p[-1]`, `p[-2]` are legal if those elements exist.  
  - Referring outside array bounds is illegal.  

---

# 💻 Code Snippets

```c
// Array declaration
int a[10];   // 10 consecutive integers
```

```c
// Pointer to array elements
int *pa;
pa = &a[0];      // pa points to a[0]
int x = *pa;     // x = a[0]
```

```c
// Pointer arithmetic
*(pa + 1);       // refers to a[1]
pa + i;          // address of a[i]
*(pa + i);       // value of a[i]
```

```c
// Array and pointer equivalence
pa = &a[0];      // pa and a have identical values
pa = a;          // equivalent assignment
*(a + i);        // same as a[i]
&a[i];           // same as a + i
pa[i];           // same as *(pa + i)
```

```c
// strlen implemented with pointers
/* strlen: return length of string s */
int strlen(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
```

```c
// Example calls to strlen
strlen("hello, world");   // string constant
strlen(array);            // char array[100];
strlen(ptr);              // char *ptr;
```

```c
// Passing subarrays
f(&a[2]);   // pass address of subarray starting at a[2]
f(a + 2);   // equivalent
```

```c
// Function parameter equivalence
f(int arr[]) { ... }   // arr treated as pointer
f(int *arr)  { ... }   // equivalent
```

```c
// Backward indexing (legal if within bounds)
p[-1];   // element before p[0]
p[-2];   // two elements before p[0]
```


