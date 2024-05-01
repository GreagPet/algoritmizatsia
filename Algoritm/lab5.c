#include <stdio.h>
#include "labs.h"

#define SIZE 10

int numb[SIZE];
int pos_even[SIZE];
int pos_odd[SIZE];

int even, odd, i1, i2, del, previous;

void lab5(void){
    even = 0;
    odd = 0;
    i1 = 0;
    i2 = 0;
    previous = 0;
    del = 0;

    for (int i = 0; i < 10; i++){
        scanf("%d", &numb[i]);

        if (del == 0 && previous >= numb[i]){
            del = 1;
        }

        previous = numb[i];
    }

    for (int i = 0; i < 10; i++){
        if (numb[i] % 2 == 0){
            even++;
            pos_even[i1] = i;
            i1++;
        }
        else{
            odd++;
            pos_odd[i2] = i;
            i2++;
        }     
    }

    if (del == 1 && odd < even){
        for (int i = 0; i < odd; i++){
            numb[pos_odd[i]] = 0;
        }      
    }
    else if (del == 1 && odd >= even){
        for (int i = 0; i < even; i++){
            numb[pos_even[i]] = 0;
        }
    }

    printf("Even: %d\n", even);
    printf("Odd: %d\n", odd);
    printf("Array: ");

    for (int i = 0; i < 10; i++){
        printf("%d, ", numb[i]);
    }
}

//теория: нарисовать как на фото
//практика: если ряд идет на возрастание, то ничего не обнуляется