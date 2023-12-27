#include <stdio.h>
#include "fizzbuzz.h"

int AddWord (char res[100], char target[100], int ptr)
{
    int i = 0;
    while (target[i] != '\0') {
        res[ptr] = target[i];
        i += 1;
        ptr += 1;
    }
    return ptr;
}

void CallNumGame(int num, Match *matchs, char res[100])
{
    int ptr = 0;
    for(int i = 0; i < matchs->length; i ++){
        if (num % matchs->items[i].number == 0) {
            ptr = AddWord (res, matchs->items[i].word, ptr);
        }
    }
    res[ptr] = '\0';
    return;
}

