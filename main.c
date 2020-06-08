#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Lesson Links: 
// - For Loops: https://www.programiz.com/c-programming/c-for-loop

void breakAndContinueDemo();
double getNumberInput();

int main(){
    breakAndContinueDemo();
    return -1;
}

void breakAndContinueDemo(){
    double number = getNumberInput();

    for (int i = 0; i < number; i++){

        if((number / 2) < i){
            printf("We've past the halfway point!\n");
            break;
        }
        else{
            printf("We aren't at the halfway point! We are at i = %d\n", i);
            continue;
        }

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



