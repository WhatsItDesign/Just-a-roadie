#pragma once
// Guard against multiple instance of the same file be compiled and run. 
#ifndef UNORDEREDARRAYLISTTYPE_H
#define UNORDEREDARRAYLISTTYPE_H
#include "arrayListType.h" // Parent of unorderedArrayListType


//-------------------------------------------------------------------------------------------------------CJR
// Name: Christopher Rohde; 
// Adapted from the work of Professor Bin "Crystal" Peng's work HW11_queue_shell.cpp
// Date: 03/01/2019
// Assignment: HW11_unorderedArrayListType_Rohde
// Header file for unorderedArrayListType (child/derived class of arrayListType) 
//-------------------------------------------------------------------------------------------------------CJR


// unorderedArrayListType creates a dynamic array from the arrayListType Parent file.
// and implements files from the abstract parent class. 
class unorderedArrayListType : public arrayListType
{
public:
  void insertAt(int location, int insertItem);
  // Pre: if all locations up to the current location are filled, insert the value of insertItem at the location. 
  // Post: No return value, the unorderedArrayList is updated with the next value and length is incremented. 

  void insertEnd(int insertItem);
  // Pre: If length is less than maxSize insert the item at the next location. 
  // Post: No value is returned. The unorderedArrayList length is incremented and the insertItem is added to the list. 

  void replaceAt(int location, int repItem);
  // Pre: If the unordered list is not empty and the input location is valid. 
  // Post: No value is returned. Overwrite the item at 'location' with the element repItem. The length remains the same and the list is upated. 

  int seqSearch(int searchItem) const;
  // Pre: search for the int argument provided.
  // Post: an int value of the location of the search for item is return. If the list was empty or the value was not found -1 will be returned. 
  
  void remove(int removeItem);
  // Pre: If the list is not empty, search the list for the item. 
  // Post: If the item is found use removeAt from arrayListType, which corrects the empty location and decrements the length of the list. 

  unorderedArrayListType(int size = 100); //Constructor
  // default constructor included size = 100. 
};
#endif // !UNORDEREDARRAYLISTTYPE_H
