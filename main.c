#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "WannaBePokemon.h"

double getNumberInput();




int main(){
    printf("%s\n", "How are you?");
    return -1;
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
