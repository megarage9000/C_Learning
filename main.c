#include <stdio.h>

// Lesson Link: 
// https://www.programiz.com/c-programming/c-data-types

void dataTypesDemo();

int main(){

    dataTypesDemo();
    return -1;
}

void dataTypesDemo(){

    // Integers
    // Format: "%d"
    int integerOne, integerTwo;
    integerOne = 1;
    integerTwo = -1;
    printf("%s%d\n", "integerOne = ", integerOne);
    printf("%s%d\n", "integerTwo = ", integerTwo);

    // Floats and Doubles 
    // Formatters:
    // - float = "%f"
    // - double = "%lf"
    float fraction;
    double price;
    fraction = 1/4;
    price = 22.95;
    printf("%s%f\n", "fraction = ", fraction);
    printf("%s%lf\n", "price = ", price);
    
    // Chars
    // Format: "%c"
    char letterA = 'A';
    printf("%s%c\n", "letterA = ", letterA);
    

    // Shorts and Longs
    // Formatters:
    // - short = "%hd"
    // - long = "%ld"
    // - long long = "%lld"
    // - long double = "%Lf"
    short smallNumber = 22; 
    long bigNumber = 222;
    long long biggerNumber = 2222;
    long double bigDoubleNumber = 22222;
    printf("%s%hd\n", "smallNumber = ", smallNumber);
    printf("%s%ld\n", "bigNumber = ", bigNumber);
    printf("%s%lld\n", "biggerNumber = ", biggerNumber);
    printf("%s%Lf\n", "bigDoubleNumber = ", bigDoubleNumber);
    

    // Unsigned and Signed
    // Format: "%u"
    unsigned int nonNegativeInt = 24;
    printf("%s%u\n", "nonNegativeInt = ", nonNegativeInt);

}

