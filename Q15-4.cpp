#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Base class Creature
class Creature {
protected:
    int type;      // 0 human, 1 cyberdemon, 2 balrog, 3 elf
    int strength;  // How much damage we can inflict
    int hitpoints; // How much damage we can sustain

public:
    // Default constructor
    Creature() : type(0), strength(10), hitpoints(10) {}

    // Parameterized constructor
    Creature(int newType, int newStrength, int newHit)
        : type(newType), strength(newStrength), hitpoints(newHit) {}

    // Accessor and mutator functions
    int getType() const { return type; }
    void setType(int newType) { type = newType; }

    int getStrength() const { return strength; }
    void setStrength(int newStrength) { strength = newStrength; }

    int getHitpoints() const { return hitpoints; }
    void setHitpoints(int newHit) { hitpoints = newHit; }

    // Virtual function to get the species of the creature
    virtual string getSpecies() const {
        switch (type) {
        case 0: return "Human";
        case 1: return "Cyberdemon";
        case 2: return "Balrog";
        case 3: return "Elf";
        default: return "Unknown";
        }
    }

    // Virtual function to get the damage
    virtual int getDamage() const {
        int damage = (rand() % strength) + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }
};

// Derived class Demon
class Demon : public Creature {
public:
    Demon() : Creature(1, 10, 10) {}
    Demon(int newType, int newStrength, int newHit) : Creature(newType, newStrength, newHit) {}

    int getDamage() const override {
        int damage = Creature::getDamage();
        if ((rand() % 100) < 5) {
            damage += 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }
        return damage;
    }
};

// Derived class Cyberdemon
class Cyberdemon : public Demon {
public:
    Cyberdemon() : Demon(1, 10, 10) {}
    Cyberdemon(int newStrength, int newHit) : Demon(1, newStrength, newHit) {}

    string getSpecies() const override {
        return "Cyberdemon";
    }
};

// Derived class Balrog
class Balrog : public Demon {
public:
    Balrog() : Demon(2, 10, 10) {}
    Balrog(int newStrength, int newHit) : Demon(2, newStrength, newHit) {}

    string getSpecies() const override {
        return "Balrog";
    }

    int getDamage() const override {
        int damage = Demon::getDamage();
        int damage2 = (rand() % strength) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;
        return damage;
    }
};

// Derived class Elf
class Elf : public Creature {
public:
    Elf() : Creature(3, 10, 10) {}
    Elf(int newStrength, int newHit) : Creature(3, newStrength, newHit) {}

    string getSpecies() const override {
        return "Elf";
    }

    int getDamage() const override {
        int damage = Creature::getDamage();
        if ((rand() % 10) == 0) {
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
            damage *= 2;
        }
        return damage;
    }
};

// Derived class Human
class Human : public Creature {
public:
    Human() : Creature(0, 10, 10) {}
    Human(int newStrength, int newHit) : Creature(0, newStrength, newHit) {}

    string getSpecies() const override {
        return "Human";
    }
};

// Function to simulate a battle between two creatures
void battleArena(Creature& creature1, Creature& creature2) {
    int damage1 = creature1.getDamage();
    int damage2 = creature2.getDamage();

    creature1.setHitpoints(creature1.getHitpoints() - damage2);
    creature2.setHitpoints(creature2.getHitpoints() - damage1);

    cout << creature1.getSpecies() << " has " << creature1.getHitpoints() << " hit points left." << endl;
    cout << creature2.getSpecies() << " has " << creature2.getHitpoints() << " hit points left." << endl;

    if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0) {
        cout << "It's a tie!" << endl;
    }
    else if (creature1.getHitpoints() <= 0) {
        cout << creature2.getSpecies() << " wins!" << endl;
    }
    else if (creature2.getHitpoints() <= 0) {
        cout << creature1.getSpecies() << " wins!" << endl;
    }
    else {
        cout << "The battle continues!" << endl;
    }
}

// Main function to test the classes
int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    // Create objects of each type of creature
    Human h1(20, 50);
    Elf e1(25, 40);
    Cyberdemon c1(30, 60);
    Balrog b1(35, 70);

    // Test the getDamage() function for each type of creature
    cout << "Human damage: " << h1.getDamage() << endl;
    cout << "Elf damage: " << e1.getDamage() << endl;
    cout << "Cyberdemon damage: " << c1.getDamage() << endl;
    cout << "Balrog damage: " << b1.getDamage() << endl;

    // Simulate a battle
    battleArena(h1, e1);
    battleArena(c1, b1);
    battleArena(h1, c1);

    return 0;
}
