#include <iostream>
#include <cstdlib>
using namespace std;

class Weight {
public:
	void setWeightPounds();
	void setWeightKilograms();
	void setWeightOunces();
	void input();
	void output();
private:
	double weight;
	double pound;
	double kilogram;
	double ounce;
};

int main() {
	Weight weight;
	weight.input();
	weight.setWeightPounds();
	weight.setWeightKilograms();
	weight.setWeightOunces();
	weight.output();
	return 0;
}
void Weight::input() {
	cout << "Enter the weight :";
	cin >> weight;
	if (weight <= 0) {
		cout << "Illegal value! Program aborted.";
		exit(1);
	}
}
void Weight::setWeightPounds() {
	if (weight <= 0) {
		cout << "Illegal value! Program aborted.";
		exit(1);
	}
	else
		pound = weight;
}
void Weight::setWeightKilograms() {
	if (weight <= 0) {
		cout << "Illegal value! Program aborted.";
		exit(1);
	}
	else
		kilogram = weight/2.21;
}
void Weight::setWeightOunces() {
	if (weight <= 0) {
		cout << "Illegal value! Program aborted.";
		exit(1);
	}
	else
		ounce = weight*16;
}
void Weight::output() {
	cout << "The weight in pounds is " << pound << endl;
	cout << "The weight in kilograms is " << kilogram << endl;
	cout << "The weight in ounces is " << ounce << endl;
}