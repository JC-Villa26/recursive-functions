#ifndef RECURSION_H
#define RECURSION_H
#include <iostream>
#include <string>
using namespace std;

const int WIDTH = 4;
const int HEIGHT = 5;

//Doll class for the findCenter function. This represents a Matryoshka doll with another Doll inside it
//A doll containing no other Dolls will have an innerDoll of nullptr
class Doll {
    string name;
    unsigned int id;
    static unsigned int count;
    Doll* innerDoll;
public:
    Doll* getInnerDoll() const { return innerDoll; }
    void printDoll() { cout << "Doll: " << id << " " << name << endl; }
    Doll(string name, Doll* inside) { this->name = name; innerDoll = inside; id = count; count++; }
};

//---------------------------- Recursive function implementations ----------------------------
/* Description */
int power(const int& base, int pow)
{
    //Check for the base case; anything to the 0th is trivial to solve
    //Otherwise, recursively take the power of a base with a lower pow

    //base case
    if (pow == 0) {
        return 1;
    }

    //general case
    return base * power(base, pow - 1);

}

/* Description */
int findBiggestNumber(int arr[], int index)
{
    //Try to find the biggest number in the array. If a base case is hit where the biggest value is trivial,
    //return the result without recursing. Else, try to find the biggest number in the array ending at the index
    //to the left of the current one. Then return the biggest value between that value and the one at the current index.
    //Try not to do more than one recursive call here.
    //(HINT Try using a variable to store the result of your recursive case)

    //base case
    if (index == 0) {
        return arr[0];
    }

    //general case
    int currentBiggest = findBiggestNumber (arr, index - 1);

    //compare that with the current element and return the larger value
    if (arr[index] > currentBiggest) {
        return arr[index];
    }
    else {
        return currentBiggest;
    }

}
/* Description */
void findTheX(char grid[HEIGHT][WIDTH], const int& x, const int& y)
{
    //If the char at the current spot is an X, then we solved it
    //Print the message and mark the spot as a O now to make sure we don't find it twice
    //Else if the char is an 'O', it is either a wall or has been verified
    //to not contain the X
    //If this is not the X or an O, mark this spot as a O then recursively try the right, left, above
    //and below spots only if each are in bounds of the array
    //You can assume the grid always has dimensions of the consts HEIGHT and WIDTH
    //by the parameter declaration above and that the X is always findable. Consider
    //that with row major arrays, y should come before x when accessing, as well

    //base case 1
    if (grid[y][x] == 'X') {
        cout << "Found the X at (" << x << ", " << y << ")" << endl; 
        grid[y][x] = 'O';
        return;
    }

    //base case 2
    if (grid[y][x] == 'O') {
        return; 
    }

    //general case: this spot is an empty space 
    //mark as visited so we don't come back here
    grid[y][x] = 'O';

    //try right, check if x+1 is within the bounds
    if (x + 1 < WIDTH) {
        findTheX(grid, x + 1, y);
    }

    //try left, check if x-1 is not negative
    if (x - 1 >= 0) {
        findTheX(grid, x - 1, y);
    }

    //try up, check if y-1 is not negative
    if (y - 1 >= 0) {
        findTheX(grid, x, y - 1);
    }

    //try down, check if y+1 is within the bounds
    if (y + 1 < HEIGHT) {
        findTheX(grid, x, y + 1);
    }
}

/* Description */
void findCenter(Doll* doll)
{
    //Try to find the center most Doll in a stack of Matryoshka dolls.
    //Print the doll we are currently opening using it's printDoll function and then open the next one
    //If this is the inner most Doll, don't recurse.

    //base case
    if (doll == nullptr){
        return;
    }

    //general case
    doll->printDoll();
    findCenter(doll->getInnerDoll());
}

#endif
