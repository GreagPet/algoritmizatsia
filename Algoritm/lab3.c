#include <stdio.h>
#include "labs.h"

int c;
int flag_glasn;
int counter = 0;
int glasn_counter;

int glasn(int chr);

void lab3(void){
    while ((c = getchar()) != EOF){
        glasn(c);
        if (c == ' ' || c == ',' || c == '.'){
            if (flag_glasn == 0){
                counter ++;
            }
            flag_glasn = 0;
        }
    }
    printf("Number of words: %d\n", counter);
    printf("Number of glasn: %d", glasn_counter);
}

int glasn(int chr){
    if (chr == 'a' || chr == 'e' || chr == 'y' || chr == 'u' || chr == 'i' || chr == 'o'){
        flag_glasn = 1;
        glasn_counter ++;
    }
    return 0;
}