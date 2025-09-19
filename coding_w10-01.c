#include <stdio.h> 

int main() {  
    int num_students; 
    int total_score = 0; 
    float average_score; 

    printf("Enter number of students: "); 
    scanf("%d", &num_students); 
    int scores[num_students];

    for (int i = 0; i < num_students; i++) {
        printf("Enter score %d: ", i + 1); 
        scanf("%d", &scores[i]); 
        total_score += scores[i]; 
    }
    average_score = (float)total_score / num_students;
    printf("\nNumber of students = %d\n", num_students);
    printf("Average score = %.2f\n", average_score);
    
    return 0;
}