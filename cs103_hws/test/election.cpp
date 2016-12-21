/**
 *  File: election.cpp
 *  Name: _Summer Yeonhee Seo____
 *  Email: ___summerys___@usc.edu
 *
 *  Description:
 *    Counts votes for Republic and Democratic candidates
 *    printing the total number of votes in the Dem and Rep party,
 *    the winner in each party and the percentage of 
 *    votes the winner received from all those who voted in that party
 *
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/* Convenience struct to group candidate info. Use if desired */
class Candidate_Dem {
  public: 
    string name;
    int votes;

      Candidate_Dem(string x, int y)
      {
        name = x;
        votes = y;
      }
};

class Candidate_Rep{
  
  public:
    string name;
    int votes;

      Candidate_Rep(string x, int y)
      {
        name = x;
        votes = y;
      }
};

/* Prototype for given printResults function         *
 *  You must use this function to print your results */
void printResults(int totalDemVotes, 
		  std::string demWinnerName, 
		  double demWinningPercent,
		  int totalRepVotes, 
		  std::string repWinnerName, 
		  double repWinningPercent);

// Add other prototypes here if you like

/*
  Things need to be done in main function 
  1) Read the file 
    *1] using infile to read the very top number and store seperately
    *2] using 'getline' to read line by line
    *3] using stringstream => and seperate each line Dem & Hill
    *4] as you string stream, make an pointer array that 
        seperate Dem & Rep  and compeletely ignore other party 
    *5] Upto here, we have data of how many Dem, Rep

  2) With the data, getting values that will be called by 
    printResults. 

*/
int main(int argc, char* argv[])
{
  if(argc < 2){
    cout << "Please provide an input file" << endl;
    return 1;
  }
 
  //1) calling file using ifstream! 
  ifstream inFile;
  inFile.open(argv[1]);
  if(inFile.fail()){
    cerr << "Invalid file" << endl;
    return 1;
  }

  int totalNumVote;
  int totalDem;
  int totalRep;

  inFile >> totalNumVote; //This allows to get the total number of votes 
  //totalNumVote will be used to calculate the total percentage

  //reading each line and while getline -> use stringstream 
  //to store dem rep seperately 
  //and need to increment the count for each candidate 


  //vector <Candidate_Dem> dem;
  //vector <Candidate_Dem> dem_count;
  //vector <Candidate_Rep> rep;
  //vector <Candidate_Rep> rep_count;

  vector <string> democratic;
  vector <string> republic; 

  Candidate_dem oneD;
  Candidate_dem twoD;
  Candidate_dem threeD;

  Candidate_Rep oneR;
  Candidate_Rep twoR;
  Candidate_Rep threeR;

  string party;
  string candidates;
  
  while(!inFile == EOF){
    //bool exist = false; //if candidate names does not exist,
    //make new candidates
    inFile >> party; 

    if(party == "Dem") //when Dem 
    {
      inFile >> candidates;//read candidate name 
      democratic.pushback(candidate);//putting candidate name into vector array 


      for(int i=0; i < democratic.size(); i++)//check candidates's name 
      {
        if(democratic[i] == oneD.name)//increment the vote for each candidate 
        {
          oneD.votes++; // increments vote for each matching candidate 
        }
        if(democratic[i] == twoD.name)//increment the vote for each candidate 
        {
          twoD.votes++; // increments vote for each matching candidate 
        }
        if(democratic[i] == threeD.name)//increment the vote for each candidate 
        {
          threeD.votes++; // increments vote for each matching candidate 
        }
      }//for

      totalDem++;
    }//if
  

    }//if

    if(party == "Rep") //when Rep
    {
      inFile >> candidates;//read candidate name 
      republic.pushback(candidate);//putting candidate name into vector array 
      for(int i=0; i < republic.size(); i++)//check candidates's name 
      {

        if(republic[i] == oneR.name)//increment the vote for each candidate 
        {
          oneR.votes++; // increments vote for each matching candidate 
        }
        if(republic[i] == twoR.name)//increment the vote for each candidate 
        {
          twoR.votes++; // increments vote for each matching candidate 
        }
        if(republic[i] == threeR.name)//increment the vote for each candidate 
        {
          threeR.votes++; // increments vote for each matching candidate 
        }
      }//for

      totalRep++;
    }//if





  }//while

  string demWinner;
  double demPercentage;
  string repWinner;
  double repPercentage;

  demPercentage = depwinner/totalNumVote;
  repPercentage =

  printResult(totalDep, demWinner, demPercentage, totalRep, repWinner, repPercentage );



  inFile.close(); //closing infile





  return 0;
}


void printResults(int totalDemVotes, 
		  std::string demWinnerName, 
		  double demWinningPercent,
		  int totalRepVotes,
		  std::string repWinnerName, 
		  double repWinningPercent)
{
  cout << totalDemVotes << " Dem votes, won by: " << demWinnerName << " ";
  cout << setprecision(2) <<  demWinningPercent << endl;
  cout << totalRepVotes << " Rep votes, won by: " << repWinnerName << " ";
  cout << setprecision(2) <<  repWinningPercent << endl;
}
