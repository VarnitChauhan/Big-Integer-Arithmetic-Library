# 🧮 Big Integer Arithmetic Library in C

## 📌 Overview
This project implements a **Big Integer Arithmetic Library** in C that supports operations on arbitrarily large integers, far exceeding the limits of built-in integer types (`int`, `long long`, etc.).

The library stores big integers as strings and performs arithmetic manually, digit-by-digit.  
It is useful for **cryptography**, **scientific calculations**, and **academic purposes** where very large numbers are required.

---

## 🚀 Features
- **Addition** ➕  
- **Subtraction** ➖  
- **Multiplication** ✖  
- **Integer Division** ➗  
- **Modulo (Remainder)** `%`  
- **Exponentiation** `pow(base, exponent)`  
- **Comparison** (`<`, `==`, `>`)  
- Handles **positive and negative numbers**  
- No reliance on built-in big integer libraries  

---

## 📂 Project Structure
bigint-arithmetic/
│
├── bigint.c # Implementation of BigInt functions
├── bigint.h # Header file with BigInt struct & function declarations
├── main.c # Test program demonstrating the library
├── Makefile # For compilation & cleanup
└── README.md # Project documentation

---

## 🛠 Compilation & Running

### 1️⃣ Compile using `make`
```bash
make

RUN THE PROGRAM
./bigint

CLEAN BUILD FILES
make clean

Sample Input
Enter first big integer: 123456789123456789
Enter second big integer: 987654321987654321

Sample Output
Number 1: 123456789123456789
Number 2: 987654321987654321
Sum: 1111111111111111110
Difference: 864197532864197532
Product: 121932631356500531347203169112635269
Quotient: 8
Remainder: 900000000900000009
Power (num1^3): 188167637743418398190956269994591
num1 is less than num2

📖 Implementation Details
Representation:

digits → Stores the number as a string

sign → +1 for positive, -1 for negative

length → Number of digits in the number

Main Functions:

createBigInt() → Initialize a BigInt from a string

printBigInt() → Display a BigInt

addBigInt() → Addition

subtractBigInt() → Subtraction

multiplyBigInt() → Multiplication

divideBigInt() → Integer division

modBigInt() → Modulo operation

powBigInt() → Exponentiation

compareBigInt() → Compare two BigInts

freeBigInt() → Free allocated memory

📌 Requirements
C Compiler (gcc recommended)

Works on Windows, Linux, and macOS

🏗 Future Improvements
Full support for negative numbers in all operations

Faster division & modulo using long division algorithm

Add modular exponentiation for cryptographic use

Improve performance and memory efficiency

📜 License
This project is licensed under the MIT License – you are free to use, modify, and distribute it.

🤝 Contributing
Contributions are welcome!
If you find bugs or have suggestions, please open an issue or create a pull request.

👨‍💻 Developed by: Varnit Chauhan
