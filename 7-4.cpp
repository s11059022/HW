#include <iostream>
using namespace std;
class HotDogStand {
public:
    HotDogStand(int id, int numberSold);
    HotDogStand();
    void justSold();
    //increments the numbers of hot dogs sold by 1.
    void setID(int id);
    int getID();
    static int getTotalHotDogs();
    //returns total hot dogs
    int getNumberOfHotDogsSold();
    //returns the number of hot dogs sold.
private:
    int hotDogID;
    int hotDogsSold;

    static int totalHotDogsSold;
    //to hold total number of sold hot dogs.1
};
int HotDogStand::totalHotDogsSold = 0;
//static variables are initialized outside the class.
//initialized the static variable's value to 0.
int main() {
    HotDogStand h1(1, 0);
    HotDogStand h2;

    h1.justSold();
    h1.justSold();

    h2.justSold();
    h2.justSold();
    h2.justSold();

    cout << "h1 id number " << h1.getID() << " sold " << h1.getNumberOfHotDogsSold() << endl;
    cout << "h2 id number " << h2.getID() << " sold " << h2.getNumberOfHotDogsSold() << endl;
    cout << endl;
    cout << "Total number of hot dogs sold: " << h1.getTotalHotDogs() << endl;
    cout << endl;
    return 0;
}
HotDogStand::HotDogStand(int id, int numberSold) : hotDogID(id), hotDogsSold(numberSold) {}
//initializes the parameters to hotDogID and hotDogSold.
HotDogStand::HotDogStand() : hotDogID(0), hotDogsSold(0) {}
//initializes the hotDogID to 1 and hotDogsSold to 0.
void HotDogStand::justSold() {
    hotDogsSold++;
    totalHotDogsSold++;
}
void HotDogStand::setID(int id) {
    hotDogID = id;
}
int HotDogStand::getID() {
    return hotDogID;
}
int HotDogStand::getTotalHotDogs() { return totalHotDogsSold; }
int HotDogStand::getNumberOfHotDogsSold() { return hotDogsSold; }