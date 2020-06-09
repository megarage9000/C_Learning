#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Lesson Link:
// - C Arrays: https://www.programiz.com/c-programming/c-arrays

double getNumberInput();
void arraysDemo();

int main(){
    arraysDemo();
    return -1;
}

void arraysDemo(){
    printf("How big is your array going to be?\n");
    int size = (int)getNumberInput();

    int intArray[size];
    for(int i = 0; i < size; i++){
        printf("Array index: %d\n", i);
        int num = (int)getNumberInput();
        intArray[i] = num;
    }

    printf("Your array: \n");
    for(int i = 0; i < size; i++){
        printf(" Index %d: %d", i, intArray[i]);
    }
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
