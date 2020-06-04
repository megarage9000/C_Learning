#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Input / Output

// Lesson Link: 
// https://www.programiz.com/c-programming/c-input-output

// ScanF tips! (It's not always safe!):
// http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html


void outputDemo();
void inputDemo();
void scanfDemo();


int main(){

    // outputDemo();
    // inputDemo();

    scanfDemo();
    return 0;
}

void scanfDemo(){
    // Rule 1. scanf() is not for reading input, it's for parsing input!
    // - never flush input stream too, it is undefined behaviour

    // Rule 2. scanf() can be dangerous when used carelessly. Always use field
    // widths with conversions that parse properly
    char exampleName[40];
    
    // - We use 39 because C needs a 0 byte to append the end!
    // printf("What is your name? ");
    // scanf("%39s", exampleName);
    // printf("Hello %s!\n", exampleName);

    // Rule 3. Although scanf() format strings can look quite similar to printf() format strings,
    // they often have different semantics!
    // printf("What is your name(We take spaces now)? ");
    // scanf("%39[^\n]s", exampleName);
    // printf("Hello %s!\n", exampleName);

    // - Using fgets()
    // char fgetsInput[40];
    // int size = sizeof(fgetsInput);
    // printf("What is the tallest point on earth? ");
    // if(fgets(fgetsInput, size, stdin)){

    //     // - strscpn allows us to replace a specific index within a string,
    //     // in this case we can overwrite it with 0 to prevent /n
    //     fgetsInput[strcspn(fgetsInput, "\n")] = 0;
    //     printf("You thought it was: %s\n", fgetsInput);
    // }

    // - Using fgets to get integers
    long a;
    char buf[1024];
    int success;

    do 
    {
        printf("Enter a number! ");
        if(!fgets(buf, 1024, stdin)){
            // input reading has failed!
            return;
        }

        char *endptr;
        errno = 0;
        int base = 10;
        a = strtol(buf, &endptr, base);
        if(errno == ERANGE){
            // Number is not within range!
            printf("Number too large! / too small!\n");
            success = 0;
        }
        else if(endptr == buf){
            // Input couldn't be converted since nothing was read!
            success = 0 ;
        }

        else if(*endptr && *endptr != '\n'){
            // the last character wasn't end of a string / newline
            success = 0;
        }
        else{
            // successfully read!
            success = 1;
        }

    } while (!success);
    printf("Your entered number! %ld\n", a);
}

void outputDemo(){

    printf(" ---- Output Demo ---- \n");
    printf("String output example!\n");

    int sampleInteger = 2;
    printf("Sample integer = %d\n", sampleInteger);

    float sampleFloat = 2.2;
    double sampleDouble = 33.45;
    printf("Sample float = %f\n", sampleFloat);
    printf("Sample double = %lf\n", sampleDouble);

    char characterA = 'A';
    printf("Sample character = %c\n", characterA);
}

void inputDemo(){
    printf(" ---- Input Demo ---- \n");

    // Note for scanf, you must enter the correct formatter and 
    // the memory location of the variable to store!

    int integerInput;
    printf("Enter an integer: ");
    scanf("%d", &integerInput);
    printf("Your entered integer = %d\n", integerInput);

    float floatInput;
    double doubleInput;
    printf("Enter a float, and then a double: ");
    scanf("%f%lf", &floatInput, &doubleInput);
    printf("You have entered float = %f, and double = %lf\n", floatInput, doubleInput);

    // Bugged area over here!
    char characterInput;
    printf("Enter a character: ");
    scanf("%c", &characterInput);
    printf("You have entered character = %c\n", characterInput);

}