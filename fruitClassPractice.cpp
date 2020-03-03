#include <iostream>
#include <string>
using namespace std;

class Fruit {
private:
	string name;
	int number;
public:
	string getName() const;
	void setName(string);
	int getNumber() const;
	void setNumber(int);
};

void Fruit::setName(string s) {
	name = s;
}
void Fruit::setNumber(int n) {
	number = n;
}

string Fruit::getName() const {
	return name;
}
int Fruit::getNumber() const {
	return number;
}

int main() {
	Fruit orange; // creating an instance of a fruit
	string fruitName; // creating local variable
	int fruitNumber; // creating local variable
	cout << "Enter the name of your fruit: ";
	cin >> fruitName;
	orange.setName(fruitName);
	cout << "Enter the amount you have of your " << orange.getName() << ": ";
	cin >> fruitNumber;
	orange.setNumber(fruitNumber);
	cout << "You have " << orange.getNumber() << " " << orange.getName();
	return 0;
}