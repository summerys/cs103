#ifndef USER_H
#define USER_H

#include <string> 
#include <vector>

using namespace std;


class User {
 public:
 		User(string name_full_, int id_num_, int year_born_, int zipcode_, string friends_);
 		//vector<int>*friends = vector<int>*friends_id; //
 		~User();
		void add_friend(int other_user);  //accepting the ID of a user to add as a friend 
 						  //if the indicated user is already a friend of this user,
 		// do nothing

 		//for having 100 arrays => use dynamic allocation * <new> 
 		void delete_friend(int other_user_d); // accepting the ID of a user to delete as a friend
 		//if the friend list is implemented as a vector / array, then that ID should be 
 		//'removed' and all following friend ID's moved up one slot. 
 		//if the friend ID provided is not in the list of friends, do nothing. 

 		//setting 3funtions
 		//getting functions 

 		//getting 
 		int id_num();
 		string name_full();
 		int year_born();
 		int zipcode();
 		void returningVectorContents();

 		vector <int> *getFriends(); //will be used as users[].getfriends();


 private:
 		std::string name; 
 		int id; 
 		int year;
 		int zip;
 		vector<int> friends;
 		//vector<int>*friends = vector<int> friends_id;
};


#endif
