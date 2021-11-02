#pragma
#include <iostream> // for ostream insertion operator<< function 
#include "arrayListType.h" // Grandparent of queue class
#include "unorderedArrayListType.h" // Parent of queue class
#include "queue_Rohde.h" // queue class header file


//-------------------------------------------------------------------------------------------------------CJR
// Name: Christopher Rohde
// Date: 03/01/2019
// Assignment: Implementation for queue class for HW11 (grandchild of arrayListType, child of unorderedArrayListType)
//-------------------------------------------------------------------------------------------------------CJR


// Pre: No input argument, standard syntax is myQue.isEmpty();
// Post: Returns 0 if queue is empty, returns 1 if queue is not empty.
bool queue::isEmpty() const
{
  // checks if the queue is empty, if it is returns 0.
  bool emptyChk = arrayListType::isEmpty();
  return emptyChk;
} // end of isEmpty
//-------------------------------------------------------------------------------------------------------CJR


// Pre: No input argument, standard syntax is myQue.size();
// Post: Returns the number of element contain by the queue.
int queue::size() const
{
  // creates an int cueSize sets the value to that returned by listSize from the arrayListType class.
  int cueSize = arrayListType::listSize();
  // returns the current size of the queue.
  return cueSize;
} // end of size
//-------------------------------------------------------------------------------------------------------CJR


// Pre: queue may not be empty. 
// Post: Returns the value at the front (0 location) of the queue if the queue is not empty.
int queue::front() const
{
  if (!isEmpty()) // first check if the list is empty (using the queue isEmpty function).
  {
    int *temp = new int; // creates a new int pointer to store the value retrieved from the location.
    int front;
    arrayListType::retrieveAt(0, *temp); // retrieves the value at the front of the queue this should be the 'oldest' value in the queue. 
    front = *temp;  // store th
    delete temp;    // delete the temp pointer
    return front;   // return the value. 
  }
  else 
  {
    std::cout << "Queue is empty a value of -1 is returned." << std::endl; // the queue is empty
    return -1; // return -1 if the queue is empty. 
  }
} // end of front
//-------------------------------------------------------------------------------------------------------CJR


// Pre: The queue must not be empty 
// Post: Returns the youngest or last item in the queue from the 'back' of the queue. 
int queue::back() const
{
  if (!isEmpty()) // first check if the list is empty (using the queue isEmpty function).
  {
    int *temp = new int; // creates a new int pointer to store the value retrieved from the location.
    int tempSize = size() - 1;
    int back;
    arrayListType::retrieveAt(tempSize, *temp); // retrieves the value at the front of the queue this should be the 'oldest' value in the queue. 
    back = *temp; // store the value in an int var
    delete temp;  // delete the temp pointer.
    return back;  // return the value. 
  }
  else
  {
    std::cout << "Queue is empty a value of -1 is returned." << std::endl; // the queue is empty
    return -1; // return -1 if the queue is empty. 
  }
} // end of back
//-------------------------------------------------------------------------------------------------------CJR


// Pre: Accepts one integer argument which will be inserted at the first open location(back of the queue) in the queue. 
// Post: No return condition, the queue should have an additional item stored at the back of the queue.
void queue::enque(int newItem)
{
  // inserts the next item at the back or the end of the queue using the unorderedArrayListType function insertEnd.
  unorderedArrayListType::insertEnd(newItem); 
} // end of enque
//-------------------------------------------------------------------------------------------------------CJR


// Pre: If the queue is not empty 
// Post: Remove and return the front/oldest element. 
int queue::deque()
{
  if (!isEmpty()) // check if the queue is empty cannot remove if there are no elements. 
  {
    int currentItem = front();  // get the current element because removeAt is a void function. 
    arrayListType::removeAt(0); // remove the front element. 
    return currentItem;         // return the element removed. 
  }
  else                          // The queue is empty
  {
    // inform user the queue is empty and return minus one. 
    std::cout << "Queue is empty -1 has been returned" << std::endl;
    return -1;
  }
} // end of deque
//-------------------------------------------------------------------------------------------------------CJR


// Pre: Accepts an integer input greater than 0 otherwise a queue of size 100 is used. 
// Post: Returns a queue object.
queue::queue(int size) :unorderedArrayListType(size)
{
  // std::cout << "Queue has been constructed " << this << "\n"; // testing queue construction
} // end of queue constructor/default constructor
//-------------------------------------------------------------------------------------------------------CJR


// Pre: Accepts input reference parameter from ostream class and one const reference parameter from queue.
// Post: Facilitates the use of the insertion operator "<<" and a queue object, returns out in the form similar to a java arrayList
//       a call such as 'std::cout << myQueue' would result similarly to: [1, 2, 3, 4].
std::ostream& operator<<(std::ostream& out, const queue& obj)
{
  int *temp = new int; // Create new int pointer temp to store the value from retrieveAT
  out << "["; 
  for (int i = 0; i < obj.size(); i++) // iterate through the queue
  {
   obj.retrieveAt(i, *temp);   // get element at the current location and store the location value at temp's location. 

   if (i < obj.size() - 1)     // if the last element has not been reached add a comma. 
     out << *temp << ", ";     
   else                        // of the last element has been reached add a brace ']'
     out << *temp << "]";       
   
  }
  delete temp; // delete the temp pointer. 
  return out;
} //end operator<<
//-------------------------------------------------------------------------------------------------------CJR
