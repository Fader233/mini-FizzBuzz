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

int NumHasTarget(int num, int target)
{
    int temp = 0;
    int tmp = num;
    while (tmp >= 1) {
        temp = tmp % 10;
        if (temp == target) {
            return 1;
        }
        tmp = tmp / 10;
    }
    return 0;
}

Match *CurMultiplyRules()
{
    static Match allMatchs = {
        3,
        {
            {"Fizz\0", 3},
            {"Buzz\0", 5},
            {"Whizz\0", 7},
        }};
    return &allMatchs;
}

Match *CurOverlapRules()
{
    static Match allMatchs = {
        3,
        {
            {"Whizz\0", 7},
            {"Buzz\0", 5},
            {"Fizz\0", 3},
        }};
    return &allMatchs;
}

void CallNumGame(int num, char res[100])
{
    Match *matchs = CurOverlapRules();
    int ptr = 0;
    int i = 0;
    
    for(i = matchs->length - 1; i > -1; i --) {
        if (NumHasTarget(num, matchs->items[i].number)){
            ptr = AddWord (res, matchs->items[i].word, ptr);
            res[ptr] = '\0';
            return;
        }
    }

    matchs = CurMultiplyRules();
    for(i = 0; i < matchs->length; i ++){
        if (num % matchs->items[i].number == 0) {
            ptr = AddWord (res, matchs->items[i].word, ptr);
        }
    }
    res[ptr] = '\0';
    return;
}

