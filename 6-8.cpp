#include <iostream>
#include <cstdlib>
using namespace std;

class Money {
public:
	void output();
	void set(double NewDollar,double NewCent); 
	int getDollar();
	int getCent();
private:
	double dollar;
	double cent;
	double total;
};

int main() {
	Money money;
	double NewDollar = 0;
	double NewCent = 0;
	cout << "Enter the number of dollars: ";
	cin >> NewDollar;
	cout << "Enter the number of cents: ";
	cin >> NewCent;
	money.set(NewDollar, NewCent);
	money.getDollar();
	money.getCent();
	money.output();
	return 0;
}


void Money::set(double NewDollar,double NewCent) {
	if (NewDollar >= 0)
		dollar = NewDollar;
	else {
		cout << "Illegal number! Program aborted.\n";
		exit(1);
	}
	if (NewCent >= 0)
		cent = NewCent;
	else {
		cout << "Illegal number! Program aborted.\n";
		exit(1);
	}
}
int Money::getDollar() {
	return dollar;
}
int Money::getCent() {
	return cent;
}
void Money::output() {
	total = dollar + (cent / 100);
	cout << "Your money is $ " << total << "." << endl;
}
