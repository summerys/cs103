#include "delist.h"
#include <cstdlib>
#include <iostream>
using namespace std;

 DEList::DEList(){
    head = NULL;
    tail = NULL; 
 };

 DEList::~DEList(){
    while(head != NULL){
      while(tail != NULL)
      {
        tail = tail->prev;
        delete tail;}
    }
 };

  // returns a Boolean 'true' if the list is empty
  bool DEList::empty(){

    if(head == NULL)
    {
      return true;
    }
    else{
      return false;
    }
  }

  // returns number of items in the list
  int DEList::size(){
    if(head==NULL)
      {return -1;}
    else{
      int ct = 0;

      DEItem *curr = head;

        while(curr->next != NULL)
        {
          ct++;
          curr = curr->next;
        }
      ct++;

      return ct;
    }//else

    
  }
  // returns front item or -1 if empty list
  int DEList::front(){

    if(head == NULL)
    {
      return -1;
    }
    else{
    return head->val;
    }

  }
  // returns back item or -1 if empty list
  int DEList::back(){
     if(head == NULL)
    {
      return- 1 ;
    }
    else{
    return tail->val; 
    }
   

  };
  // Adds a new integer to the front of the list
  void DEList::push_front(int new_val){
   if(head == NULL){ //creating new DEItem
      DEItem *newDEItem = new DEItem;
      head = newDEItem;
      tail = head;
      head->val = new_val; 

    }
    else{
      DEItem *newDEItem = new DEItem; 
      head->prev = newDEItem;
      newDEItem->next = head;
      head = newDEItem;
      head->val = new_val;
    }

  }
  
  // Adds a new integer to the back of the list
  void DEList::push_back(int new_val){
   if(head == NULL){ //creating new DEItem
    DEItem *newDEItem = new DEItem;
    head = newDEItem;
    tail = head;
    tail->val = new_val; 
   }
   else{
     DEItem *newDEItem = new DEItem;
     tail-> next = newDEItem;
     newDEItem->prev = tail;
     tail = newDEItem;
     tail->val = new_val;
    }
   }

 
  // Removes the front item of the list (if it exists)
  void DEList::pop_front(){
   if(head == NULL){
      return;
    }
    else if(head == tail)
    {
      DEItem firstDEItem;
      firstDEItem.next = head;
      head = NULL;
      tail = NULL;
      delete firstDEItem.next;
    }
    else{
      DEItem firstDEItem;
      firstDEItem.next = head;
      head = head->next;
      delete firstDEItem.next;
    }
  }
  // Removes the back item of the list (if it exists)
  void DEList::pop_back(){
    if(head == NULL){
      return;
    }
    else if(head == tail)
    {
      DEItem lastDEItem;
      lastDEItem.prev = tail;
      tail = NULL;
      head = NULL;
      delete lastDEItem.prev;
    }
    else{
      DEItem lastDEItem;
      lastDEItem.prev = tail;
      tail = tail->prev;
      delete lastDEItem.prev;
}
  }

