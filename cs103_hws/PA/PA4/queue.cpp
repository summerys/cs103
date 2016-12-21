/* 
queue.cpp

Author: Summer Yeonhee Seo 

Short description of this file:

This is a program for BFS algorithm.

To achieve this: 
creating Queue, and implement FIFO(first in first out) method.

FIFO method : add to back / remove from front. 
           neighbors around the current array will be added 
           to the back of the queue, 
           and the very front of the queue is removed the first.
           In this order BFS is achieved.  
*/

#include "queue.h"

// constructor. maxlen must be as large as the total number
// of Locations that will ever be entered into this Queue.
Queue::Queue(int maxlen) {
   contents = new Location[maxlen];
   head = 0;
   tail = 0;
}

// destructor. releases resources. C++ will call it automatically.
Queue::~Queue() {
   delete[] contents;
}

// insert a new Location at the end/back of our list   
void Queue::add_to_back(Location loc) {
   contents[tail] = loc;
   tail++;
}

// return and "remove" the oldest Location not already extracted
Location Queue::remove_from_front() {
   head++;
   return contents[head-1];
}

// is this Queue empty? (did we extract everything added?)
bool Queue::is_empty() {
   return head == tail;
}

