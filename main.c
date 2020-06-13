#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// CLearning Memory Allocation
// Lesson Link: https://www.programiz.com/c-programming/c-dynamic-memory-allocation

double getNumberInput();
void dynamicMemoryAllocationDemo();
int * makeIntegerArray(int size, int initialElement);
void printIntArray(int array[], int size);
void clearArray(int ** array);
void resizeArray(int ** array, int newSize, int newInitialElem);

int main(){
    dynamicMemoryAllocationDemo();
    return -1;
}

void dynamicMemoryAllocationDemo(){
    // Dynamic Memory Allocations allows us to allocate a certain
    // amount of memory during runtime. This is especially useful 
    // when making arrays during runtime or adjusting it throughout 
    // program run time

    // Allocation Memory:
    // C malloc()
    // - allocates a number of bits in dynamic memory
    // - (castType*)malloc(size in bits);
    //
    // C calloc()
    // - similar to malloc(), but it initializes all bits to 0
    // - (castType*)calloc(number of blocks, size of each block);
    //
    // calloc() vs malloc(): https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-with-examples/

    // Freeing Memory:
    // 
    // C Dynamic Memory must be freed as there is no garbage collection 
    // within C
    // 
    // C free():
    // - frees memory allocated by either malloc() or calloc()
    // - free(pointer);

    // Reallocating Memory:
    // 
    // C Dynamic Memory can also be reallocated during runtime 
    // if there is little or too much space
    //
    // C realloc()
    // - changes the allocated memory at a pointer to a different size
    // - realloc(pointer, new size of memory allocated at pointer);

    // Creating a new integer array from dynamic memory
    printf("Enter a size for a random array\n");
    int sizeOfArray = (int)getNumberInput();
    printf("Enter intial element\n");
    int intialElement = (int)getNumberInput();
    int * intArray = makeIntegerArray(sizeOfArray, intialElement);
    printf("---- Integer array printed ----\n");
    printIntArray(intArray, sizeOfArray);

    // Reallocating the integer array
    printf("Enter a new size for the integer array\n");
    sizeOfArray = (int)getNumberInput();
    printf("Enter a new initial element for the integer array\n");
    intialElement = (int)getNumberInput();
    resizeArray(&intArray, sizeOfArray, intialElement);
    printf("---- Reallocated integer array printed ----\n");
    printIntArray(intArray, sizeOfArray);

    // Clearing the array
    clearArray(&intArray);

}

int * makeIntegerArray(int size, int initialElement){
    int * returnArray = (int *)malloc(size * sizeof(int));
    if(!returnArray){
        return NULL;
    }
    
    for(int i = 0; i < size; i++){
        returnArray[i] = initialElement;
    }
    return returnArray;
}

// doing ** to perform pass by reference on a pointer
void resizeArray(int ** array, int newSize, int newInitialElem){
    *array = realloc(*array, newSize * sizeof(int));
    if(!*array){
        return;
    }
    for(int i = 0; i < newSize; i++){
        *(*array + i) = newInitialElem;
    }
}

void clearArray(int ** array){
    free(*array);
}

void printIntArray(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("Element %d: %d\n", i, array[i]);
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
