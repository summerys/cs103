CSCI 103 Programming Assignment 1, Hailstone, Spring 2015

Name: Summer Yeonhee Seo

Email Address: summerys@usc.edu


: I searched google for parts I was not confident about.
  Such as how to compute Maximum and Minimum.

================================ Questions ==================================

1. I used while loop because loop has to continue until it  
   reaches number 0, without knowing exact number of times.
 
2a.
-----------------------------------------------------------------------------
    50 100  :  6 64  118 97               
   100 200  :  7 128 124 171
   200 400  :  8 256 143 327          

2b. 
when first input increases by *2, the minimum length increases by +1. 
It is because 50 and 100 both are divisible by 2, so that first number for 50 is 50/2 and for 100 is 100/2. 
Since 100/2 is 50, sequence comes following is same as the length of calculation of 50.
(200/2 = 100 100/2 = 50)
Therefore, the result gets minimum length of whatever initial number/2 +1.  

3a. 703

3b. I put 100,300 / 300,500/ 500,700/700,900
to find the maxinum length that is bigger than 150. 
when I put 700,900 I got a maximum bigger than 150. 
so I narrowed it down to 700,800 / 700,750 / 700, 710 to find the answer. 

================================ Remarks ====================================

:about 6 hours

:the biggest problem I had is to figure out how to put initial value for max_length and min_length and max_Num and min_Num this took me the longest to figure out. I used boolean function to assign initial values. 


