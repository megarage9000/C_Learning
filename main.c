#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// CLearning Pointers and Functions
// Lesson Link: https://www.programiz.com/c-programming/c-pointer-functions

double getNumberInput();

void swapNumbers(int * a, int * b);

int main(){
    int a, b;
    printf("Enter a value for variable a\n");
    a = (int)getNumberInput();
    printf("Enter a value for variable b\n");
    b = (int)getNumberInput();

    printf("Before swap: a = %d, b = %d\n", a, b);
    swapNumbers(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
    return -1;
}

void swapNumbers(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}



double getNumberInput(){
    int success = 0;
    double result;
    char buf[40];
    do{
        printf("Enter a number: ");
        if(fgets(buf, sizeof(buf), stdin)){
            char *endptr;
            int base = 10;
            errno = 0;
            result = strtol(buf, &endptr, base);

            int ifNoRead = (endptr == buf);
            int ifEndlessRead = (*endptr && *endptr != '\n');

            if(errno == ERANGE){
                success = 0;
            }
            else if(ifNoRead || ifEndlessRead){
                success = 0;
            }
            else{
                success = 1;
            }

        } else{
            return -1;
        }
    } while (!success);

    return result;
}
