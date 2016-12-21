/*
network.h and network.cpp is for Network class.

Network class holds 8 different methods. 
1. to read friends from input file and set up the basic network.
2. to write the output to the new input file. 
3. It allows to add new user, 
   add or remove friends connection between existed users, 
   to get Id number of the user, to print users or their friends. 

also contains vector that has User type we created in user.h,
this allows Network to save many users 
(that ccan have values in User class) in vector array. 
*/


#ifndef NETWORK_H
#define NETWORK_H
#include <string>
#include <vector>
#include "user.h"

using namespace std;



class Network{
 public:
  Network();
  ~Network();
  int read_friends(const char *filename);
  int write_friends(const char *filename);
  void add_user(string username, int yr, int zipcode);
  int add_connection(string name1, string name2);
  int remove_connection(string name1, string name2);
  int get_id(string username);
  void print_users();
  void print_friends(string call_friend);

  vector <User> *getUsers();

 private:
  vector <User> users;
};


#endif
