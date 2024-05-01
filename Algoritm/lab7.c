#include <stdio.h>
#include "labs.h"

unsigned long n;
unsigned int k;

unsigned long cyclic_right_shift(unsigned long n, unsigned int k);

void lab7(void){

    printf("N = ");
    scanf("%lx", &n);
    printf("K = ");
    scanf("%u", &k);

    n = cyclic_right_shift(n, k);
    printf("Result: %lx\n", n);
}

unsigned long cyclic_right_shift(unsigned long n, unsigned int k) {
    int bits_in_ulong = sizeof(unsigned long) * 8;

    k %= bits_in_ulong;

    return (n >> k) | (n << (bits_in_ulong - k));
}