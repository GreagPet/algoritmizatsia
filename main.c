#include <stdio.h>
#include <stdlib.h>
#include "labs.h"

int number_of_lab;

int main(){
    printf("Input number of laboratory work: ");
    scanf("%d\n", &number_of_lab);
    
    if (number_of_lab == 1){
        lab1();
    }
    else if (number_of_lab == 2){
        lab2();
    }
    else if (number_of_lab == 3){
        lab3();
    }
    else if (number_of_lab == 4){
        lab4();
    }
    else if (number_of_lab == 5){
        lab5();
    }
    else if (number_of_lab == 6){
        lab6();
    }
    else if (number_of_lab == 7){
        lab7();
    }
    else{
        printf("This laboratory work is not found");
    }
    
    system("pause");
    return 0;
}

//gcc -o main lab1.c lab2.c lab3.c main.c