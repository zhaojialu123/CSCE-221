/*my_string.h
Jialu Zhao 507
Header file for a string data structure
*/
#include <iostream>
#include <stdexcept>
using namespace std;
#ifndef my_string_H
#define my_string_H

class my_string
{
public://member functions
	my_string(); //default constructor
	~my_string(); //destructor
	my_string(int n); //constructor with an int argument n
	my_string(char *cstring); //constructor with a C-string creates a string
	my_string(const my_string& str); //copy constructor
	my_string& operator=(const my_string& str); //copy assignment
	int size() const; //size()
	int capacity() const; //capacity()
	bool empty() const; //empty()
	char& operator[](int i) const; //operator[](i) 
	char& at(int i) const; //– at(i)
	my_string& operator+=(const my_string& str); //operator+= for string
	my_string& operator+=(const char& c); //operator += for char
	my_string& insert(int r,const my_string& str); //insert function

private://member variables
	char *ptr;
	int sz;
	int cap;
	void doublecapacity();
};
	istream& operator>>(istream& in, my_string& str); // input operator
	ostream& operator<<(ostream& out, const my_string& str); // output operator

#endif