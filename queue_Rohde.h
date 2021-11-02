#pragma once
// Guard to ensure multiples of the same file are not loaded. 
#ifndef QUEUE_ROHDE_H
#define QUEUE_ROHDE_H
#include "arrayListType.h"
#include "unorderedArrayListType.h"


//-------------------------------------------------------------------------------------------------------CJR
// Name: Christopher Rohde
// Date: 03/01/2019
// Assignment: Header file for queue class for HW11 (grandchild of arrayListType, child of unorderedArrayListType)
//-------------------------------------------------------------------------------------------------------CJR


// queue class - a queue is a first in first out kind of list. This queue class has functions that allow this type
// of manipulation of an unorderedArrayListType
class queue : private unorderedArrayListType
{
public:
  friend std::ostream& operator<<(std::ostream&, const queue&);
  // Pre: Non-Member friend of queue class accepts a reference parameter of type ostream and a reference parameter of type queue.
  // Post: Prints the queue in the format of an 'arrayList' from java. 

  bool isEmpty() const; // test whether queue is empty
  // Post: returns true if queue is empty, otherwise returns false

  int size() const; // return size
  // Post: returns the number of elements in the queue

  int front() const; // returns the element at the front of the queue. This should be the "oldest" element, the same element that will be removed if deque() is called next
  // Pre: the queue is not empty
  // Post: returns the element at the front of the queue

  int back() const; // returns the element at the back of the queue. This should be the "youngest" element, the same element that was added into the queue most recently using enque()
  // Pre: the queue is not empty
  // Post: returns the element at the back of the queue

  void enque(int newItem); // insert one element at the back of the queue, after its current last element (the "youngest" element before this enque)
  // Post: newItem added at the end of the queue, after the current last element

  int deque(); // remove one element from the front of the queue. The "oldest" element should be removed
  // Pre: the queue is not empty
  // Post: the item at the front of the queue is removed from the queue and returned

  queue(int size = 100);
  // Post: queue initialized with capacity being size param and contains 0 elements.
  //       if no size is specified, 100 is used for the capacity
};
#endif // !QUEUE_ROHDE_H
