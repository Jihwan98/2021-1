#include <iostream>
using namespace std;

int main()
{
	/*cout << "C++" << "Java" << endl;
	cout << "C++" << endl << "Java" << endl;
	cout << "C++, " << "Java, " << "and C#" << endl;*/

	/*double radius;
	cout << "Enter a radius: ";
	cin >> radius;

	double area = radius * radius * 3.141592;

	cout << "The area is " << area << endl;*/

	/*double num1, num2, num3;
	cout << "Enter three numbers: ";
	cin >> num1 >> num2 >> num3;

	double average = (num1 + num2 + num3) / 3;

	cout << "The average of " << num1 << " " << num2 << " " << num3 << "is " << average << endl;*/

	const double PI = 3.141592;

	double radius;

	cout << "Enter radius: ";
	cin >> radius;

	double area = radius * radius * PI;

	cout << "The area is " << area << endl;

	return 0;
}