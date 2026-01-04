#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "arrayStack.h"

int main() {
    Stack s[3];
    for(int i = 0; i < 3; i++){
        initializeStack(&s[i]);
    }
    
    int choice = 0, value, currentStack = 0;

    while(choice != 5){
        printf("--- Warehouse Inventory Management System ---\n1. Push a container\n2. Pop a container\n3. Check if a container exists\n4. Display all stacks\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
    switch (choice) {
            case 1:
                printf("Enter container ID to push: ");
                scanf("%d", &value);
                while (currentStack < 3 && isFull(&s[currentStack])) {
                    currentStack++;
                }
                if (currentStack < 3) {
                    push(&s[currentStack], value);
                    printf("Container %d pushed successfully.\n", value);
                } else {
                    printf("All stacks are full! Cannot push.\n");
                }
                break;

            case 2:
                currentStack = 0;
                while (currentStack < 3 && isEmpty(&s[currentStack])) {
                    currentStack++;
                }
                if (currentStack < 3) {
                    printf("Container %d popped successfully.\n", pop(&s[currentStack]));
                } else {
                    printf("Error: All stacks are empty. Cannot pop container.\n");
                }
                break;

            case 3: {
                printf("Enter container ID to check: ");
                scanf("%d", &value);
                int found = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j <= s[i].top; j++) {
                        if (s[i].items[j] == value) {
                            printf("Container %d exists in a stack.\n", value);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Container %d does not exist in any stack.\n", value);
                }
                break;
            }

            case 4:
                for (int i = 0; i < 3; i++) {
                    printf("\n--- Stack %d ---\n", i + 1);
                    if (isEmpty(&s[i])) {
                        printf("Stack is empty.");
                        printf("\n");

                    } else {
                        for (int j = s[i].top; j >= 0; j--) {
                            printf("%d\n", s[i].items[j]);
                        }
                    }
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    printf("\n");

    }
return 0;
}