/*my_string.cpp
Jialu Zhao 507
*/
#include <iostream>
#include "my_string.h"


//default constructor
my_string::my_string(): sz(0), cap(10),ptr(new char[cap]){}

//destructor
my_string::~my_string(){
	delete[] ptr;
}

// constructor with an int argument n
my_string::my_string(int n):sz(0), cap(n),ptr(new char[cap]){}

// constructor with a C-string creates a string
my_string::my_string(char *cstring){
	int size = 0;
	// c-string was terminated by a null character ’\0’
	while(cstring[size] != '\0'){
		size++;
	}
	ptr = new char[size];
	for(int i = 0; i<size; i++)
	{
		ptr[i] = cstring[i];
	}
	sz = size;
}

my_string::my_string(const my_string& str):sz(str.sz),cap(str.cap),ptr(new char[str.cap]){
	//copy constructor, for my_string s2=s1
	for(int i=0;i<sz;i++) 
		ptr[i]=str.ptr[i];
}

my_string& my_string::operator=(const my_string& str){
	//copy assignment, for v2=v1
	delete [] ptr; //deallocate old string
	sz = str.sz;
	cap = str.cap;
	ptr = new char[str.cap];
	for(int i=0; i<sz; i++)
		ptr[i] = str.ptr[i];
	//return reference
	return *this;
}

int my_string::size() const{//size()
	return sz;
}

int my_string::capacity() const{//capacity()
	return cap;
}

bool my_string::empty() const{//empty()
	return sz == 0;
}

char& my_string::operator[](int i) const {//operator[] , no bounds checking
	return ptr[i];
}

char& my_string::at(int i) const{//at
	if(i<0||i>=sz)
	{
		throw out_of_range("Please make sure i is between 0 and size of string!!!");//throw an exception
	}
	return ptr[i];
}

void my_string::doublecapacity(){// function for incrementing capacity of the string
	char* new_ptr = new char[cap*2];
	for(int i = 0; i<cap; i++){
		new_ptr[i] = ptr[i];
	}
	cap = cap*2;
	delete[] ptr;
	ptr = new_ptr;
}

my_string& my_string::operator+=(const my_string& str){//operator+= for a string
	while(sz + str.size() > cap){
		doublecapacity();
	}
	for(int i=0; i<str.size(); i++)
		ptr[i+sz] = str[i];
	sz = sz+str.size();
	return *this;

}

my_string& my_string::operator+=(const char& c){//operator+= for a char
	if(sz + 1 > cap){
		doublecapacity();
	}
	ptr[sz] = c;
	sz = sz+1;
	return *this;
}

my_string& my_string::insert(int r,const my_string& str){//insert
	if(r<0){
			throw out_of_range("Please make sure r >0!!!");
	}
	else 
		sz = sz + str.size();
	while(sz > cap){
		doublecapacity();
	}
	for(int i=sz-1; i>r; i--){
		ptr[i] = ptr[i-str.size()];
	}
	for( int i=0; i<str.size(); i++){
		ptr[i+r] = str[i];
	}

	return *this;
}

istream& operator>>(istream& in, my_string& str){// read stream from keyboard
	char* temp= new char[256];
	int i=0;
	in.getline(temp,256,'\n');
	while(!isspace(temp[i]) && temp[i]!=0)
	{
		str+=temp[i];
		i++;
	}
	return in;
}

ostream& operator<<(ostream& out, const my_string& str){
	for(int i=0; i<str.size(); i++){
		out<<str.at(i);//read string in stream
	}
	return out;
}

