/* PA #2 

   Name: Summer Yeonhee Seo 
   lecture section/time : M,W 11:00am 
   UID: 8321974769

   This program is simulation of coin-flipping game to find the average
   number of flips before one of the players goes broke.

   This is how game is played: 
   When flipping coin, if all three players have either head or tail, they keep their own coins.
   When two players have same result (either head or tail), and one doesn,t, that one takes two others' coin. 
   And game goes on until one player goes broke. 

   Users can decide the initial coins to be start with, coin fairness, 
   and number of game simulations. 

   */ 

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <climits>

using namespace std;

int flip(double fairness);

int main()
{
	int initial_coins, num_simulations;
	double fairness;

	cout << "Please input three values in order, a number of initial coins, coin fairness in decimal between [0,1) and number of game simulations to perform" << endl;
	cin >> initial_coins >> fairness >> num_simulations;

	int players[3]; //making 3 elements array (three players)

	int total_Num_Sum = 0;
	int total_Num = 0;

	srand(time(NULL));

	for(int i=0; i < num_simulations; i++) // for loop for number of games to be played
	{	                                   // for loop breaks after it runs "num_simulations" amount of time.
		
		for(int j=0; j<3; j++)
		{
		players [j] = initial_coins; 
		}

		total_Num = 0; 
		//Re-assigning number of coins each players have before starting a new game. 
		//Re-assigning total number of flips to 0 before starting a new game. 

		// while loop ends until one player goes broke (this is per game)
		while(players [0] > 0 && players [1] > 0 && players [2] > 0) 
		{
			int player_0 = flip(fairness); // each player gets random num of either 0 or 1 (head or tail)
			int player_1 = flip(fairness); 
			int player_2 = flip(fairness);

			/* 
			if else statement of different situations when one player takes two other players' coins
			and when others lose one of theirs. 
			*/

			if ((player_0 == 0 && player_1 == 0 && player_2 ==1) || (player_0 == 1 && player_1 == 1 && player_2 ==0))
			{ 
				players [2] = players [2] +2; 
				players [0] = players [0] -1;
				players [1] = players [1] -1;
			}
			else if ((player_1 == 0 && player_2 == 0 && player_0 ==1) || (player_1 == 1 && player_2 == 1 && player_0 ==0))
			{
				players [0] = players [0] +2; 
				players [1] = players [1] -1;
				players [2] = players [2] -1;
			}
			else if ((player_0 == 0 && player_2 == 0 && player_1 ==1) || (player_0 == 1 && player_2 == 1 && player_1 ==0))
			{
				players [1] = players [1] +2; 
				players [0] = players [0] -1;
				players [2] = players [2] -1;
			}
			
			
			/*
			else if (player_0 == 0 && player_1 == 0 && player_2 == 0)
			{
				players [1] = players [1]; 
				players [0] = players [0];
				players [2] = players [2];
			}
			else if (player_0 == 1 && player_1 == 1 && player_2 == 1)
			{
				players [1] = players [1]; 
				players [0] = players [0];
				players [2] = players [2];
			}

			Condition when all players get either head or tail. 
			Can be omitted. 

			*/

			total_Num ++; // total number of flips have done per game

		}//while

		total_Num_Sum += total_Num; // sum of all the flips have done per games. 
	
	}//for

	cout << "Average:" << " " << (double)total_Num_Sum / (double)num_simulations << endl;	

	return 0;
}//main

int flip(double fairness)
{
	double flipcoin = ((double) rand()) / ((double)(RAND_MAX));

	if(flipcoin <= fairness)
		{return 0;}
	else
		{return 1;}
}