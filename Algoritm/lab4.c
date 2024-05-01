#include <stdio.h>
#include "labs.h"

#define maximum 1000

char input_string[maximum];
char output_string[maximum];

int glasn_cnt;
int sogl_cnt;
int i;
char c;
int start;
int pos;
int n;

void char_counter(int chr);
void process_string(char string[]);

void lab4(void){
    gets(input_string);
    process_string(input_string);
    puts(output_string);
}

void process_string(char string[]){
    glasn_cnt = 0;
    sogl_cnt = 0;
    i = 0;
    start = 0;
    pos = 0;
    n = 0;

    do{
        c = string[i];
        char_counter(c);

        if (c == ' ' || c == ',' || c == '.' || c == '\n' || c == '\0'){
            if (sogl_cnt >= glasn_cnt || n <= 3){
                for (int j = start; j < i; j++){
                    output_string[pos++] = string[j];
                }
                output_string[pos++] = ' ';
                start = pos;
            }
            sogl_cnt = 0;
            glasn_cnt = 0;
            start = i + 1;
            n = 0;
        }
        i++;
    } while (c != '\0');
}

void char_counter(int chr){
    if (chr == 'a' || chr == 'e' || chr == 'y' || chr == 'u' || chr == 'i' || chr == 'o'){
        glasn_cnt ++;
        n++;
    }
    else if (chr != ' ' && chr != ',' && chr != '.' && chr != '\n' && chr != '\0'){
        sogl_cnt ++;
        n++;
    }
}

