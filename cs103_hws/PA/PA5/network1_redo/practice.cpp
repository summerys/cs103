#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main(){

  ifstream inFile("users_new.txt");
  if(inFile.fail()){
    cout << "Invalid file" << endl;
    return -1;
  }//if

  int total;
  inFile >> total;

 for(int i = 0; i < total; i++)
 {
  int id;
  string first_name;
  string last_name;
  string name;
  int year;
  int zip;
  vector<int> fri;
  
	  inFile >> id;
    cout << id << endl;

    inFile >> first_name; 
    inFile >> last_name; 
    name = first_name + " " + last_name;

    inFile >> year;
    inFile >> zip; 

    string junk;  //get rid of \n
    getline(inFile, junk);

    string myline;
    
      getline(inFile, myline);
     
      stringstream ss(myline);
      int buff =0;
      User u(name, id, year, zip);
       while(ss >> buff){
         u.add_friend(buff);
       }

       users.push_back(u);
     // Users()->push_back(u); 

  	
 }//for

 // cout << name << " " << year << " " << zip << endl;

};