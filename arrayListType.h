#pragma once
#include <iostream>
// Class Guard.
#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H


//-------------------------------------------------------------------------------------------------------CJR
// Name: Christopher Rohde; 
// Adapted from the work of Professor Bin "Crystal" Peng's work HW11_queue_shell.cpp
// Date: 03/01/2019
// Assignment: HW11_arrayListType_Rohde
// Header file for arrayListType (super class) 
//-------------------------------------------------------------------------------------------------------CJR


// Class array is an abstract class due to the inclusion of 5 Pure Virtual Functions. 
class arrayListType
{
  friend std::ostream& operator<<(std::ostream&, const arrayListType&);
  // Pre: Non-Member Friend Function, accepts as arguments the reference parameters of type ostream (for the insertion operator) and const arrayListType.
  // Post: Prints out an array list. 

public:
  bool isEmpty() const;
  // Post: Returns a bool of 1 if the list is empty. Otherwise returns 1. 

  bool isFull() const;
  // Post: Returns bool of 1 if the list is full. Otherwise returns 1. 
  
  int listSize() const;
  // Post: Returns the int number of elements in the list. 

  int maxListSize() const;
  // Post: Returns the int maxSize of the list. 

  bool isItemAtEqual(int location, int item) const;
  // Pre: Accepts the arguments int as location, and int as an item to be inserted. 
  // Post: If location is outside of the bounds of the list return false, otherwise check if int item is equal to the item at location and return true/false accordingly. 
  
  void removeAt(int location);
  // Pre: accepts an int for the location in the array. If the list is empty do nothing. 
  // Post: else remove the item from the list and move any elements after the removed item to the 'left' one location. Decrement length. 

  void retrieveAt(int location, int& retItem) const;
  // Pre: Accepts int location and a reference to be reference location. 
  // Post: If the list is not empty copy the value at int location to the location of retItem. retItem value = location value. 

  void clearList();
  // Post: Sets length to 0;

  // The following 5 functions are undefined Pure Virtual Functions. They are not defined in class making the class Abstract. 
  // Pure virtual functions can be identified by the function beginning with the keyword virtual and ending with '= 0;'
  virtual int seqSearch(int searchItem) const = 0;
  virtual void insertAt(int location, int insertItem) = 0;
  virtual void insertEnd(int insertItem) = 0;
  virtual void replaceAt(int location, int repItem) = 0;
  virtual void remove(int removeItem) = 0;

  // arrayListType constructor / default constructor value set to size 100. 
  arrayListType(int size = 100);
  // Pre: Accepts an int argument or no argument. If using the default constructor do not use parentheses. 
  // Post: If int is 0 or less, or if the default constructor is invoked size is set to 100 and array of size 100 is created. 
  //       If an int size argument greater than 0 is set to the size argument input by the user. 

  // arrayListType copy constructor 
  arrayListType(const arrayListType& otherList);
  // Pre: accepts an argument of type arrayListType as a reference parameter.
  // Post: copies the values of referenced list into another list. 

  // arrayListType virtual destructor, due to its virtual nature this makes it unnecessary to create destructors for each derived class. 
  virtual ~arrayListType();

protected:
  int *list;    //array to hold the list elements
  int length;   //length of the list
  int maxSize;  //the maximum size of the list
};
#endif // !ARRAYLISTTYPE_H