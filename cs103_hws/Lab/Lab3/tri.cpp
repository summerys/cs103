#include <iostream>
#include <cmath>

using namespace std;

int main(){

   double degree;
   cout << "Enter the angle theta in degree between 15 to 75: " <<endl;
   cin >> degree;
   cout << endl;
   
   double degree_to_radians = degree*M_PI / 180;
   
   for( int y=1; y<32; y++){
   
      int length = int(tan(degree_to_radians) * y);
   
       if(length <=20 || length >= 30){
   
       for(int x=0; x<length; x++){
         cout << "*";
     }
     
      }else{
          for(int x=0; x<20; x++){
            cout << "*";
          }
      }
          cout<<endl;
   
   }
   
   return 0;
   }
