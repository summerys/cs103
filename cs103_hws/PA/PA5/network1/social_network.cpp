/*

This program is mock social networking program that does ...

1) Create the basic network based on accepts the output file. 
2) User can choose between 7 given seletions to build social network 
	- 1) Add user, 2) Add friend connection 3) Remove friend connection 4) Print users
	  5) List friends 6) Write to file 7) Exit the program. 
3) Print the result as a new file. 

*/
#include "network.h"
#include "user.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{

  Network * nw = new Network();

  nw->read_friends(&argv[1]); //reading the give file and initialize the networ;s information from a file. 
  //FINISHING SETTING UP THE INITIALIZED NETWORK 
  //Modifying the network by letting user to choose from 
  //following options.

	cout << "Please select from the following options by entering the corresponding number:" << endl;
	cout << "1. Add a user" << endl;
	cout << "2. Add friend connection" << endl;
	cout << "3. Remove friend connection" << endl;
	cout << "4. Print users" << endl;
	cout << "5. List friends" << endl;
	cout << "6. Write to file" << endl;
	cout << "7. Exit the program" << endl;
	cout << "Please make your selection (enter 1, 2, 3, 4, 5, 6 or 7): " << endl;

	int selection;
	cin >> selection;

	string first_name;
	string last_name;
	string full_name;
	string calling_friends;
	int birth_year = 0;
	int zip_code =0;
	bool end = false;
	string first;
	string last;
	string user1;
	string user2;
	string two_users;
	    	


	//loop continues until end is false. 
	while(end == true){

	    if(selection == 1){

	    	//cout << "Please enter first and last name, birth year, and zip code in order by giving space in between" << endl;
	    	cin >> first_name;
			cin >> last_name;
			full_name = first_name + " " + last_name;
	    	cin >> birth_year; 
	    	cin >> zip_code;

	    	nw->add_user(full_name, birth_year, zip_code);  // from network.h

	    }//if
	    else if(selection == 2){

	    	//cout << "Please enter two user names(first and last name in order just spaces between each names)" << endl;
	    	getline(cin, two_users);
	    	stringstream ss(two_users);
			ss >> first;
			ss >> last;
			user1 = first+ " " + last;
			ss >> first;
			ss >> last;
			user2 = first+ " " + last;

	    	for(int i=0; i < nw->getUsers().size(); i++)
	    	{
	    		for(int j=0; j < nw->getUsers().size(); j++)
	    		{
	    			if(nw->getUsers().at(i).name_full() == user1){
	    				if(nw->getUsers()[j].name_full() == user2){
	    					nw->add_connection(user1, user2);
	    				}//if
	    				else{
	    					cout << "User name does not exist." << endl;
		    				break;
	    				}//else
	    			}//if
	    		}//for
	    	}//for
	    	
	    }//selection 2 


	    else if(selection == 3){
	    
			//cout << "Please enter two user names(first and last name in order just spaces between each names)" << endl;
	    	getline(cin, two_users);
	    	stringstream ss(two_users);
			ss >> first;
			ss >> last;
			user1 = first+ " " + last;
			ss >> first;
			ss >> last;
			user2 = first+ " " + last;

			for(int i=0; i < nw->getUsers()->size(); i++)
	    	{
	    		for(int j=0; j < nw->getUsers()->size(); j++)
	    		{
	    			if(nw->getUsers()[i]->name_full() == user1){
	    				if(nw->getUsers()[j]->name_full() == user2){
	    					nw->remove_connection(user1, user2);
	    				}//if
	    				else{
	    					cout << "User name does not exist." << endl;
		    				break;
	    				}//else
	    			}//if
	    		}//for
	    	}//for

	    }//selection 3

	    else if(selection == 4){
	    	nw->print_users();
	    }//selection4

	    else if(selection == 5){

	    	bool notexist = false;

	    	//cout << "please enter user name: " << endl;
	    	string calling_friends;
	    	getline(cin, calling_friends);

	    	for(int i=0; i < nw->getUsers()->size(); i++)
	    	{
	    		if(nw->getUsers()[i]->name_full() == calling_friends){
	    			nw->print_friends(calling_friends);
	    			notexist = false;
	    			break;
	    		}//if
	    		if(nw->getUsers()[i]->name_full() != calling_friends){
	    			notexist = true;
	    		}//if
	    	}//for
		    	if(notexist == true){
		    		cout << "User name does not exist." << endl;
		    	}//if
	    		
	    }//selection5

	    else if(selection == 6){

	    	string temp;
	    	cin >> temp;
	    	
	    	nw->write_friends(temp.c_str()); //need to find the way to print out in order. 
	    }//selection 6 

	    else{
	    	end = false; //if user enters other than number 1-6, 
						 //loop finishes. 
	    }//else

	    cout << "Please make your selection (enter 1, 2, 3, 4, 5, 6 or 7):" << endl;
		cin >> selection; 

	}//while			
	
  delete nw;


  return 0;
}
