#include <stdio.h>
#include <stdbool.h>
#include "bitvector.h"

void setAnswer(BitVect* profile, int index, int value) {
    profile->answers[index] = value ? 1 : 0;
}

int getAnswer(BitVect profile, int index) {
    return profile.answers[index];
}

int countYesAnswers(BitVect profile) {
    int count = 0;
    for (int i = 0; i < 10; i++)
        if (profile.answers[i] == 1)
            count++;
    return count;
}

void printAnswers(BitVect profile) {
    for (int i = 9; i >= 0; i--)
        printf("%d", profile.answers[i]);
    printf("\n");
}

int compareProfiles(BitVect a, BitVect b) {
    int count = 0;
    for (int i = 0; i < 10; i++)
        if (a.answers[i] == b.answers[i])
            count++;
    return count;
}

BitVect unionProfiles(BitVect a, BitVect b) {
    BitVect result = {0};
    for (int i = 0; i < 10; i++)
        result.answers[i] = (a.answers[i] || b.answers[i]) ? 1 : 0;
    return result;
}

BitVect intersectProfiles(BitVect a, BitVect b) {
    BitVect result = {0};
    for (int i = 0; i < 10; i++)
        result.answers[i] = (a.answers[i] && b.answers[i]) ? 1 : 0;
    return result;
}

BitVect differenceProfiles(BitVect a, BitVect b) {
    BitVect result = {0};
    for (int i = 0; i < 10; i++)
        result.answers[i] = (a.answers[i] && !b.answers[i]) ? 1 : 0;
    return result;
}