
/* Code snippet 1 */

#include <stdio.h>

// Function takes a POINTER to an integer
void add_extra_credit(int *gradePtr) {
  *gradePtr = *gradePtr + 5; // Go to the address and change the value
}

int main() {
  int myGrade = 85;

  printf("Before: %d\n", myGrade);

  // We pass the ADDRESS of myGrade using '&'
  add_extra_credit(&myGrade);

  printf("After: %d\n", myGrade); // It actually changed to 90!
  return 0;
}

// This snippets are for learning purposes;
//
//
//
//

/* code snippet 2 */

#include <stdio.h>

void get_stats(int scores[], int size, int *min, int *max) {
  *min = scores[0];
  *max = scores[0];

  for (int i = 1; i < size; i++) {
    if (scores[i] < *min)
      *min = scores[i];
    if (scores[i] > *max)
      *max = scores[i];
  }
}

int main() {
  int examScores[] = {70, 95, 82, 40, 88};
  int lowest, highest; // Variables to hold our "results"

  // We pass the addresses so the function can "fill them in"
  get_stats(examScores, 5, &lowest, &highest);

  printf("Class Low: %d, Class High: %d\n", lowest, highest);
  return 0;
}

// this snippet is for learning purposes;
//
//
//
//
/* code snippet 3 */

#include <stdio.h>

typedef struct {
  char name[50];
  float gpa;
} Student;

// Instead of passing the whole struct, we pass the pointer
// Use the '->' (arrow) operator to access members via a pointer
void update_gpa(Student *sPtr, float newGpa) { sPtr->gpa = newGpa; }

int main() {
  Student s1 = {"Alice Smith", 3.5};

  printf("%s GPA: %.1f\n", s1.name, s1.gpa);

  update_gpa(&s1, 3.9);

  printf("%s Updated GPA: %.1f\n", s1.name, s1.gpa);
  return 0;
}
