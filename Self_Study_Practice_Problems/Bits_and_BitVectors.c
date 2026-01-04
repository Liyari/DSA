/*Write the code of the function findFourth that will return 1 if the 4th bit from the right is 1, otherwise return 0;*/
//return 1 if the 4th bit from the right is 1, otherwise return 0
#include <stdio.h>

int findFourth(char elem){
    return (elem >>3) &1;
}

int main() {
    char elem;
    
    printf("Answer: %d\n", findFourth(8));
    printf("Answer: %d\n", findFourth(4));
    printf("Answer: %d\n", findFourth(24));

}

/*Write the code of the function displayBit that will display the bit pattern of the given value*/
#include <stdio.h>

int findFourth(char elem) {
    return (elem >> 3) & 1;   
}

void displayBit(char elem) {
    printf("\nBit Pattern of %d:\n", elem);
    for (int i = 7; i >= 0; i--) {
        printf("%d ", ( (elem >> i) & 1) );
    }
    printf("\n");
}

int main() {
    char elem;
    
    printf("Answer: %d\n", findFourth(8));
    printf("Answer: %d\n", findFourth(4));
    printf("Answer: %d\n", findFourth(24));
    
    displayBit(8);
    displayBit(4);
    displayBit(24);

    return 0;
}