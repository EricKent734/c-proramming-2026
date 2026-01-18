In C programming, memory is primarily divided into two areas: the **Stack** and the **Heap**. Understanding the difference is crucial for efficient memory management and avoiding bugs like memory leaks or segmentation faults.

---

### 1. The Stack (Static Memory Allocation)
The stack is a "Last In, First Out" (LIFO) data structure managed automatically by the CPU.

*   **Management:** Automatic. The compiler allocates memory when a function is called and deallocates it when the function returns.
*   **Variables:** Stores local variables and function call information (return addresses, parameters).
*   **Speed:** Very fast access because of the LIFO nature and hardware optimization.
*   **Size:** Fixed and limited (determined by the OS). Exceeding it causes a **Stack Overflow**.
*   **Lifetime:** Variables exist only within the scope of the function they are declared in.

### 2. The Heap (Dynamic Memory Allocation)
The heap is a large pool of memory used for dynamic allocation during runtime.

*   **Management:** Manual. The programmer must explicitly allocate memory (using `malloc`, `calloc`, or `realloc`) and deallocate it (using `free`).
*   **Variables:** Used for data that needs to persist beyond the scope of a single function or for large data structures (like linked lists or trees).
*   **Speed:** Slower than the stack because allocation requires searching for free blocks and managing fragmentation.
*   **Size:** Flexible and much larger (limited by the system's physical RAM). Failing to free memory causes **Memory Leaks**.
*   **Lifetime:** Managed by the programmer; stays allocated until it is manually freed or the program exits.

---

### Comparison Table

| Feature | Stack | Heap |
| :--- | :--- | :--- |
| **Allocation** | Automatic (by compiler) | Manual (by programmer) |
| **Deallocation** | Automatic (end of scope) | Manual (using `free()`) |
| **Access Speed** | Very Fast | Slower |
| **Memory Size** | Limited/Fixed | Large/Flexible |
| **Structure** | LIFO (Linear) | No fixed structure (Fragmented) |
| **Safety** | Safer (No manual freeing) | Risk of memory leaks/dangling pointers |

---

### Code Example

```c
#include <stdio.h>
#include <stdlib.h>

void exampleFunction() {
    // STACK allocation
    int stackVar = 10; 

    // HEAP allocation
    int *heapVar = (int*)malloc(sizeof(int)); 
    *heapVar = 20;

    printf("Stack: %d, Heap: %d\n", stackVar, *heapVar);

    // Manual cleanup for Heap
    free(heapVar); 
} // stackVar is automatically destroyed here
```

### Key Takeaways
*   Use the **Stack** for small, temporary variables where the size is known at compile time.
*   Use the **Heap** for large datasets, arrays whose size is determined at runtime, or data that needs to survive across multiple function calls.
