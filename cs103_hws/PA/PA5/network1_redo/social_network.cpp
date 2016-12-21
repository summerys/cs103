/*

Name: Summer Seo 
E-mail : summerys@usc.edu

This program is mock social networking program that does followings

1) Create the basic network based on accepted output file. 
2) User can choose between 7 given seletions to build social network 
   
   such as: 

   - 1) Add user, 2) Add friend connection 
   3) Remove friend connection 4) Print users
    5) List friends 6) Write to file 7) Exit the program. 

3) Print the result into a new file. 

***Social network calls functions network.h and user.h***

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

   nw->read_friends(argv[1]);


   cout << "Please select from the following options: " << endl;
   cout << "1. Add a user" << endl;
   cout << "2. Add friend connection" << endl;
   cout << "3. Remove friend connection" << endl;
   cout << "4. Print users" << endl;
   cout << "5. List friends" << endl;
   cout << "6. Write to file" << endl;
   cout << "7. Exit the program" << endl;
   cout << endl;

   int selection;
   cin >> selection;

   string first_name;
   string last_name;
   string full_name;
   string calling_friends;
   int birth_year = 0;
   int zip_code =0;
   bool end = true;
   string first;
   string last;
   string user1;
   string user2;
   string two_users;
         

   //loop continues until end is false. 
   while(end == true){

      //1. Adding new users 
      if(selection == 1){

         cin >> first_name;
         cin >> last_name;
         full_name = first_name + " " + last_name;
         cin >> birth_year; 
         cin >> zip_code;

         nw->add_user(full_name, birth_year, zip_code);  // from network.h
      }//selestion 1

      //2. Add connections between two entered users 
      else if(selection == 2){

         getline(cin, two_users);
         stringstream ss(two_users);
         ss >> first;
         ss >> last;
         user1 = first+ " " + last;
         ss >> first;
         ss >> last;
         user2 = first+ " " + last;

    
         nw->add_connection(user1, user2);
      }//selection 2 

      //3. Remove friends connections between two users
      else if(selection == 3){
      
         getline(cin, two_users);
         stringstream ss(two_users);
         ss >> first;
         ss >> last;
         user1 = first+ " " + last;
         ss >> first;
         ss >> last;
         user2 = first+ " " + last;


         nw->remove_connection(user1, user2);
      }//selection 3

      //4. Print Users
      else if(selection == 4){
         nw->print_users();
      }//selection4

      //5. List friends 
      else if(selection == 5){

         getline(cin, calling_friends);
         stringstream ss(calling_friends);
         ss >> first;
         ss >> last;
         calling_friends = first + " " + last;

         nw->print_friends(calling_friends);
               
      }//selection5

      //6. Write friends on the list on the received file. 
      else if(selection == 6){

         string temp;
         cin >> temp;
         
         nw->write_friends(temp.c_str()); 

      }//selection 6 

      //If user enters othern than number 1-6, loop finishes, exit program. 
      else if(selection != 1 || selection != 2 || selection != 3 || 
         selection != 4 || selection != 5 || selection != 6  ){

         cout << "Bye!" << endl; 
         break; 
      }//

      cout << endl;
      cout << "Please select from the following options: " << endl;
      cout << "1. Add a user" << endl;
      cout << "2. Add friend connection" << endl;
      cout << "3. Remove friend connection" << endl;
      cout << "4. Print users" << endl;
      cout << "5. List friends" << endl;
      cout << "6. Write to file" << endl;
      cout << "7. Exit the program" << endl;
      cout << endl;

      cin >> selection; 

   }//while         
   
  delete nw;

  return 0;
}
