#include <iostream>
using namespace std;

int main(){

   int x;
   cout << "Enter a number between 0 and 999: " << endl;
   cin >> x;

   cout << "1's digit is: " << x % 10 << endl;
   cout << "10's digit is: " << (x / 10) % 10 << endl;
   cout << "100's digit is: " << x / 100 << endl;
 
return 0;

}
