#include <stdio.h>
#include "bigint.h"

int main() {
    char input1[1024], input2[1024];  // Support up to 1023-digit numbers

printf("Enter first big integer: ");
scanf("%1023s", input1);

printf("Enter second big integer: ");
scanf("%1023s", input2);

BigInt* num1 = createBigInt(input1);
BigInt* num2 = createBigInt(input2);


    printf("Number 1: ");
    printBigInt(num1);
    printf("Number 2: ");
    printBigInt(num2);

    // Addition
    BigInt* sum = addBigInt(num1, num2);
    printf("Sum: ");
    printBigInt(sum);

    // Subtraction
    BigInt* diff = subtractBigInt(num2, num1);
    printf("Difference: ");
    printBigInt(diff);

    // Multiplication
    BigInt* product = multiplyBigInt(num1, num2);
    printf("Product: ");
    printBigInt(product);

    // Division
    BigInt* quotient = divideBigInt(num2, num1);
    printf("Quotient: ");
    printBigInt(quotient);

    

    BigInt* remainder = modBigInt(num2, num1);
    printf("Remainder: ");
    printBigInt(remainder);

    BigInt* power = powBigInt(num1, createBigInt("3"));
    printf("Power (num1^3): ");
    printBigInt(power);

int cmp = compareBigInt(num1, num2);
if (cmp == 0) {
    printf("num1 and num2 are equal\n");
} else if (cmp < 0) {
    printf("num1 is less than num2\n");
} else {
    printf("num1 is greater than num2\n");
}



    // Free memory
    freeBigInt(num1);
    freeBigInt(num2);
    freeBigInt(sum);
    freeBigInt(diff);
    freeBigInt(product);
    freeBigInt(quotient);

    return 0;
}
