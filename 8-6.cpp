#include <iostream>
#include <cmath> //pow()
#include <cstdlib> //exit()
#include <vector>
using namespace std;
class MyInteger {
public:
    void setInteger(int intValue);
    int getInteger() const;
    //counts the number of digits in the number
    //and sets the value to sizeOfArray
    void setSizeOfArray();

    void setValuesInArray();
    void reverseTheOrder();
    int& operator [](int index);
private:
    int sizeOfArray;
    vector<int> arr;
    int integer;
};

//getter and setter member functions for integer
void MyInteger::setInteger(int intValue) {
    integer = intValue;
}
int MyInteger::getInteger() const { return integer; }

void MyInteger::setValuesInArray() {
    int number = integer;
    int counter = 0;
    while (number > 0) {
        arr.push_back(number % 10);
        number = number / 10;
        counter++;
    }
}
void MyInteger::setSizeOfArray() {
    int digit = 0;
    int number = integer;
    while (true) {
        number = number / 10;
        digit++;
        if (number == 0) {
            break;
        }
    }
    sizeOfArray = digit;
}

int& MyInteger::operator [](int index) {
    if (index > sizeOfArray) {
        cout << "Maximum size exceeded.";
        exit(1);
    }
    else {
        return arr[index];
    }
}
int main() {
    MyInteger i;
    i.setInteger(9845);
    i.setSizeOfArray();
    i.setValuesInArray();
    //i.reverseTheOrder();
    cout << i[1];
    cout << endl;
    return 0;
}