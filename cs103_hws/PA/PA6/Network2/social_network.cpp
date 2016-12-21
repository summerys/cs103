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
#include <iomanip>

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
   cout << "7. To find the shortest relational distance" << endl;
   cout << "8. Disjoint sets" << endl;
   cout << "9. Friend Suggestions" << endl;
   cout << "10. Exit the program" << endl;
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
   string user;
         

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

      else if(selection == 7){

         getline(cin, two_users);
         stringstream ss(two_users);
         ss >> first;
         ss >> last;
         user1 = first+ " " + last;
         ss >> first;
         ss >> last;
         user2 = first+ " " + last;

         int idUser1 = 0;
         int idUser2 = 0;

         idUser1 = nw->get_id(user1); 
         idUser2 = nw->get_id(user2);

         vector<int> copy_shortest_path;

        copy_shortest_path = nw->shortest_path(idUser1, idUser2);

        if(copy_shortest_path[0] == -1){
            cout << "None" << endl;
        }

        cout << "Distance: " << copy_shortest_path.size()-1 << endl;

        for(int i = copy_shortest_path.size()-1; i >= 0; i--){
            cout << nw->get_name(copy_shortest_path[i]);
            if(i != 0){
               cout << " -> ";
            }
         } 
         cout << endl;
         copy_shortest_path.clear();
      }

      else if(selection == 8){

          vector<vector<int> > copy_groups;
          copy_groups = nw->groups();

        for(int i= 0; i < copy_groups.size(); i++){
            cout << "Set " << i+1 << " => ";
            for(int j = 0; j < copy_groups[i].size(); j++){
               cout << nw->get_name(copy_groups[i][j]);
                  if(j != 0 ){
                     cout << ", ";
                  } //if
             }//for
             cout << endl << endl;
         }//for

      }//8

      else if(selection == 9){
         getline(cin, user);
         stringstream ss(user);
         ss >> first;
         ss >> last;
         user1 = first+ " " + last;

         int user1_id = 0;
         user1_id = nw->get_id(user1);

         int *score_max = new int;
         *score_max = 0;

         vector<int> copy_suggest_Friends;
         copy_suggest_Friends = nw->suggest_friends(user1_id, *score_max);

         if(copy_suggest_Friends[0] == -1){
            cout << "None" << endl;
         }//if
         else{

               cout << "The suggested friend(s) is/are: " << endl;
               for(int i=0; i < copy_suggest_Friends.size(); i++){
                  cout << setw(25) << left << nw->get_name(copy_suggest_Friends[i])
                  << '\t' << "score: " << *score_max << endl;
               }
         }//else

         delete score_max;
      }//9

      //If user enters othern than number 1-6, loop finishes, exit program. 
      else if(selection != 1 || selection != 2 || selection != 3 || 
         selection != 4 || selection != 5 || selection != 6 || selection != 7 || 
         selection != 8 || selection != 9){

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
      cout << "7. To find the shortest relational distance" << endl;
      cout << "8. Disjoint sets" << endl;
      cout << "9. Friend Suggestions" << endl;
      cout << "10. Exit the program" << endl;
      cout << endl;

      cin >> selection; 
         

   }//while         
   
  delete nw;

  return 0;
}
