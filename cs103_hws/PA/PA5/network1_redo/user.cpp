

#include "user.h"
#include <string>


using namespace std;

User::User(string name_full, int id_num, int year_born, int zipcode){
   name = name_full;
   id = id_num;
   year = year_born;
   zip = zipcode;
}

User::~User(){};

void User::add_friend(int other_user){

for (int i = 0; i < friends.size(); ++i){
   if (friends[i] == other_user) {
       return;
   }
}//for
   friends.push_back(other_user);
   
}//add_friend


void User::delete_friend(int other_user_d){
   
   for(int i=0; i < friends.size(); i++){
      if(friends[i] == other_user_d){

         friends.erase ( friends.begin() + i );

      }//if
   }//for   
}//void

int User::id_num(){
   return id;
}

string User::name_full(){
   return name;
}

int User::year_born(){
   return year;;
}

int User::zipcode(){
   return zip;
}

//accessor 
vector<int>  User::getFriends(){
   return friends;
}
