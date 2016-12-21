#ifndef NETWORK_H
#define NETWORK_H

#include "user.h"

#include <string>
#include <vector>

class Network {
 public:
  Network();
  ~Network();
  int read_friends(const char *filename);
  int write_friends(const char *filename);
  void add_user(std::string username, int yr, int zipcode);
  int add_connection(std::string name1, std::string name2);
  int remove_connection(std::string name1, std::string name2);
  int get_id(std::string username);
  void print_users();
  void print_friends(std::string call_friend);
  std::vector<User> *getUsers();


 private:
 	// int *max_user = new int[100]; 
   std::vector <User> users;
};


#endif
