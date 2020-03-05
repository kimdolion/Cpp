#include <iostream>
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
	Rectangle();
	~Rectangle();
};
Rectangle::Rectangle() {
	length = 1;
	width = 10;
	cout << "This is a rectangle constructor" << endl;
}
Rectangle::~Rectangle() {
	cout << "Destructor is now run." << endl;
}
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
	cout << "The area of your rectangle is " << firstArea << endl << endl;
	
	Rectangle secondRect; // creating an instance of a rectangle
	cout << "Create another rectangle.\n";
	double secondLength, secondWidth, secondArea;
	cout << "Enter the length of your rectangle: ";
	cin >> secondLength;
	secondRect.setLength(secondLength);
	cout << "Enter the width of your rectangle: ";
	cin >> secondWidth;
	secondRect.setWidth(secondWidth);
	cout << "Your rectangle has a length of " << secondRect.getLength() << " and a width of " << secondRect.getWidth() << endl;
	secondArea = secondRect.area();
	cout << "The area of your rectangle is " << secondArea << endl << endl;
	
	Rectangle thirdRect;
	cout << "Your rectangle has a length of " << thirdRect.getLength() << " and a width of " << thirdRect.getWidth() << endl;
	
	return 0;
}
