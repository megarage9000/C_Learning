#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Lesson Links:
// - C Recursion: https://www.programiz.com/c-programming/c-recursion

double getNumberInput();
void recursionDemo();
int fibSum(int num);

int main(){
    recursionDemo();
    return -1;
}

void recursionDemo(){
    printf("Enter a number for its fibonacci sum: ");
    int num = (int)getNumberInput();

    int fibonacci = fibSum(num);
    printf("The fibonacci sum of %d is: %d\n", num, fibonacci);
}

int fibSum(int num){
    if(num != 0){
        return num + fibSum(num - 1);
    }
    else{
        return num;
    }
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
