#include <stdio.h>

// Input / Output

// Lesson Link: 
// https://www.programiz.com/c-programming/c-input-output

// ScanF tips! (It's not always safe!):
// http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html

void outputDemo();
void inputDemo();

int main(){

    // outputDemo();
    inputDemo();
    return 0;
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