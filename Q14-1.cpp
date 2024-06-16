#include <iostream>
#include <string>

using namespace std;

// UniversityStaff class definition
class UniversityStaff {
private:
    string name;

public:
    // Default constructor
    UniversityStaff() : name("") {}

    // Parameterized constructor
    UniversityStaff(string theName) : name(theName) {}

    // Copy constructor
    UniversityStaff(const UniversityStaff& theObject) : name(theObject.name) {}

    // Accessor method
    string getName() const {
        return name;
    }

    // Friend function for input stream operator overloading
    friend istream& operator>>(istream& inStream, UniversityStaff& staffObject);

    // Friend function for output stream operator overloading
    friend ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject);

    // Assignment operator overloading
    UniversityStaff& operator=(const UniversityStaff& rtSide) {
        if (this != &rtSide) {
            name = rtSide.name;
        }
        return *this;
    }
};

// Overloading the input stream operator to input the name of the staff
istream& operator>>(istream& inStream, UniversityStaff& staffObject) {
    cout << "Enter staff name: ";
    inStream >> staffObject.name;
    return inStream;
}

// Overloading the output stream operator to output the name of the staff
ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject) {
    outStream << "Staff name: " << staffObject.name;
    return outStream;
}

// Student class definition, inheriting from UniversityStaff
class Student : public UniversityStaff {
private:
    string registrationNumber;

public:
    // Default constructor
    Student() : UniversityStaff(), registrationNumber("") {}

    // Parameterized constructor
    Student(string theName, string regNumber) : UniversityStaff(theName), registrationNumber(regNumber) {}

    // Accessor method
    string getRegistrationNumber() const {
        return registrationNumber;
    }

    // Friend function for input stream operator overloading
    friend istream& operator>>(istream& inStream, Student& studentObject);

    // Friend function for output stream operator overloading
    friend ostream& operator<<(ostream& outStream, const Student& studentObject);

    // Assignment operator overloading
    Student& operator=(const Student& rtSide) {
        if (this != &rtSide) {
            UniversityStaff::operator=(rtSide);
            registrationNumber = rtSide.registrationNumber;
        }
        return *this;
    }
};

// Overloading the input stream operator to input the name and registration number of the student
istream& operator>>(istream& inStream, Student& studentObject) {
    cout << "Enter student name: ";
    inStream >> studentObject.name;
    cout << "Enter registration number: ";
    inStream >> studentObject.registrationNumber;
    return inStream;
}

// Overloading the output stream operator to output the name and registration number of the student
ostream& operator<<(ostream& outStream, const Student& studentObject) {
    outStream << "Student name: " << studentObject.getName() << ", Registration number: " << studentObject.getRegistrationNumber();
    return outStream;
}

int main() {
    // Create UniversityStaff object
    UniversityStaff staff1;
    cin >> staff1;
    cout << staff1 << endl;

    // Create Student object using parameterized constructor
    Student student1("Jane Doe", "12345");
    cout << student1 << endl;

    // Create another Student object and use input stream operator
    Student student2;
    cin >> student2;
    cout << student2 << endl;

    // Use the assignment operator
    student2 = student1;
    cout << "Assigned student: " << student2 << endl;

    return 0;
}
