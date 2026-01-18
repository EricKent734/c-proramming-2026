
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

// code snippet 4
//
//
//
//
//
//
//

#include <stdio.h>

// Function takes a pointer to the balance
// Returns 1 if successful, 0 if not enough money
int withdraw(float *balancePtr, float amount) {
  if (*balancePtr >= amount) {
    *balancePtr =
        *balancePtr - amount; // Subtracting from the original variable
    return 1;
  } else {
    return 0; // Transaction failed
  }
}

int main() {
  float mySavings = 1000.00;
  float spend = 200.00;

  printf("Initial Balance: $%.2f\n", mySavings);

  // We pass '&mySavings' so the function can edit the real money
  if (withdraw(&mySavings, spend)) {
    printf("Withdrawal successful!\n");
  } else {
    printf("Declined! Not enough funds.\n");
  }

  printf("Final Balance: $%.2f\n", mySavings);
  return 0;
}
