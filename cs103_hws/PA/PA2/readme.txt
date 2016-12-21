CSCI 103 Programming Assignment: Going Broke

Name:  Summer Yeonhee Seo 

Email Address: summerys@usc.edu

================== Prelab ===================

Response 1:
Using srand(time(NULL)) and rand()%2 to generate coin-toss outcome for each player. 

Response 2:
There are 4 different situations
1) If all players gets either all head(0) or tail(1) : No inclement 
2) If Player 0 or 1 both have head or tail -> player 2 gets 2 extra coins
3) If player 1 or 2 both have head or tail -> player 0 gets 2 extra coins
4) If player 0 or 2 both have head or tail -> player 1 gets 2 extra coins 
I can use if/else statement for this.

Response 3: while loop. Games ends only when one of the player goes broke. So in this lab, condition would be until everyone have one or more coins. 
It can be written like following as an example: 
while (player1 > 0 && player2 > 0 && player3 > 0) 
while condition in ( ) is true, loops continues. so when one person goes broke, ( ) becomes false that loop stops. 

Response 4: fairness (type: double) , initial number of coin (type: integer) 

Response 5. Yes, because user inputs total number of simulation. for loops

Response 6:
Probability matters alot in this game. 
If we have probability of 0.5, each players have 0.5x chances to get either head or tail. It is harder to get all three users to get same heads or tails. (compare to when p=0.1) Therefore, game will move forward faster pace. (number of losing and gaining coins between users)
However, when p=0.1, it means that each user have 0.1x chance to get either head or tail and 0.9x for other. Let's say they have 90% chance of getting head and tail comes out only for 10% chance. Game will flow very sluggish because most of the time, the player will get all heads which does not add or lose the number of the total coins. In this case, to find the winner, interation of the game needs to be larger than the first case. 


====================== Data from Procedure Step 6 ==========================

coins |  p  |   n    | output
------------------------------
  3   | 0.5 | 5      |4.6
  3   | 0.5 | 10     |4.7
  3   | 0.5 | 50     |5.68
  3   | 0.5 | 100    |5.15
  3   | 0.5 | 1000   |5.178
  3   | 0.5 | 10000  |5.1963
  3   | 0.5 | 100000 |5.13723
 
====================== Data from Procedure Step 7 ==========================

coins |  p  |   n    | output
------------------------------
  3   | 0.1 | 10000  |14.2964
  3   | 0.2 | 10000  |8.0997
  3   | 0.3 | 10000  |6.1312
  3   | 0.4 | 10000  |5.319
  3   | 0.5 | 10000  |5.1804
  3   | 0.6 | 10000  |5.3565
  3   | 0.7 | 10000  |6.1907
  3   | 0.8 | 10000  |8.1326
  3   | 0.9 | 10000  |14.3813

================================== Review ===================================

Response 1: Based on the first data set,"point of diminishing returns" are at  3, 0.5, 50 and 3, 0.5, 10000
because output decreases after those two points. 
After the first "point of diminishing returns" datas look pretty similar, which is at 5.10-5.19 range.
however we don't know the outcomes in between n of 50 to 100.
Therefore in my opinion "point of diminishing returns" where the extra time wating for the simulation
is not worth the increase accuracy is at 3, 0.5, 10000. 

Response 2: Yes it does match to my expectation because probability of 0.5 should have lowest number of output.
Since it has half chance to get head and tail that it is easier to get different result (head or tail) per each flips. 
When probablities like 0.1 or 0.9 means there is 10%, 90% chance of getting either head or tail that 
it is more likely that all three players to get the same side of the coin. Which requires more flips until one goes broke. 

Response 3: because 0.0 or 1.0 means players always either get heads or tails.
with probability of 0.0 and 1.0, game will never end. 

================================ Remarks ====================================

Approximately how long did you spend on this assignment?
: 2 days

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

Yes, I was keep getting wrong outcomes when I thought I did everything correctly. 
It was really hard to see the error and took me a day to debug and find out the problem.

