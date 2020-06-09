#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Lesson Link:
// - C Multi-Dimensional Arrays: https://www.programiz.com/c-programming/c-multi-dimensional-arrays

double getNumberInput();
void arraysDemo();
void multiDArrayDemo();
void printSingleArray(int array[], int sizeOfArray);

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
    printSingleArray(intArray, size);
}

void multiDArrayDemo(){
    printf("How many arrays do you want?\n");
    int numArrays = (int)getNumberInput();
    printf("How big is each array?\n");
    int arraySize = (int)getNumberInput();

    int doubleArray[numArrays][arraySize];

    for(int i = 0; i < numArrays; i++){
        for(int j = 0; j < arraySize; j++){
            doubleArray[i][j] = rand();
        }
    }

    printf("Your randomly generated 2D array: \n");
    for (int i = 0; i < numArrays; i++){
        printf("Array #%d: \n", i);
        for(int j = 0; j < arraySize; j++){
            printf("Index #%d: %d ", j, doubleArray[i][j]);
        }
        printf("\n");
    }
}

void printSingleArray(int array[], int sizeOfArray){

    printf("Your array: \n");
    for(int i = 0; i < sizeOfArray; i++){
        printf("Index %d: %d ", i, array[i]);
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
