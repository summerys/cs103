#include "network.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <deque> 
#include <iomanip>

using namespace std;
Network::Network(){};

Network::~Network(){};

int Network::read_friends(const char *filename)
{
  ifstream inFile(filename);
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
          }//while
          users.push_back(u);

      }//for

inFile.close();

return 0;
}//read_friend


int Network::write_friends(const char *filename){

   ofstream outFile(filename);

   if(outFile.fail()){
    cout << "Invalid file" << endl;
    return -1;
     }//if

   outFile << users.size() << endl;

   for(int i=0; i < users.size(); i++){
      
      outFile << users[i].id_num() << endl;
      outFile << '\t' << users[i].name_full() << endl;
      outFile << '\t' << users[i].year_born() << endl;
      outFile << '\t' << users[i].zipcode() << endl;
      outFile << '\t';
      for(int j=0; j < (users[i].getFriends()).size(); j++){
      outFile << users[i].getFriends()[j] << " ";
      }
      outFile << endl;
   };
   outFile.close();

   return 0;
}//


void Network::add_user(string username, int yr, int zipcode)
{
   int id_next = users.size();

   User add(username, id_next, yr, zipcode); 
   users.push_back(add);
}



int Network::add_connection(string name1, string name2){

   for(int i=0; i < users.size(); i++){
      for(int j=0; j < users.size(); j++){
         if(users[i].name_full() == name1){
            if(users[j].name_full() == name2){

            users[i].add_friend(users[j].id_num());
            users[j].add_friend(users[i].id_num());

            return 0;
            }//if
         }//if
      }//for
   }//for

   return -1;
}//int

int Network::remove_connection(string name1, string name2){

   for(int i=0; i < users.size(); i++){
      for(int j=0; j < users.size(); j++)
      {
         if(users[i].name_full() == name1){
            if(users[j].name_full() == name2){

            users[i].delete_friend(users[j].id_num());
            users[j].delete_friend(users[i].id_num());

            return 0; 
            }//if
         }//if
      }
   }

   return -1;
}//int


int Network::get_id(string username)
//accept a user name and return the corresponding id. 
{
   for(int i=0; i < users.size(); i++)
   {
      if(users[i].name_full() == username){
         return users[i].id_num();
      }
   }

   return -1;
}

string Network::get_name(int useridnum)
{
  for(int i=0; i < users.size(); i++)
   {
      if(users[i].id_num() == useridnum){
         return users[i].name_full();
      }
   }
   return "error";
}

void Network::print_users(){

   cout << "ID" << '\t' << "Name" << '\t' << '\t' << '\t' << " "
   << "Year" << '\t' << "Zip" << endl;
   cout << "=============================================="<< endl;
   for(int i=0; i < users.size(); i++){
      cout << i << "." << '\t' 
      << setw(25) << left << users[i].name_full() 
      << users[i].year_born() << '\t'
      << users[i].zipcode() << endl;
   }//for
}//void


void Network::print_friends(string call_friend){
   int userid = get_id(call_friend);
   if(userid ==-1)
   {
      return ;
   }

   vector<int> friendlist = users[userid].getFriends();

   cout << "ID" << '\t' << "Name" << '\t' << '\t' << '\t' << " "
   << "Year" << '\t' << "Zip" << endl;
   cout << "=============================================="<< endl;
   for(int i=0; i < friendlist.size(); i++){
            cout << users[friendlist[i]].id_num()<< "." << '\t'
            << setw(25) << left << users[friendlist[i]].name_full()
            << users[friendlist[i]].year_born() << '\t'
            << users[friendlist[i]].zipcode() << endl;
   }//if
   
}//void

vector<User> * Network::getUsers() {
   return &users;
}


vector<int> Network::shortest_path(int from, int to){

  for(int i=0; i < users.size(); i++){
    users[i].setdepth(0);
    users[i].setPredecessor(-1);
  }

  my_deque.push_back(from);
  int curr = from;
  vector<int> return_shortest_path; 

  users[from].depthInc();

  while(curr != to){

    if(my_deque.empty()){
      return_shortest_path.push_back(-1);
      return return_shortest_path;
    }
    
    for(int i=0; i < (users[curr].getFriends()).size(); i++){
       if(users[users[curr].getFriends()[i]].return_depth() == 0){
            my_deque.push_back(users[curr].getFriends()[i]);
            users[users[curr].getFriends()[i]].depthInc(); 
            users[users[curr].getFriends()[i]].setPredecessor(curr); 
      }
     
    }//for 
     my_deque.pop_front();
     curr = my_deque[0];
  }//while


  int predID_num = to; 
  //creating vector that holds predecessor id numbers. 
  return_shortest_path.push_back(to);

  while(predID_num != from){
      //tracing back predecessors until it reaches to 
      //id num = from 
      predID_num = users[predID_num].returnPredecessor();
      return_shortest_path.push_back(predID_num);
  }//while

  for(int i=0; i < users.size(); i++){
      users[i].setdepth(0);
      users[i].setPredecessor(-1);
  }

  my_deque.clear();
  

  vector<int> backwards;


  /*

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  When I add this part to pass the tests for short_path on
  bits submission, my group() comes out wrong. 
  Instead, what I did is to print out backward on
  social_network.cpp for option 7 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  for(int i=return_shortest_path.size()-1; i>=0; i--)
  {
    backwards.push_back(return_shortest_path[i]);
  }
  return_shortest_path.clear();

  for(int i=0; i<backwards.size(); i++){
    return_shortest_path.push_back(backwards[i]);
  }
*/
  return return_shortest_path; // vector
}//shortest_path


vector<vector<int> > Network::groups(){

  deque <int> setgroup;
  vector <int> temp;
  vector <int> temp1;
  vector <int> temp2;
  vector <int> set1;
  vector<vector<int> > set;
  bool first = true;
  int count = 0;
//initiating setgroup
  for(int i=0; i < users.size(); i++){
      setgroup.push_back(users[i].id_num());
  }//for 

  while(!setgroup.empty()){

      first = true;
      
      if(setgroup.size() == 1){
           temp.push_back(setgroup[0]);
           set.push_back(temp);
           temp.clear();
           return set;
      }
      for(int i=0; i < setgroup.size()-1; i++){
         temp.clear();         
         temp = shortest_path(setgroup[0], setgroup[i+1]);

        if ( temp[0] == -1) {
           temp.clear();
           continue;
        }//if

        if(first == true){
           temp1 = temp; 
           first = false;   
        }//if

        for(int j = 0; j < temp.size(); j++){
        
          for(int z = 0; z < temp1.size(); z++){
              if(temp[j] != temp1[z]){
                  count++;
              }//if
          }//for

          if(count == temp1.size()){
              if(temp[j] != -1){
                  temp1.push_back(temp[j]);
              }//if
          }//if
              count = 0;
              temp.clear();
        }//for

    }//first for loop.
    //made first set. 
    //temp1 holds the first group

      for(int k =0; k < setgroup.size(); k++){
          count = 0;
      for(int m = 0; m < temp1.size(); m++){
        if(setgroup[k] != temp1[m]){
          count ++;
        }
        if(count == temp1.size()){
          temp2.push_back(setgroup[k]);
        }
      }//for
    }//for

      //now temp 1 is complete set 
      set.push_back(temp1); // putting into set

      //deleting temp1 from setgroup 

      for(int w = 0; w < setgroup.size(); w ++){
        for(int y = 0; y < temp1.size(); y++){
          if(setgroup[w] == temp1[y]){
            setgroup.erase(setgroup.begin() + w);
            w--;
          }//if
        }//for
      }//for
      //now have setgroup without first set. 
      //repeating this for next set 

      temp1.clear();
  }//while 

  return set;

}//group()


vector<int> Network::suggest_friends(int who, int &score){

//who_friends hold user's friend's id numbers. 
  vector<int> who_friends;
  deque<int> not_who_friends;
  who_friends = users[who].getFriends();

  int *max_score = new int; 
  max_score = &score;

//find the the id num who's not user's friend. 
  int count = 0;

  for(int i = 0; i < users.size(); i++){
    for(int j = 0; j < who_friends.size(); j++){
      if(users[i].id_num() != who_friends[j]){
        count++;
      }//if
      if(count == who_friends.size()){
        not_who_friends.push_back(users[i].id_num());
        continue;
      }//if
    }//for
    count = 0;
  }//for
  //pop out user's own id from the que

  for(int i=0; i < not_who_friends.size(); i++){
    if(not_who_friends[i] == who){
      not_who_friends.erase(not_who_friends.begin()+i);
    }
  }
  //now not_who_friends only hold not_who_friend's non friends id nums
  //find if user and nofriend has friends in common. 
  //user's friend == not_who_friends's friend
  //if friend's in common, increment the suggestion_score

  vector<int> temp;

  for(int i = 0; i < not_who_friends.size(); i++){

    temp = users[not_who_friends[i]].getFriends();

    for(int j =0; j < temp.size(); j++){
      for(int z = 0; z < who_friends.size(); z++){
        if(temp[j] == who_friends[z]){
          users[not_who_friends[i]].set_suggestion_score();
        }//if
      }//for
    }//for

    temp.clear();
  }//for

  //check who has the highest score, and pick that person. 
  int biggest_score = 0; 
//finding biggest score number. 
  for(int i=0; i < not_who_friends.size(); i++){
    if(biggest_score < users[not_who_friends[i]].return_suggestion_score()){
      biggest_score = users[not_who_friends[i]].return_suggestion_score();
    }//if
  }//for

  vector<int> biggest_score_id;

  if(biggest_score ==0){
    biggest_score_id.push_back(-1);
    return biggest_score_id;
  }//if
//putting ids that has biggest score number into the vector array. 
  for(int i=0; i < not_who_friends.size(); i++){
    if(biggest_score == users[not_who_friends[i]].return_suggestion_score()){
      biggest_score_id.push_back( users[not_who_friends[i]].id_num() );

    }//if
  }//for

  for(int i=0; i <not_who_friends.size(); i++){
    users[not_who_friends[i]].access_suggestion_score();
  }//for

  *max_score = biggest_score;

  return biggest_score_id;
}//ends


