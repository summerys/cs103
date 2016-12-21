#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   int red;
   int green;
   int blue;
   
   cout << "Enter three numbers between 0 to 255 corresponding to color red, green and blue" << endl;
   cin >> red >> green >> blue;
   
   double white = max(double(red)/255, max(green/255.0, blue/255.0));
   double cyan = (white - red/255.0) / white;
   double magenta = (white - green/255.0) / white;
   double yellow = (white - blue/255.0) / white;
   double black = 1 - white; 
   
   cout << "cyan: " << cyan << endl;
   cout << "magenta: " << magenta << endl;
   cout << "yellow: " << yellow << endl;
   cout << "black: " <<black << endl;
  
   return 0;
}
