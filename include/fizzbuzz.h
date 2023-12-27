#ifndef __FIZZBUZZ_H__
#define __FIZZBUZZ_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _Matching_Item {
    char word[30];
    int number;
}Matching_Item;

typedef struct Matching_Items
{
    int length;
    Matching_Item items[100];
}Match;

void CallNumGame(int num, char res[100]);

#ifdef __cplusplus
}
#endif

#endif /* __FIZZBUZZ_H__ */
