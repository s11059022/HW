#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Dice class definition
class Dice {
public:
    Dice();                     // Default constructor
    Dice(int numSides);         // Constructor with number of sides
    virtual int rollDice() const; // Function to roll the dice
protected:
    int numSides;               // Number of sides of the dice
};

// Default constructor
Dice::Dice() {
    numSides = 6;
    srand(time(NULL));          // Seed random number generator
}

// Constructor with number of sides
Dice::Dice(int numSides) {
    this->numSides = numSides;
    srand(time(NULL));          // Seed random number generator
}

// Function to roll the dice
int Dice::rollDice() const {
    return (rand() % numSides) + 1;
}

// Function to roll two dice and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2) {
    return die1.rollDice() + die2.rollDice();
}

// LoadedDice class derived from Dice
class LoadedDice : public Dice {
public:
    LoadedDice();               // Default constructor
    LoadedDice(int numSides);   // Constructor with number of sides
    int rollDice() const override; // Override rollDice function
};

// Default constructor for LoadedDice
LoadedDice::LoadedDice() : Dice() {}

// Constructor with number of sides for LoadedDice
LoadedDice::LoadedDice(int numSides) : Dice(numSides) {}

// Override rollDice function
int LoadedDice::rollDice() const {
    if (rand() % 2 == 0) {
        return numSides;        // 50% chance to return the largest number
    }
    else {
        return Dice::rollDice();
    }
}

// Main function to test the classes
int main() {
    // Create two Dice objects
    Dice die1(6);
    Dice die2(6);

    // Test rollTwoDice function with Dice objects
    cout << "Rolling two Dice objects:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Roll " << i + 1 << ": " << rollTwoDice(die1, die2) << endl;
    }

    // Create two LoadedDice objects
    LoadedDice loadedDie1(6);
    LoadedDice loadedDie2(6);

    // Test rollTwoDice function with LoadedDice objects
    cout << "\nRolling two LoadedDice objects:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Roll " << i + 1 << ": " << rollTwoDice(loadedDie1, loadedDie2) << endl;
    }

    return 0;
}
