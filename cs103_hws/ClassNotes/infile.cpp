//1. Streams
//2. File streams
//3. Redirection

//Are the main topic ! 

//1. Streams
//cin and cout 

//2. File stream 
// How to WRITE data from our program to a file... :D 

// File reading 

#include <iostream>
#include <fstream>

using namespace std;
using std::ifstream;
using std::ofstream; 

int main()
{
	ifstream inFile;
	inFile.open("C:/temp/test.txt");
	if(inFile.fail()) // always check if file opens!!! 
	{
		cout << "Unable to open input file" << endl;
		return 1; 
	}

	inFile.close();
}