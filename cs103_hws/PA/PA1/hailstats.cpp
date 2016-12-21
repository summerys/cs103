/* 
   
   Name: Summer Yeonhee Seo
   E-mail : summerys@usc.edu
   
   <PA1> - Part 2 
   
   :This is a program that searches through a range of 
    numbers that the user specifies, and reports the
    shortest and longest lengths in that range. 
   
*/
  
#include <iostream> 
using namespace std;

int main()
{
   int a;
   int b;
   int length=0;  
   int max_Length=0;
   int min_Length=0;
   int max_Num=0;
   int min_Num=0;
   bool first = true;
   
   cout << "Please enter the range you want to search: ";
   cin >> a >> b; 
  
  if(a>b) // if range is set wrong, program exit out
    { 
        cout << "Invalid range" ;
        return 0;
    }
    else 
    { 
        for(int i = a ; i <= b; i++) 
        {
            a=i;
            length = 0;
            while(a != 1) // hailstone sequences
            {
                if(a % 2==0)
                {
                    a = a / 2;  
                }
                else
                {
                    a = a * 3 + 1;    
                }
                
            length ++;
            } 
            
            if(first) 
            // assigning initial max_Length and min_Length
            // and initial max_Nu and min_Num
            {
                max_Length = length;
                min_Length = length;
                max_Num = i;
                min_Num = i;
             
                first = false;
            } 
            
            if(length >= max_Length)
            {
                max_Length = length;
                max_Num = i;
            }
            else if(length < min_Length)
            {
                min_Length = length;
                min_Num = i;
            }  
        }

    cout << "Minimum length: " << min_Length << endl;
    cout << "Achived by: "<< min_Num << endl;
    cout << "Maximum length: " << max_Length << endl;
    cout << "Achieved by: "<< max_Num << endl;
       
    } 
  
return 0; 
}


