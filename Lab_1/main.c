#include "main.h"
#include <stdio.h>

#define MAXSIZE 500

struct Student getMaxAverageStudent(struct Student *s, int n) {
  int maxidx = 0;

  float max = 1;

  for (int i = 0; i < n; i++) {
    if (s[i].average > max) {
      max = s[i].average;
      maxidx = i;
    }
  }

  return s[maxidx];
}

void readData(struct Student *students, int *c) {
  scanf("%d", c);

  for (int i = 0; i < *c; i++) {
    scanf("%d", &students[i].student_id);
    scanf("%d %d %d", &students[i].g1, &students[i].g2, &students[i].g3);

    students[i].average =
        (students[i].g1 + students[i].g2 + students[i].g3) / 3.0;

    printf("%d %d %d %d %0.2f\n", students[i].student_id, students[i].g1,
           students[i].g2, students[i].g3, students[i].average);
  }
}

int main() {

  struct Student students[MAXSIZE];
  int n, i;

  readData(students, &n);

  struct Student maxStudent = getMaxAverageStudent(students, n);

  printf("\nMaximum Average is %0.2f and the student is %d\n",
         maxStudent.average, maxStudent.student_id);

  return 0;
}