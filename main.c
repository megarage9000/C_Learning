#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// CLearning Pointers
// Lesson Link: https://www.programiz.com/c-programming/c-pointers

double getNumberInput();
void arraysAndPointers(int arraySize);


int main(){
    arraysAndPointers(5);
    return -1;
}

void arraysAndPointers(int arraySize){
    int * elementPointer;
    int array[arraySize];

    printf("Make an array of numbers! You have %d numbers to enter\n", arraySize);

    for (int i = 0; i < arraySize; i++){
        array[i] = (int)getNumberInput();
    }

    printf("Addresses per array element!\n");

    for(int i = 0; i < arraySize; i++){
        printf("*(array + %d) = %d\n", i, *(array + i));
    }

    printf("Enter a position of an element to access for pointer demonstration!\n");

    int success = 0;
    int position;
    do{
        position = (int)getNumberInput();
        success = (position >= 0 && position < arraySize);
        if(!success){
            printf("Index out of bounds! Try again\n");
        }
    } while(!success);

    elementPointer = &array[position];

    printf("Element pointer to end of array:\n");
    int positionToEnd = arraySize - position;
    for(int i = 0; i < positionToEnd; i++){
        printf("*(elmentPointer + %d) = %d\n", i, *(elementPointer + i));
    }

    printf("Element pointer to beginning of array:\n");
    for(int i = 0; i < position; i++){
        printf("*(elmentPointer - %d) = %d\n", i, *(elementPointer - i));
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
