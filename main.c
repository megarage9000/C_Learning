#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Lesson Links:
// - C Storage Class: https://www.programiz.com/c-programming/c-storage-class

int globalInt = 5;


double getNumberInput();
void storageClassDemo();
int main(){
    storageClassDemo();
    storageClassDemo();
    storageClassDemo();
    return -1;
}

void storageClassDemo(){
    // Each variable in C has a storage class!
    // There are 4 types:
    // - automatic
    //      - Are local variables and only exist in code bracket
    // - external
    //      - Can be used outside of its code bracket, and in the case of extern
    //      keyword, can be used in other files
    // - static
    //      - The value of the variable persists until the end of the program
    // - register
    //      - Utilizes the actual registers for greater speed, although many 
    //      compilers already have optimized quite efficiently
    register int regInt = 20;
    static int staticInt = 2;
    printf("Register integer: %d\n", regInt);
    printf("Static integer: %d\n", staticInt);
    printf("Global integer: %d\n", globalInt);

    staticInt += 20;
    globalInt ++;
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
