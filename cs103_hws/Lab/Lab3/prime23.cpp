#include <iostream>
using namespace std;

int main(){

int n;
int a=0;
int b=0;
cout << "Enter a positive integer: " <<endl;
cin >> n;

if(n%5==0){
   cout << "NO" <<endl;
  }
   else if(n%2==0 || n%3==0){
   cout << "YES" <<endl;
   }
   else{
   cout << "NO" <<endl;
   }

   while(n%2==0 || n%3==0){
      while(n%2==0)
      { 
       n = n/2;
       a++;
      }
         while(n%3==0)
         {
         n = n/3;
         b++;
         }
   
   
   if(n%5!=0){
   cout << "Twos=" << a << " " << "Threes=" << b << endl;
   }
   }
   
return 0;
}
