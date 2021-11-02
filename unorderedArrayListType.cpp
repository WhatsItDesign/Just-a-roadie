#pragma
#include <iostream>
#include "arrayListType.h"
#include "unorderedArrayListType.h"


//-------------------------------------------------------------------------------------------------------CJR
// Name: Christopher Rohde; 
// Adapted from the work of Professor Bin "Crystal" Peng's work HW11_queue_shell.cpp
// Date: 03/01/2019
// Assignment: HW11_unorderedArrayListType_Rohde
// Implementation file for unorderedArrayListType (child/derived class of arrayListType)
//-------------------------------------------------------------------------------------------------------CJR


  // Pre: if all locations up to the current location are filled, insert the value of insertItem at the location. 
  // Post: No return value, the unorderedArrayList is updated with the next value and length is incremented. 
void unorderedArrayListType::insertAt(int location,
  int insertItem)
{
  if (location < 0 || location >= maxSize)
    std::cout << "The position of the item to be inserted "
    << "is out of range.\n";
  else if (length >= maxSize)  //list is full
    std::cout << "Cannot insert in a full list\n";
  else
  {
    for (int i = length; i > location; i--)
      list[i] = list[i - 1];  //move the elements down

    list[location] = insertItem; //insert the item at
    //the specified position

    length++; //increment the length
  }
} //end insertAt


  // Pre: If length is less than maxSize insert the item at the next location. 
  // Post: No value is returned. The unorderedArrayList length is incremented and the insertItem is added to the list. 
void unorderedArrayListType::insertEnd(int insertItem)
{
  if (length >= maxSize)  //the list is full
    std::cout << "Cannot insert in a full list.\n";
  else
  {
    list[length] = insertItem; //insert the item at the end
    length++; //increment the length
  }
} //end insertEnd


  // Pre: search for the int argument provided.
  // Post: an int value of the location of the search for item is return. If the list was empty or the value was not found -1 will be returned. 
int unorderedArrayListType::seqSearch(int searchItem) const
{
  for (int loc = 0; loc < length; loc++)
    if (list[loc] == searchItem)
      return loc;

  return -1; // not found
} //end seqSearch


  // Pre: If the list is not empty, search the list for the item. 
  // Post: If the item is found use removeAt from arrayListType, which corrects the empty location and decrements the length of the list. 
void unorderedArrayListType::remove(int removeItem)
{
  if (length == 0)
    std::cout << "Cannot delete from an empty list.\n";
  else
  {
    int loc = seqSearch(removeItem);

    if (loc != -1)
      removeAt(loc);
    else
      std::cout << "The item to be deleted is not in the list\n.";
  }
} //end remove


  // Pre: If the unordered list is not empty and the input location is valid. 
  // Post: No value is returned. Overwrite the item at 'location' with the element repItem. The length remains the same and the list is upated. 
void unorderedArrayListType::replaceAt(int location, int repItem)
{
  if (location < 0 || location >= length)
    std::cout << "The location of the item to be "
    << "replaced is out of range.\n";
  else
    list[location] = repItem;
} //end replaceAt

  // constructs unorderedArrayList with parameter input of int size
  // default construction is of int size 100, no argument is necessary for the default constructor. 
unorderedArrayListType::unorderedArrayListType(int size)
  : arrayListType(size)
{
  //std::cout << "constructor of unorderedalt: " << this << "\n"; // testing
}  //end constructor


