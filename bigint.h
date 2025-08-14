#ifndef BIGINT_H
#define BIGINT_H

typedef struct {
    char *digits; // Stores number as string
    int sign;     // +1 for positive, -1 for negative
    int length;   // Length of the number
} BigInt;

// Function declarations
BigInt* createBigInt(const char* str);
void printBigInt(BigInt* num);

BigInt* addBigInt(BigInt* a, BigInt* b);
BigInt* subtractBigInt(BigInt* a, BigInt* b); // New: Subtraction
BigInt* multiplyBigInt(BigInt* a, BigInt* b); // New: Multiplication
BigInt* divideBigInt(BigInt* a, BigInt* b);   // New: Division

BigInt* modBigInt(BigInt* a, BigInt* b);
BigInt* powBigInt(BigInt* base, BigInt* exponent);

int compareBigInt(BigInt* a, BigInt* b);  // declare helper


void freeBigInt(BigInt* num);

#endif
