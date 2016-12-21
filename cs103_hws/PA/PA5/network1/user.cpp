#include "user.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

User::User(string name_full_, int id_num_, int year_born_, int zipcode_, string friends_){
	name = name_full_;
	id = id_num_;
	year = year_born_;
	zip = zipcode_;

	int ignore;
	int id_;
	stringstream ss(friends_);
	ss >> ignore;
	ss >> id_;
	friends.push_back(id_);
}

User::~User(){};

void User::add_friend(int other_user){

	getFriends()->push_back(other_user);
};//void

void User::delete_friend(int other_user_d){
	
	for(int i=0; getFriends()->size(); i++){
		if((*getFriends())[1] == other_user_d){
			getFriends()->erase(getFriends()->begin()+i);
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

void User::returningVectorContents(){
	int *ids = new int [friends.size()];
	for(unsigned int i=0; i < friends.size(); i++)
	{
		ids[i] = friends[i];
	}
}

//accessor 
vector<int> * User::getFriends(){
	return &friends;
}

