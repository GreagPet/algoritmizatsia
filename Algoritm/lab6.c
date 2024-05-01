#include <stdio.h>
#include "labs.h"

#define K 5
#define N 4

int x[K][N];
int main_diagonal[2];
int side_diagonal[2];

int sum_main, sum_side, offset, key, k;

void print_arr(void);
void insertion_sort(void);

void lab6(void){
    sum_main = 0;
    sum_side = 0;
    offset = 0;
    key = 0;
    k = 0;

    for (int i = 0; i < K; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &x[i][j]);
        }
        printf("\n");
    }
    print_arr();

    if (K <= N){
        while (K + offset <= N){
            for (int i = 0; i < K; i++){
                sum_main = sum_main + x[i][i + offset];
                sum_side = sum_side + x[i][N - 1 - i - offset];
            }
                
            if(sum_main > main_diagonal[1]){
                main_diagonal[0] = offset;
                main_diagonal[1] = sum_main;
            }
            if(sum_side > side_diagonal[1]){
                side_diagonal[0] = N - 1 - offset;
                side_diagonal[1] = sum_side;
            }
            offset++;
            sum_main = 0;
            sum_side = 0;
        }
        
        if(main_diagonal[1] > side_diagonal[1]){
            for (int i = 0; i < K; i++){
                x[i][i + main_diagonal[0]] = 0;
            }
        }
        else if (main_diagonal[1] < side_diagonal[1]){
            for (int i = 0; i < K; i++){
                x[i][side_diagonal[0] - i] = 0;
            }
        }
        print_arr();
    }
    
    else{
        while (N + offset <= K){
            for (int i = 0; i < N; i++){
                sum_main = sum_main + x[i + offset][i];
                sum_side = sum_side + x[K - 1 - i - offset][i];
            }
                
            if(sum_main > main_diagonal[1]){
                main_diagonal[0] = offset;
                main_diagonal[1] = sum_main;
            }
            if(sum_side > side_diagonal[1]){
                side_diagonal[0] = K - 1 - offset;
                side_diagonal[1] = sum_side;
            }
            offset++;
            sum_main = 0;
            sum_side = 0;
        }
        
        if(main_diagonal[1] > side_diagonal[1]){
            for (int i = 0; i < N; i++){
                x[i + main_diagonal[0]][i] = 0;
            }
        }
        else if (main_diagonal[1] < side_diagonal[1]){
            for (int i = 0; i < N; i++){
                x[side_diagonal[0] - i][i] = 0;
            }
        }
        print_arr();
    }
    printf("\n");
    insertion_sort();
    printf("After sorting:\n");
    print_arr();   
}

void print_arr(void){
    for (int i = 0; i < K; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void insertion_sort(void){
    for (int i = 0; i < K; i++){
        for (int j = 1; j < N; j++){
            key = x[i][j];
            k = j - 1;

            while (k >= 0 && x[i][k] > key){
                x[i][k + 1] = x[i][k];
                k--;
            }
            x[i][k + 1] = key;
        }
    }   
}