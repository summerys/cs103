

#include "user.h"
#include <string>


using namespace std;

User::User(string name_full, int id_num, int year_born, int zipcode){
   name = name_full;
   id = id_num;
   year = year_born;
   zip = zipcode;
   depth = 0;
   predecessorID = -1;
   suggestion_score = 0;
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

int User::depthInc(){
   return depth++;
}

int User::return_depth(){
   return depth;
}

void User::setPredecessor(int preID){
   predecessorID = preID;
}

int User::returnPredecessor(){
   return predecessorID;
}

void User::setdepth(int depth1){
   depth = depth1;
}

void User::set_suggestion_score(){
   suggestion_score++;
}

int User::return_suggestion_score(){
   return suggestion_score;
}

void User::access_suggestion_score(){
   suggestion_score = 0;
}