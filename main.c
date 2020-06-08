#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Lesson Links: 
// - Do/while loops: https://www.programiz.com/c-programming/c-do-while-loops
// - If/Else statements: https://www.programiz.com/c-programming/c-if-else-statement
void ifDemo();

int main(){
    ifDemo();
    return -1;
}

void ifDemo(){

    // For boolean expressions:
    // 1 == true, 0 == false
    
    int success = 0;
    int result;
    char buf[40];
    do {
        printf("What is 54 x 5 equal to? ");
        if(fgets(buf, 40, stdin)){

            char *endptr;
            int base = 10;
            errno = 0;
            result = strtol(buf, &endptr, base);

            int ifUnsuccessfulRead = (endptr == buf);
            int ifNoEnd = (*endptr && *endptr != '\n');
            if(errno == ERANGE){
                success = 0;
            }
            else if(ifUnsuccessfulRead == 1 || ifNoEnd == 1){
                success = 0;
            }
            else{
                success = 1;
            }
        }
        else{
            return;
        }
    } while (!success);

    if(result == 270){
        printf("success!\n");
    }
    else{
        printf("wrong answer!\n");
    }
}


