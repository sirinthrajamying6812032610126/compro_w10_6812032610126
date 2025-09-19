#include <stdio.h>
#include <string.h> 

int main() {
    char customer1[100];
    char customer2[100];

    printf("Enter name of customer 1: ");
    fgets(customer1, sizeof(customer1), stdin);

    printf("Enter name of customer 2: ");
    fgets(customer2, sizeof(customer2), stdin);

    customer1[strcspn(customer1, "\n")] = 0;
    customer2[strcspn(customer2, "\n")] = 0;

    if (strcmp(customer1, customer2) == 0) {
        printf("Both of your names are the same, which is %s.\n", customer1);
        printf("The length of the name is %d characters.\n", (int)strlen(customer1));
    } else {
        printf("Customer 1: %s (%d characters)\n", customer1, (int)strlen(customer1));
        printf("Customer 2: %s (%d characters)\n", customer2, (int)strlen(customer2));
    }

    return 0; 
}