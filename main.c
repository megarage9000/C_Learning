#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Lesson Links:
// C User-Defined Functions: https://www.programiz.com/c-programming/c-user-defined-functions
// C Function Types: https://www.programiz.com/c-programming/types-user-defined-functions

double getNumberInput();
void swapNumbers(int * a, int * b);
void functionDemo();

int main(){
    functionDemo();
    return -1;
}

void swapNumbers(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void functionDemo(){
    printf("Enter a number: ");
    int a = (int)getNumberInput();
    printf("Enter a number to swap the first one with: ");
    int b = (int)getNumberInput();

    printf("Before swapping: A = %d, B = %d\n", a, b);
    swapNumbers(&a, &b);
    printf("After swapping: A = %d, B = %d\n", a, b);
}


double getNumberInput(){
    int success = 0;
    double result;
    char buf[40];
    do{
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
