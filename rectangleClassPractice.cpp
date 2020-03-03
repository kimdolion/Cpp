#include <iostream>
#include <string>
using namespace std;

class Rectangle {
private:
	double length;
	double width;
public:
	double getWidth() const;
	void setWidth(double);
	double getLength() const;
	void setLength(double);
	double area();
};

void Rectangle::setWidth(double w) {
	width = w;
}

void Rectangle::setLength(double l) {
	length = l;
}

double Rectangle::getLength() const {
	return length;
}
double Rectangle::getWidth() const {
	return width;
}
double Rectangle::area() {
	return length * width;
}

int main() {
	Rectangle firstRect; // creating an instance of a rectangle
	double firstLength, firstWidth, firstArea;
	cout << "Enter the length of your rectangle: ";
	cin >> firstLength;
	firstRect.setLength(firstLength);
	cout << "Enter the width of your rectangle: ";
	cin >> firstWidth;
	firstRect.setWidth(firstWidth);
	cout << "Your rectangle has a length of " << firstRect.getLength() << " and a width of " << firstRect.getWidth() << endl;
	firstArea = firstRect.area();
	cout << "The area of your rectangle is " << firstArea;
	return 0;
}