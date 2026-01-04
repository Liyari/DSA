#include <stdio.h>
#include <stdbool.h>
#include "compword.h"

void setAnswer(CompWord* profile, int index, int value) {
    if (value)
        *profile |= (1 << index);
    else
        *profile &= ~(1 << index);
}

int getAnswer(CompWord profile, int index) {
    return (profile >> index) & 1;
}

int countYesAnswers(CompWord profile) {
    int count = 0;
    for (int i = 0; i < 10; i++)
        if ((profile >> i) & 1)
            count++;
    return count;
}

void printAnswers(CompWord profile) {
    for (int i = 9; i >= 0; i--)
        printf("%d", getAnswer(profile, i));
    printf("\n");
}

int compareProfiles(CompWord a, CompWord b) {
    CompWord same = ~(a ^ b);  
    int count = 0;
    for (int i = 0; i < 10; i++)
        if ((same >> i) & 1)
            count++;
    return count;
}


CompWord unionProfiles(CompWord a, CompWord b) {
    return a | b;
}

CompWord intersectProfiles(CompWord a, CompWord b) {
    return a & b;
}

CompWord differenceProfiles(CompWord a, CompWord b) {
    return a & (~b);
}