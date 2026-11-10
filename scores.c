#include <stdio.h>
#include <stdlib.h>

#define maxCourse 50

// Requirement 4: Count characters with a pointer until '\0' (no strlen)
int myLength(const char *s) {
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

// Requirement 5: Average using pointer arithmetic only (no [])
double average(const int *scores, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(scores + i);
    }
    return sum / (double)n;
}

// Requirement 6: Send lowest and highest back through the two pointers
void findMinMax(const int *scores, int n, int *min, int *max) {
    *min = scores[0];
    *max = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] < *min) {
            *min = scores[i];
        }
        if (scores[i] > *max) {
            *max = scores[i];
        }
    }
}

// Requirement 7: Add bonus to the original array, capped at 100
void addBonus(int *scores, int n, int bonus) {
    for (int i = 0; i < n; i++) {
        scores[i] += bonus;
        if (scores[i] > 100) {
            scores[i] = 100;
        }
    }
}

int main(void) {
    // Requirement 1: Read the course name (one word) into a char array
    char courseName[maxCourse];
    printf("Course name: ");
    scanf("%s", courseName);

    // Requirement 2: Ask for number of students until it is above 0
    int numStudents;
    do {
        printf("How many students? ");
        scanf("%d", &numStudents);
    } while (numStudents <= 0);

    // Requirement 3: Dynamic array with malloc, checked for NULL
    int *scores = (int *)malloc(numStudents * sizeof(int));
    if (scores == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Requirement 3 (continued): Read each score, 0 to 100
    for (int i = 0; i < numStudents; i++) {
        do {
            printf("Score for student %d: ", i + 1);
            scanf("%d", &scores[i]);
        } while (scores[i] < 0 || scores[i] > 100);
    }

    // Requirement 8: Report
    int min, max;
    findMinMax(scores, numStudents, &min, &max);

    printf("\nCourse: %s (%d characters)\n", courseName, myLength(courseName));
    printf("Average: %.2f\n", average(scores, numStudents));
    printf("Lowest: %d, Highest: %d\n", min, max);

    addBonus(scores, numStudents, 5);
    printf("Scores after 5-point bonus: ");
    for (int i = 0; i < numStudents; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    // Requirement 9: Free the array and set the pointer to NULL
    free(scores);
    scores = NULL;

    return 0;
}
