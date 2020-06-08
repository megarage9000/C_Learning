#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Lesson Links: 
// - Switch/Break: https://www.programiz.com/c-programming/c-switch-case-statement



double getNumberInput();
void switchDemo(int numberToGuess, int numberOfAttempts);
int main(){
    switchDemo(rand(), 20);
    return -1;
}

void switchDemo(int numberToGuess, int numberOfAttempts){

    printf("---- Guess the number game! ----\n");

    int isRightGuess = 0;
    int iteration = 0;
    do {
        printf("Iteration %d ", iteration);
        double guessedNumber = getNumberInput();
        isRightGuess = (guessedNumber == numberToGuess);
        switch (isRightGuess)
        {
        case 0:
            if(guessedNumber > numberToGuess){
                printf("Number is too large!\n");
            }
            else{
                printf("Number is too small!\n");
            }
            break;
        
        default:
            printf("You guessed correctly!\n");
            break;
        }

        iteration++;

    } while(!isRightGuess && (iteration < numberOfAttempts));

    printf("Out of attempts! The number was: %d\n", numberToGuess);
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



