
#include "network.h"
#include <sstream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

//accept the file from main function in social_network.cpp
//and initialize the networl's information from a file. 
int Network::read_friends(const char *filename)
{
  ifstream inFile;
  inFile.open(filename);
  if(inFile.fail()){
    cout << "Invalid file" << endl;
    return -1;
  }//if

  string s;
  string s_;
  string s__;
  int total; 
  string name;
  string first_name;
  string last_name;
  int id;
  int year;
  int zip;
  string line;
  string tap;
  string friends;

  inFile >> total; 

  for(int i = 0; i < total; i++)
  {
	inFile >> id;

  	getline(inFile, line) >> s;
  	stringstream ss(s);
  	ss >> ta
  	ss >> first_name;
  	ss >> last_name;

  	name = first_name + " " + last_name;

  	getline(inFile, line) >> s_;
  	stringstream ss(s_);
  	ss >> tap;
  	ss >> year;

  	getline(inFile, line) >> s__;
  	stringstream ss(s__);
  	ss >> tap;
  	ss >> zip;

  	getline(inFile, line) >> friends; 

  	User u(name, id, year, zip, friends); 
  	getUsers()->push_back(u); 

  	
  }//for

  inFile.close(); 

  return 0; // success
}

int Network::write_friends(const char *filename){

	ofstream outFile(*filename);
	outFile << users.size() << endl;
	for(int i=0; i < users.size(); i++){
		
		outFile << users[i].id_num() << endl;
		outFile << '\t' << users[i].name_full() << endl;
		outFile << '\t' << users[i].year_born() << endl;
		outFile << '\t' << users[i].zipcode() << endl;
		outFile << '\t' << users[i].getfriends() << endl; 
	}

	outFile.close();
}
;

void Network::add_user(std::string username, int yr, int zipcode)
{
	int id_next = users.size();

	User add(username, id_next, yr, zipcode); 
	users.puch_back(add);
}

int Network::add_connection(std::string name1, std::string name2){

	for(int i=0; i < users.size(); i++){
		for(int j=0; j < users.size(); j++){

			if(users[i].name_full() == "name1"){
				users[i].add_friend(users[j].id_num());
		}//for
			}//if
	}//for
}//int


int Network::remove_connection(std::string name1, std::string name2){

	for(int i=0; i < users.size(); i++){
		for(int j=0; j < users.size(); j++)
		{
			if(users[i].name_full() == "name1";){
				if(users[j].name_full() == "name2";){
				users[i].delete_friend(users[j].id_num());
				}//if
			}//if
		}
	}
}//int

//accept 2 user and delete their connection ... 

int Network::get_id(std::string username)
//accept a user name and return the corresponding id. 
{
	for(int i=0; i < getUsers()->size(); i++)
	{
		if(users[i].name_full() == username){
			return users[i].id_num();
		}
	}

	return -1;
}

void Network::print_users(){

	cout << "ID" << '\t' << "Name" << '\t' << '\t' << "Year" << '\t' << "Zip" << endl;
	cout << "================================================================="<< endl;
	for(int i=0; i < users.size(); i++){
		cout << i << ".";
		cout << setw(10);
		cout << users[i].name_full();
		cout << setw(17);
		cout << users[i].year_born();
		cout << setw(18);
		cout << users[i].zipcode() << endl;
	}//for
}//void

void Network::print_friends(std::string call_friend){

	for(int i = 0; i < users.size(); i++)
	{
		if(users[i].name_full() == call_friend)
		{
 			users[i].returningVectorContents();
		}//if
	}//for

	cout << "ID" << '\t' << "Name" << '\t' << '\t' << "Year" << '\t' << "Zip" << endl;
	cout << "================================================================="<< endl;
	for(int i=0; i < ids.size(); i++){
		for(int j=0; j < users.size(); j++){
			if(ids[i] == users[j].id_num()){
				cout << users[i].id_num() << ".";
				cout << setw(10);
				cout << users[i].name_full();
				cout << setw(17);
				cout << users[i].year_born();
				cout << setw(18);
				cout << users[i].zipcode() << endl;
			}//if
		}//for
	}//for

}//void


}
vector<User> * Network::getUsers() {
	return &users;
}