/* 
   
   Name: Summer Yeonhee Seo
   E-mail : summerys@usc.edu
   
   <PA1> - Part 1 
   
   :This is a simple algorithm that allows to solve
    "Hailstone Sequences" with any positive integer. 
   
*/
    

#include <iostream> 
using namespace std;

int main()
{
   int input;
   int length=0;
   cout << "Please enter any positive integer: ";
   cin >> input;
         
        while(input!=1)
        {
            if(input % 2==0)
            {
                input = input / 2;  
            }
            else
            {
                input = input * 3 + 1;    
            }
        
        cout << input << " ";  
        length ++;
        }
        
    cout << endl;    
    cout << "length: " << length << endl;
    
return 0;
}
