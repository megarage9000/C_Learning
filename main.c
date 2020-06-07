#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Operators

// Lesson Link: 
// https://www.programiz.com/c-programming/c-operators
// - Bitwise Operators: https://www.programiz.com/c-programming/bitwise-operators



void bitwiseOperatorsDemo();

int main(){
    bitwiseOperatorsDemo();
    return 0;
}

void bitwiseOperatorsDemo(){

    int a = 12;
    int b = 25;

    // --------------
    // bitwise AND = &
    // - returns 1 if bits are both 1, 0 otherwise

    // 12 = 00001100
    // 25 = 00011001
    //ans = 00001000 = 8
    printf("Bitwise & on 12 and 25 = %d\n", a&b);

    // --------------
    // bitwise OR = |
    // - returns 1 if either bits are 1, 0 otherwise

    // 12 = 00001100
    // 25 = 00011001
    //ans = 00011101 = 29
    printf("Bitwise | on 12 and 25 = %d\n", a|b);

    // --------------
    // bitwise XOR(exclusive OR) = ^
    // - returns 1 if corresponding bits are opposite, 0 otherwise

    // 12 = 00001100
    // 25 = 00011001
    //ans = 00010101 = 21
    printf("Bitwise ^ on 12 and 25 = %d\n", a^b);

    // ------------
    // bitwise Complement = ~
    // performs complement on numbers by taking its complement,
    // flipping its bits, adding 1 and negating it
    // ex. ~45 = -46
    // generally: n's bitwise complement = -(n + 1)
    int c = 45;
    printf("Bitwise ~ on 45 = %d\n", ~c);

    // ------------
    // bitwise shift operators:
    // b >> n: shifts b bits to the right by n bits
    // b << n: shifts b bits to the left by n bits
    // ex. 12 >> 2 = 00001100 -> 00000011 = 3
    // ex. 25 << 4 = 00011001 -> 110010000 = 400
    printf("Bitwise 12 >> 2 = %d\n", 12 >> 2);
    printf("Bitwise 25 << 4 = %d\n", 25 << 4);
}



