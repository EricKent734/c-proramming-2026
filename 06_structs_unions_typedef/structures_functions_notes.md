
---

# 📘 Summary: Structures and Functions in C

## ✅ Legal Operations on Structures
- Copying or assigning as a unit.
- Taking the address (`&`).
- Accessing members (`.`).
- Passing/returning structures to/from functions.
- **Not allowed:** direct comparison of structures.

## ⚙️ Initialization
- Structures can be initialized with constant values.
- Automatic structures can be initialized by assignment.

---

## 🧩 Approaches to Using Structures in Functions
1. Pass components separately.  
2. Pass the entire structure.  
3. Pass a pointer to the structure.  

---

## 🔹 Example Functions

### 1. **makepoint** – Create a point from x and y
```c
/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}
```

**Usage:**
```c
struct rect screen;
struct point middle;
struct point makepoint(int, int);

screen.pt1 = makepoint(0,0);
screen.pt2 = makepoint(XMAX, YMAX);
middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                   (screen.pt1.y + screen.pt2.y)/2);
```

---

### 2. **addpoint** – Add two points
```c
/* addpoints: add two points */
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}
```

---

### 3. **ptinrect** – Test if a point lies inside a rectangle
```c
/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}
```

---

### 4. **canonrect** – Canonicalize rectangle coordinates
```c
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}
```

---

## 📍 Pointers to Structures

### Declaration
```c
struct point *pp;
```

### Example Usage
```c
struct point origin, *pp;
pp = &origin;
printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
```

- `(*pp).x` → correct (parentheses required).  
- `*pp.x` → illegal (wrong precedence).  

---

## ➡️ Arrow Operator (`->`)
Shorthand for accessing members via pointers.

```c
printf("origin is (%d,%d)\n", pp->x, pp->y);
```

### Equivalences
```c
struct rect r, *rp = &r;

r.pt1.x
rp->pt1.x
(r.pt1).x
(rp->pt1).x
```

---

## 🔝 Operator Precedence
- `.` and `->` bind tightly (highest precedence).
- Example:
```c
struct {
    int len;
    char *str;
} *p;

++p->len        // increments len
(++p)->len      // increments p, then accesses len
(p++)->len      // increments p afterward
```

### Pointer to String Member
```c
*p->str         // fetches what str points to
*p->str++       // increments str after access
(*p->str)++     // increments what str points to
*p++->str       // increments p after access
```

---

# 📝 Key Takeaways
- Structures can be passed/returned by value, but pointers are more efficient for large structures.
- `.` is for direct structure members, `->` is for pointer-to-structure members.
- Operator precedence matters: `.` and `->` bind tighter than `*`, `++`, or `[]`.

---


