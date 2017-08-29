 /* 
Jialu Zhao
username: zhaojialu123
section number: 507
email: zhaojialu123@tamu.edu
*/
//HashTable.h

#include "TemplateDoublyLinkedList.h"
#include <vector>
#include <iostream>
using namespace std;

class HashTable
{
public:
	HashTable(int size){
		// constructor: hash table is the vector of linked list
		TABLE_SIZE = size;
		table = vector<DoublyLinkedList<int>>(TABLE_SIZE);
	}

	~HashTable(){
		// destructor: destroy all elements using destructors for linkedlist one by one
		for(int i = 0; i < TABLE_SIZE; i++){
		table[i].~DoublyLinkedList<int>();	
		}
		
	}

	// Hash function 
	ulong hash(const unsigned long key){
		return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
	}

	// search function
	int search(const int key){
		int hashValue = hash(key);
		if( !table[hashValue].isEmpty()){
  			DListNode<int> *Iter = table[hashValue].getFirst(); // pointer to point head of the linked list
  			while(Iter != table[hashValue].getAfterLast()){ // stop when get to the tailer
    			if(Iter -> getKey() == key)
    				return Iter -> getValue();
    			Iter =  Iter -> getNext(); // move to next object
  			}
  		}

	}
	
	// insert function
	void insert(const ulong key, int value){
		int hashValue = hash(key);
		table[hashValue].insertFirst(key, value);
	}

    // get the statistic data of hash table
    // get the maximum length of the linkedlist in hash table
	int get_max()
	{
		int maximum = 0;
		for(int i = 0; i < TABLE_SIZE; i++){
		if(table[i].getlength() > maximum)
		maximum = table[i].getlength();	
		}
		return maximum;

	}
	// get the minimum length of the linkedlist in hash table
	int get_min()
	{
		int minimum = 0;
		for(int i = 0; i < TABLE_SIZE; i++){
		if(table[i].getlength() < minimum)
		minimum = table[i].getlength();	
		}
		return minimum;

	}

	// get the average length of the linkedlist in hash table
	double get_average()
	{
		int sum = 0;
		for(int i = 0; i < TABLE_SIZE; i++){
		sum = sum + table[i].getlength();
		}
		double average = double(sum) / TABLE_SIZE;
		return average;

	}

private:
	int TABLE_SIZE;
	vector<DoublyLinkedList<int>> table;
};
