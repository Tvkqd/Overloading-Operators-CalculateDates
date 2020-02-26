// Tuyen Vu
// tvkqd@mail.umkc.edu
// Program 5
// Due 11/03/2019

#include "Header.h"
#include<iostream>
#include<string>

using namespace std;

//Initialize static variables
int Date::startWeekday = 1;
int Date::startYear = 1900;
int Date::daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string Date::daysOfWeek[] = { "Monday", "Tueday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
string Date::monthsOfYear[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

//Constructors
Date::Date() {
	month = 1;
	day = 1;
	year = startYear;
}

Date::Date(int mm, int dd, int yy) {
	month = mm;
	day = dd;
	year = yy;
	if (!isValid()) {
		cout << "WARNING---INVALID DATE---PLEASE FIX BEFORE KEEP GOING" << endl;
		cout << "WARNING---INVALID DATE---PLEASE FIX BEFORE KEEP GOING" << endl;
		cout << "WARNING---INVALID DATE---PLEASE FIX BEFORE KEEP GOING" << endl;
	}
}

//Check if a date is a valid one or not
bool Date::isValid() const {
	if (month < 1 || month > 12 || year < startYear || day < 1)
		return false;
	if (day > daysInMonth[month - 1]) {
		if (isLeap(year) && day == 29)
			return true;
		else
			return false;
	}
	return true;
}

//Check if a year is leap
bool Date::isLeap(int yy) const{
	if (yy % 4 == 0) {
		if (yy % 100 != 0)
			return true;
		else {
			if (yy % 400 == 0)
				return true;
		}
	}
	else
		return false;
}

//Return the number of days since 1/1/1900
int Date::findTotalDays() const {
	int total = 0;
	int i = 1;
	int numYears = year - startYear;
	int numLeap = numYears / 4;

	//Calculate the passed days in current year
	while (i < month) {
		total += daysInMonth[i - 1];
		i++;
	}
	//Add days for current month
	total += day;

	//Add days for each passed year
	if (isLeap(year)) {
		//Do not count current year if it is leap
		numLeap--;
		total += numLeap * 366 + (numYears - numLeap) * 365;
		if (month > 2)
			//Add 1 day for current leap year
			total++;
	}
	else {
		total += numLeap * 366 + (numYears - numLeap) * 365;
	}

	return --total;
}


//Pre-increment a day
Date& Date::operator++() {
	day++;
	return *this;
}

//Pre-decrement a day
Date& Date::operator--() {
	day--;
	return *this;
}

//Post-increment a day
Date Date::operator++(int) {
	Date temp = *this;
	day++;
	return temp;
}

//Post-decrement a day
Date Date::operator--(int) {
	Date temp = *this;
	day--;
	return temp;
}

//Add days to given date
Date& Date::operator+=(int days) {
	day += days;
	//Update if date is not valid
	if (!isValid()) 
		plusReset();
	return *this;
}

//Subtract days from given date
Date& Date::operator-=(int days) {
	day -= days;
	//Update if date is not valid
	if (!isValid())
		minusReset();
	return *this;
}

//Check if dates of 2 objects are the same
bool Date::operator==(const Date& right) const {
	return *this == right;
}

//Check if dates of 2 objects are not the same
bool Date::operator!=(const Date& right) const {
	return *this != right;
}

//Assign object to another object
Date& Date::operator=(const Date& right) {
	if (*this == right)
		return *this;
	else {
		day = right.day;
		month = right.month;
		year = right.year;
		return *this;
	}
}

//Return the number of days different of 2 objects
int operator-(const Date& date1, const Date& date2) {
	int diff;
	
	diff = date1.findTotalDays() - date2.findTotalDays();
	return abs(diff);
}


//Return the output current day, month, year
ostream& operator<<(ostream& output, const Date& date) {
	//Get remainder of total passed day since 1/1/1900 divided by 7
	int index = date.findTotalDays() % 7;
	output << date.daysOfWeek[index] << " " << date.monthsOfYear[date.month - 1] << " " << date.day << " " << date.year << endl;
	return output;
}

//Update change in date after increment
void Date::plusReset() {
	int numYear;
	//Update year
	if (day >= 365) {
		numYear = day / 365;
		day = day % 365;
		for (int i = 1; i <= numYear; i++) {
			if (isLeap(year) && month < 3)
				day--;
			year++;	
		}
	}
	//Update month
	while (!isValid()) {
		if (isLeap(year) && month == 2)
			day--;
		day -= daysInMonth[month - 1];
		month++;
		if (month > 12) {
			//Go to next year
			year++;
			month = 1;
		}
	}
}


//Update change in date after decrement
void Date::minusReset() {
	int numYear;
	day *= -1;
	//Update year
	if (day >= 365) {
		numYear = day / 365;
		day = day % 365;
		for (int i = 1; i <= numYear; i++) {
			if (isLeap(year) && month > 2)
				day--;
			year--;
		}
	}
	//Update month
	do{
		month--;
		if (month < 1) {
			//Goback a year
			month = 12;
			year--;
		}
		day -= daysInMonth[month - 1];
		if (isLeap(year) && month == 2)
			day--;
	} while (day > 0);
	day *= -1;
}
