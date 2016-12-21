#include <iostream>
#include "delist.h"

using namespace std;

int main()
{
  DEList list;
  list.push_back(1);
  cout << list.front()<< endl;


  for(int i=0; i < 5; i++){
    list.push_back(10+i);
    cout << list.back() << endl;;
    list.push_front(20+i);
    cout << list.front() << endl;;
  }
  //list.pop_front();

  
return 0; 
}