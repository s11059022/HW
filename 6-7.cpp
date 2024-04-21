#include <iostream>
#include <cstdlib>
using namespace std;
//set the class
class Pizza {
public:
	//create public function
	void input();
	void outputDescription();
	void computePrice();
private:
	//create private member
	char type;//type constants
	char size;//size constants
	int number_of_cheese;
	int number_of_pepperoni;
	double price = 0;
};
int main() {
	Pizza pizza;
	pizza.input();
	pizza.outputDescription();
	pizza.computePrice();
	return 0;
}
void Pizza::input() {
	cout << "Enter the first alphabet of type (deep dish/hand tossed/pan) : ";
	cin >> type;
	cout << "Enter the first alphabet of size (small/medium/large) :";
	cin >> size;
	cout << "Enter the number of cheese topping :";
	cin >> number_of_cheese;
	cout << "Enter the number of pepperoni topping :";
	cin >> number_of_pepperoni;
}
void Pizza::outputDescription() {
	cout << "Your order is ";
	switch (size) {
	case 's':
		cout << "small ";
		break;
	case 'm':
		cout << "medium ";
		break;
	case 'l':
		cout << "large ";
		break;
	default:
		break;
	}
	switch (type) {
	case 'd':
		cout << "deep dish pizza with ";
		break;
	case 'h':
		cout << "hand tossed pizza with ";
		break;
	case 'p':
		cout << "pan pizza with ";
		break;
	default:
		break;
	}
	cout << number_of_pepperoni + number_of_cheese << " toppings" << endl;
}
void Pizza::computePrice() {
	switch (size) {
	case 's':
		price += 10;
		break;
	case 'm':
		price += 14;
		break;
	case 'l':
		price += 17;
		break;
	default:
		break;
	}
	price += 2 * (number_of_cheese + number_of_pepperoni);
	cout << "The price is " << price << " dollars.\n";
}