#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Lesson Links: 
// - For Loops: https://www.programiz.com/c-programming/c-for-loop

void forLoopDemo();

int main(){
    forLoopDemo();
    return -1;
}

void forLoopDemo(){

    int success = 0;
    double result;
    char buf[40];
    do{
        printf("Enter a number to multiply itself: ");
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
            return;
        }
    } while (!success);

    for (int i = 0; i < 3; i++){
        result *= result;
    }

    printf("Your number multiplied by itself 3 times: %lf\n", result);

}




