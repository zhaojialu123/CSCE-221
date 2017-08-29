// Jialu Zhao
// section: 507
// 02/22/2017
// programming assignment 3

#include "DoublyLinkedList.h"
#include <stdexcept>




// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  // empty doubly linked list
  if( !dll.isEmpty()){
  DListNode *Iter = dll.getFirst(); // pointer to point head of the linked list
  while(Iter != dll.getAfterLast()){ // stop when get to the tailer
    insertLast( Iter -> obj); // insert the value of dll to the new linked list
    Iter =  Iter -> next; // move to next object
  }//complexity:O(n)
  // Copy from dll
  // Complete this function
  }
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  // remove all old elements
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  }//complexity:O(n)

  // Initialize the list
  header.next = &trailer;
  trailer.prev = &header;
  // copy elements from dll
  if( !dll.isEmpty()){
  DListNode *Iter = dll.getFirst(); // pointer to point head of the linked list
  while(Iter != dll.getAfterLast()){ // stop when get to the tailer
    insertLast( Iter -> obj); // insert the value of dll to the new linked list
    Iter =  Iter -> next; // move to next object
  }//complexity:O(n)
  return *this;
  // //complexity:O(n)+O(n)=O(n)
  // Complete this function

}
}

// insert the object to the first of the linked list
void DoublyLinkedList::insertFirst(int newobj)
{ 
  DListNode *newNode = new DListNode(newobj, &header, header.next); // create a new node with th value of newobj
  header.next -> prev = newNode;
  header.next = newNode;
  // Complete this function
}
//complexity:O(1)

// insert the object to the last of the linked list
void DoublyLinkedList::insertLast(int newobj)
{
  DListNode *newNode = new DListNode(newobj, trailer.prev,&trailer); // create a new node with th value of newobj
  trailer.prev->next = newNode;
  trailer.prev = newNode;
}
//complexity:O(1)

// remove the first object of the list
int DoublyLinkedList::removeFirst()
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = header.next;
  node -> next -> prev = &header;// make the first node to be null
  header.next = node -> next;
  int obj = node -> obj;
  delete node;
  return obj; //get the value of the removed node
  // Complete this function
}
//complexity:O(1)

// remove the last object of the list
int DoublyLinkedList::removeLast()
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  DListNode *node = trailer.prev;
  node->prev->next = &trailer; // make the last node to be null
  trailer.prev = node->prev;
  int obj = node->obj;
  delete node;
  return obj; //get the value of the removed node
}
//complexity:O(1)

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
  DListNode *prev_node, *node = header.next;
  while (node != &trailer) {
    prev_node = node;
    node = node->next;
    delete prev_node;
  } //complexity:O(n)
  header.next = &trailer;
  trailer.prev = &header;
}

// return the first object
int DoublyLinkedList::first() const
{ 
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  // Complete this function
  return header.next -> obj;
}
//complexity:O(1)

// return the last object
int DoublyLinkedList::last() const
{
  if (isEmpty())
    throw EmptyDLinkedListException("Empty Doubly Linked List");
  return trailer.prev -> obj;
}
//complexity:O(1)

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
  DListNode *Iter = dll.getFirst(); // pointer to point head of the linked list
  while(Iter != dll.getAfterLast()){ // stop when get to the tailer
    out << Iter -> getElem() << ' '; // read out value in this node
    Iter =  Iter -> getNext(); // move to next object
  }
  //complexity:O(n)
  // Complete this function
  return out;
}
