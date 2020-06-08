#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Lesson Links: 
// - goto statements: https://www.programiz.com/c-programming/c-goto-statement



double getNumberInput();
void gotoDemo();

int main(){
    
    gotoDemo(20);

    return -1;
}

void gotoDemo(int numPositive){

    // goto statements:
    // Follows this structure:
    // -----------------------
    // goto [label]
    // .
    // .
    // .
    // [label]:
    //      code here.

    // when to use:
    // - to jump out of nested loops
    // why you shouldn't use it:
    // - can cause buggy code
    // - hard to follow
    // 
    // generally goto statements are rarely used in C programs
    

    printf("Enter %d positive numbers!\n", numPositive);
    for (int i = 0; i < numPositive; i++){
        
        double num = getNumberInput();
        if(num < 0){
            goto negativeNumber;
        }
        else{
            printf("You have entered: %f\n", num);
        }

    }

negativeNumber:
    printf("You have entered a negative number!\n");
    return;
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



