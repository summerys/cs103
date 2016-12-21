#include <iostream>
#include <string> 
#include <vector>
#include <fstream>

using namespace std;

class wordCt
{
	public:
		string word;
		int ct;

		wordCt(string x, int y)
		{
			word = x; 
			ct = y;
		}
};


int main(){
	//First, read the file! using infile. 
	ifstream inFile("Alice.txt");
	//make string since Alice is a file with words..!
	string w;
	//make two vector arrays
	//one keeping words 
	//one for counting
	vector <string> words;
	vector <wordCt> count;

	//putting Alice.txt items into the file. 
	while(inFile >> w){
		words.push_back(w);
	} //Finishing putting every text file into words vector array

	inFile.close(); //closing infile 

	//need to go over every vector array and find how many same words are in the array
	for(int i = 0; i < words.size(); i++)
	{ 
		bool exist = false; // setting up boolian to false
		for(int j = 0; j < count.size(); j++)
		{

			if(count[j].word == words[i])
			{
				count[j].ct++;
				exist = true;
			}
			//If the word is same increment the count
			//and change exist to true 
		
		}//for

		if(!exist)
			{
				wordCt c(words[i],1);
				count.push_back(c);
			}
	}//for

	for(int i = 0; i < words.size(); i++)
	{
		cout << words[i] << "  appeared : " << count[i].ct << endl;
	}

	return 0;
}