# Recursive Functions Library

A C++ program implementing four recursive algorithms demonstrating base case design and call stack management.

## Concepts Demonstrated
- Recursive function design and implementation
- Base case and recursive case structure
- 2D array traversal using recursion
- Pointer-based recursive data structures

## Project Structure
- recursion.h — Function declarations
- recursion.cpp — Recursive function implementations

## How to Compile and Run
```
g++ -Wall -std=c++17 recursion.cpp -o recursion
./recursion
```

## Functions Implemented
- **power** — Computes base to the power recursively
- **findBiggestNumber** — Finds the maximum value in an array recursively
- **findTheX** — Searches a 2D maze for a target character recursively
- **findCenter** — Traverses nested Matryoshka dolls recursively to find the center

## Sample Output
```
Which function should be tested?
(1) power
(2) findBiggestNumber
(3) findTheX
(4) findCenter
1
2^10 = 1024
4^0 = 1
```
