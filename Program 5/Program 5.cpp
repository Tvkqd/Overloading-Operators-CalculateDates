// Tuyen Vu
// tvkqd@mail.umkc.edu
// Program 5
// Due 11/03/2019

#include<iostream>
#include"Header.h"

using namespace std;

int main() {
	Date date1(10, 22, 2019);
	Date date2(10, 15, 1944);

	//Overloading operator << test
	cout << "date1: " << date1 << endl;
	cout << "date2: " << date2 << endl;

	//Overloading operator = test
	Date date3 = date1;
	Date date4 = date2;

	//Overloading operator --,++ test
	cout << "date3 after pre-increment: " << ++date3 << endl;
	cout << "date4 after pre-decrement: " << ++date4 << endl;
	
	//Overloading +=,-= test
	date3 += 20;
	cout << "date3 after add 20 days: " << date3 << endl;
	date4 -= 130;
	cout << "date4 after minus 130 days: " << date4 << endl;

	//Overloading operator - test
	cout << "Difference between date3 and date4: " << date3 - date4 << " days" << endl;

	system("pause");
	return 0;
}