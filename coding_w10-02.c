#include <stdio.h>

int main() {
    float scores[3][3];
    const char *subjects[] = {"Math", "Physics", "Chemistry"};
    const char *students[] = {"Student 1", "Student 2", "Student 3"};

    printf("Enter scores for 3 students and 3 subjects (Math, Physics, Chemistry).\n");
    for (int i = 0; i < 3; i++) { 
        printf("--- Enter scores for %s ---\n", students[i]);
        for (int j = 0; j < 3; j++) { 
            printf("Enter %s score: ", subjects[j]);
            scanf("%f", &scores[i][j]);
        }
    }
    printf("\nScore Table:\n");
    printf("--------------------------------------------------\n");
    printf("Student\t\tMath\tPhysics\tChemistry\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        printf("%d\t\t", i + 1); 
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", scores[i][j]); 
        }
        printf("\n");
    }
    printf("--------------------------------------------------\n");
    printf("\nAverage per subject:\n");
    for (int j = 0; j < 3; j++) { 
        float sum = 0.0;
        for (int i = 0; i < 3; i++) { 
            sum += scores[i][j];
        }
        float average = sum / 3.0;
        printf("%s: %.2f\n", subjects[j], average);
    }

    return 0;
}