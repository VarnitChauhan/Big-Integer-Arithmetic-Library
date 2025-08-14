#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bigint.h"

// Function to initialize a BigInt from a string
BigInt* createBigInt(const char* str) {
    BigInt* num = (BigInt*)malloc(sizeof(BigInt));
    if (!num) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    num->sign = (str[0] == '-') ? -1 : 1;
    if (num->sign == -1) str++;

    num->length = strlen(str);
    num->digits = (char*)malloc(num->length + 1);
    strcpy(num->digits, str);
    
    return num;
}

// Function to print BigInt
void printBigInt(BigInt* num) {
    if (num->sign == -1) printf("-");
    printf("%s\n", num->digits);
}

// Function to add two BigInts
// Function to add two BigInts correctly
BigInt* addBigInt(BigInt* a, BigInt* b) {
    int len1 = a->length, len2 = b->length;
    int maxLen = (len1 > len2 ? len1 : len2) + 1;  // +1 for carry
    char *resultDigits = (char*)malloc(maxLen + 1); // +1 for null terminator
    if (!resultDigits) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    int carry = 0, i = len1 - 1, j = len2 - 1, k = maxLen - 1;
    resultDigits[k--] = '\0'; // Null terminator

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? a->digits[i--] - '0' : 0;
        int digit2 = (j >= 0) ? b->digits[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        resultDigits[k--] = (sum % 10) + '0'; // Store last digit
        carry = sum / 10;  // Carry forward
    }

    // If carry is left, shift result to avoid leading zeros
    BigInt* result = createBigInt(resultDigits + k + 1);
    free(resultDigits);  // Free temp array
    return result;
}

// Function to subtract two BigInts
BigInt* subtractBigInt(BigInt* a, BigInt* b) {
    int cmp = compareBigInt(a, b);
    BigInt *larger, *smaller;
    int resultSign = 1;

    if (cmp == 0) return createBigInt("0");
    else if (cmp > 0) {
        larger = a;
        smaller = b;
    } else {
        larger = b;
        smaller = a;
        resultSign = -1;
    }

    int len1 = larger->length, len2 = smaller->length;
    char *resultDigits = (char*)malloc(len1 + 1);
    resultDigits[len1] = '\0';

    int borrow = 0, i = len1 - 1, j = len2 - 1, k = len1 - 1;

    while (k >= 0) {
        int d1 = larger->digits[i--] - '0';
        int d2 = (j >= 0) ? smaller->digits[j--] - '0' : 0;

        d1 -= borrow;
        if (d1 < d2) {
            d1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        resultDigits[k--] = (d1 - d2) + '0';
    }

    // Remove leading zeros
    while (*resultDigits == '0' && *(resultDigits + 1)) resultDigits++;

    BigInt* result = createBigInt(resultDigits);
    result->sign = resultSign;
    return result;
}


// Function to multiply two BigInts
BigInt* multiplyBigInt(BigInt* a, BigInt* b) {
    int len1 = a->length, len2 = b->length;
    int maxLen = len1 + len2;
    int *tempResult = (int*)calloc(maxLen, sizeof(int));

    if (!tempResult) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (a->digits[i] - '0') * (b->digits[j] - '0');
            int pos1 = i + j, pos2 = i + j + 1;
            int sum = mul + tempResult[pos2];

            tempResult[pos2] = sum % 10;                                        
            tempResult[pos1] += sum / 10;
        }
    }

    // Convert int array to string
    char *resultDigits = (char*)malloc(maxLen + 1);
    int index = 0;
    int k = 0;
    while (k < maxLen && tempResult[k] == 0) k++;  // Skip leading zeros

    while (k < maxLen) {
        resultDigits[index++] = tempResult[k++] + '0';
    }
    resultDigits[index] = '\0';

    free(tempResult);
    if (index == 0) return createBigInt("0");  // If result is 0

    return createBigInt(resultDigits);
}

// Function to divide two BigInts (integer division)
BigInt* divideBigInt(BigInt* a, BigInt* b) {
    if (strcmp(b->digits, "0") == 0) {
        printf("Error: Division by zero!\n");
        return NULL;
    }

    if (compareBigInt(a, b) < 0) {
        return createBigInt("0");  // a < b, so result is 0
    }

    BigInt* result = createBigInt("0");
    BigInt* remainder = createBigInt(a->digits);
    BigInt* one = createBigInt("1");

    while (compareBigInt(remainder, b) >= 0) {
        BigInt* newRemainder = subtractBigInt(remainder, b);
        freeBigInt(remainder);
        remainder = newRemainder;

        BigInt* newResult = addBigInt(result, one);
        freeBigInt(result);
        result = newResult;
    }

    freeBigInt(remainder);
    freeBigInt(one);
    return result;
}



// Function to compute modulus (remainder) of BigInt division
// Helper: compare two BigInts (returns -1 if a < b, 0 if a == b, 1 if a > b)
int compareBigInt(BigInt* a, BigInt* b) {
    if (a->length < b->length) return -1;
    if (a->length > b->length) return 1;
    return strcmp(a->digits, b->digits);
}

// Function to compute modulus (remainder) of BigInt division
BigInt* modBigInt(BigInt* a, BigInt* b) {
    if (strcmp(b->digits, "0") == 0) {
        printf("Error: Modulo by zero!\n");
        return NULL;
    }

    BigInt* temp = createBigInt("0");
    BigInt* remainder = createBigInt(a->digits);
    BigInt* one = createBigInt("1");

    while (compareBigInt(remainder, b) >= 0) {
        BigInt* newTemp = subtractBigInt(remainder, b);
        freeBigInt(remainder);
        remainder = newTemp;
    }

    freeBigInt(temp);
    freeBigInt(one);
    return remainder;
}

BigInt* powBigInt(BigInt* base, BigInt* exponent) {
    BigInt* result = createBigInt("1");
    BigInt* counter = createBigInt("0");
    BigInt* one = createBigInt("1");

    while (compareBigInt(counter, exponent) < 0) {
        BigInt* temp = multiplyBigInt(result, base);
        freeBigInt(result);
        result = temp;

        BigInt* newCounter = addBigInt(counter, one);
        freeBigInt(counter);
        counter = newCounter;
    }

    freeBigInt(counter);
    freeBigInt(one);
    return result;
}


// Function to free memory
void freeBigInt(BigInt* num) {
    if (num) {
        free(num->digits);
        free(num);
    }
}
