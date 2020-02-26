// Tuyen Vu
// tvkqd@mail.umkc.edu
// Program 5
// Due 11/03/2019

#pragma once
#include<iostream>
#include<string>
using namespace std;

class Date {
	int month;
	int day;
	int year;
	static int daysInMonth[12];
	static string daysOfWeek[7];
	static string monthsOfYear[12];
	static int startWeekday;
	static int startYear;

public:
	//Constructors
	Date();
	Date(int mm, int dd, int yy);

	//Check if a date is a valid one or not
	bool isValid() const;

	//Check if a year is leap
	bool isLeap(int yy) const;

	//Return the number of days since 1/1/1900
	int findTotalDays() const;

	//Pre-increment a day
	Date& operator++();

	//Pre-decrement a day
	Date& operator--();

	//Post-increment a day
	Date operator++(int);

	//Post-decrement a day
	Date operator--(int);

	//Add days to given date
	Date& operator+=(int days);

	//Subtract days from given date
	Date& operator-=(int days);

	//Check if dates of 2 objects are the same
	bool operator==(const Date& right) const;

	//Check if dates of 2 objects are not the same
	bool operator!=(const Date& right) const;

	//Assign object to another object
	Date& operator=(const Date& right);

	//Return the number of days different of 2 objects
	friend int operator-(const Date& date1, const Date& date2);

	//Return the output current day, month, year
	friend ostream& operator<<(ostream& output, const Date& date);

	//Update change in date after increment
	void plusReset();

	//Update change in date after decrement
	void minusReset();
};

