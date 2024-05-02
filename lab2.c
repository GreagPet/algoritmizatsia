#include <stdio.h>
#include "labs.h"

float a, c, b, s, eps; //очередной элемент ряда, числитель, знаменатель, сумма ряда
int i, sign, n; //номер очередного элемента ряда, знак очередного элемента ряда

int recurs(){
    if (a < eps || i == n){
        printf("i = %d, s = %f", i, s);
        return 1;
    }

    s = s + a*sign;
    c = c + 1;
    b = 2*b;
    a = c/b;
    sign = -sign;
    i = i + 1; 

    return recurs();
}

void lab2(void){
    c = 1;
    b = 1;
    s = 1;
    i = 0;
    sign = 1;
    a = c/b;

    printf("eps = ");
    scanf("%f", &eps);

    printf("n = ");
    scanf("%d", &n);

    recurs();

    getchar();
}