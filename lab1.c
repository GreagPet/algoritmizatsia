#include <stdio.h>
#include "labs.h"

void lab1(void) {
    float v1, v2, L, t; 

    printf("v1 = ");
    scanf("%f", &v1);

    printf("v2 = ");
    scanf("%f", &v2);

    printf("t = ");
    scanf("%f", &t);

    L = v1 * t + v2 * t;
    printf("Distance = %f\n", L);

    getchar();
}