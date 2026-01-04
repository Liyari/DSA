#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "arrayQueue.c"

int main() {
    Queue* regular = initialize();
    Queue* priority = initialize();
    int choice, value;

    do {
        printf("\n--- Pharmacy Queueing System ---\n");
        printf("1. Enter Regular Queue\n");
        printf("2. Enter Priority Queue\n");
        printf("3. Call Next Customer\n");
        printf("4. Display Queues\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer number for Regular Queue: ");
                scanf("%d", &value);
                enqueue(regular, value);
                break;
            case 2:
                printf("Enter customer number for Priority Queue: ");
                scanf("%d", &value);
                enqueue(priority, value);
                break;
            case 3:
                if (!isEmpty(priority)) {
                    printf("Calling Priority Customer: %d\n", dequeue(priority));
                } else if (!isEmpty(regular)) {
                    printf("Calling Regular Customer: %d\n", dequeue(regular));
                } else {
                    printf("No customers in queues.\n");
                }
                break;
            case 4:
                printf("\n-- Current Queue Status --\n");
                printf("Priority Queue: ");
                display(priority);
                printf("Regular Queue: ");
                display(regular);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    free(regular);
    free(priority);

    return 0;
}
