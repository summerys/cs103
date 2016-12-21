/*
user.h & user.cpp is for User class.
Each user holds 5 different information. 

1. Name
2. Id
3. Year
4. Zip code
5. Friends' ID

These information are private value, 
can be accessed through getter functions. 

add_friend and delete_friend controls 
Users connection with others. 

*/


#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

using namespace std;

class User {
 public:
       User(string name_full, int id_num, int year_born, int zipcode);
       ~User();

      void add_friend(int other_user);  
       void delete_friend(int other_user_d); 

       //getter functions 
       //this allows users can have an access to 
       //seperate values in private. 
       int id_num();
       string name_full();
       int year_born();
       int zipcode();
       vector <int> getFriends(); 

 private:
       string name; 
       int id; 
       int year;
       int zip;
       vector<int> friends;
};


#endif
