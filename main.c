#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// CLearning Strings and String functions
// - Lesson Links: 
//      - https://www.programiz.com/c-programming/c-strings
//      - https://www.programiz.com/c-programming/string-handling-functions

double getNumberInput();
char * getStringInput(int charLimit, char message[]);
void freeString(char ** string);
void stringDemo();

const char answer[] = "John Ordoyo";

int main(){
    stringDemo();
    return -1;
}

char * getStringInput(int charLimit, char message[]){
    int success = 0;
    char buf[charLimit];
    char * result = NULL;
    
    printf("%s", message);
    if(fgets(buf, charLimit, stdin)){
        buf[strcspn(buf, "\n")] = 0;
    }
    
    result = (char *)malloc(charLimit * sizeof(char));
    strcpy(result, buf);
    return result;
}

void freeString(char ** string){
    free(*string);
}

void stringDemo(){
    int success = 0;
    do{
        char * guess = getStringInput(100, "Guess my name: ");
        int result = strcmp(answer, guess);
        success = (result == 0);
        if(!success){
            printf("Wrong guess try again!\n");
        }
        freeString(&guess);

    } while (!success);
    printf("You guess my name! it was %s!\n", answer);
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
