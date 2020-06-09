#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// CLearning Pointers
// Lesson Link: https://www.programiz.com/c-programming/c-pointers

double getNumberInput();
void pointersDemo();
void printPointerAndInt(int * p, int c);


int main(){
    pointersDemo();
    return -1;
}

void pointersDemo(){

    int * p, c; // Declares an integer pointer p, and a normal integer c
    c = 10;
    p = &c;

    printf("Integer variable's address: %p, ", &c);
    printf("Integer vairable's content: %d\n", c);

    printf("Pointer variable's address its pointing to: %p, ", p);
    printf("Pointer variable's content its pointing to: %d\n", *p);

    printf("Change the number of the variable!\n");
    c = (int)getNumberInput();

    printf("Integer variable's address: %p, ", &c);
    printf("Integer vairable's content: %d\n", c);

    printf("Pointer variable's address its pointing to: %p, ", p);
    printf("Pointer variable's content its pointing to: %d\n", *p);
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
