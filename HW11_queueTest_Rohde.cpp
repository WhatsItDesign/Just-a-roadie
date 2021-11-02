#include <iostream>
#include "arrayListType.h"
#include "unorderedArrayListType.h"
#include "queue_Rohde.h"

// Name: Christopher Rohde; 
// Adapted from the work of Professor Bin "Crystal" Peng's work HW11_queue_shell.cpp
// Date: 03/01/2019
// Assignment: HW11_arrayListType_Rohde
// Main driver/test for function for queue Class. Queue class is a first in first out list 
// storage class. 

int main()
{
  // Test default and assigned construction.
  queue myQue, yourQue(1000);
  // Check is empty when empty.
  std::cout << "If myQue is empty return 1: " << myQue.isEmpty() << std::endl;
  // Check size when 0
  std::cout << "The current number of elements in myQue is: " << myQue.size() << std::endl;

  // Insert multiple values starting from 5 going to 50
  for (int i = 0; i < 10; i++)
  {
    myQue.enque( (i+1) * 5 );
  }

  // Check is empty when not empty. 
  std::cout << "If myQue is not empty return 0: " << myQue.isEmpty() << std::endl;
  
  // Print the current queue.
  std::cout << "myQue list is: " << myQue << std::endl;

  // Print the element at the front of the queue.
  std::cout << "The element at the front of myQue: " << myQue.front() << std::endl;

  // Print the element at the back of the queue.
  std::cout << "The element at the end or back of myQue is: " << myQue.back() << std::endl;

  // Use deque to return the element at the front of the queue.
  std::cout << "The element at the front of myQue is: " << myQue.deque() << std::endl;
  
  // Check size when not empty and check that deque removed an element.
  std::cout << "The new number of elements in myQue is: " << myQue.size() << std::endl;

  // Check that deque deleted the first element by printing the queue.
  std::cout << "The new myQue list is: " << myQue << std::endl;
  
  // Insert 100 items into the queue using the normal constructor
  for (int i = 0; i < 100; i++)
  {
    yourQue.enque(i);
  }
  // Check size of your queue.
  std::cout << "The new number of elements in yourQue is: " << yourQue.size() << std::endl;

  system("pause");
  return 0;
} // end main



