/* 
	Three different types of streams in c++ are ...!
	1) cin & cout => console in and out streams (user inputs)
	2) ifstream and ofstream => to create file in and out streams (calling files)
	3) stringstream => to create ***string*** in and out streams

	stringstreams are useful in 3 different ways :

	1) To convert between a number and its string equivalent 
	2) To extract from a string, indivisual numbers. combile multiple numbers into a string
	3) to "TOKENIZE" ( break apart ) a string into substrings

*/


// 1) CONVERT BETWEEN A NUMBER AND ITS STRING EQUIVALENT 
//	  Text file : stroe everything as text meaning that it is "string". 
//	  2015 will be read as "2015". 
//	  So, stringstream lets conver "2015" into 2015. :) 

#include <iostream>
#include <string>
#include <sstream> //HAVE TO INCLUDE THIS!!!!!!! FOR STRING STREAM...

using namespace std;

int main(){
	string s = "2015"; 
	cout << s+s << endl; // this will print out as 20152015 because it's still in string
	stringstream ss; //CREATE STRINGSTREAM SS
	ss << s; //putting string s "2015" into string stream. 
			 //this will change string to whatever output 

	//simply can say
	//stringstream ss(s);

	int n; // creating integer that is going to accept ss
	ss >> n; // NOW "2015" is in integer type, 2015
	cout << n+n << endl; // will do 2015+2015 = 4030 

	ss.clear(); ss.str(""); // DO THIS BEFORE REUSING

	n = 1776; 
	cout << n+n << endl; //since it's integer, it will pring out 1776+1776
	ss << n; // putting 1776 into string stream 

	ss >> s; // // putting ss which is 1776, into string s 
			//therefore s now is "1776"
	cout << s+s << endl; // 17761776
} // main()


// 2) EXTREACT NUMBERS, COMBINE NUMBERS..! :) 
//    WHAT IF... given string is "150.65 19 M" 
// 	  How to extract the double, int and char? 
// 	  Also, How do we create a string from a double, int and char? 

#include <iostream>
#include <string>
#include <sstream> // :) Don't forget sstream for stringstream! 

using namespace std;

int main(){
	string s = "160.65 19 M";
	stringstream ss(s); //accepting string into stringstream

	double a;
	int b;
	char c;

	ss >> a >> b >> c; //separate out the contents. 
	//converting string as double, int and char 

	ss.clear(); 
	ss.str("")   //DO THIS BEFORE USING IT 

	a *= 0.9;
	b = 20;
	c = 'F';
	ss << a << " " << b << " " << " " << c;
	//pay attention that we input space as well!!!! 

	s = ss.str(); //string equivalent of a stringstream
	cout << s << endl; // will be "144.864 20 F"

	//making extra string and save is seperately is also possible
	//ex) string s2; 
	//    string s3;
	// ss >> s >> s3 >> s3 >> endl; 
	// putting values in order into string 
}//main



//3. TOKENIZE A SINGLE LINE OF TEXT INTO WORDS/TOKENS
//   When there are long sentences of text.. :) 

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
int main(){
	string sentence = "Knowing that millions of people around the world
	would be watching in person and on television and expecting great things
	from him - at least one more gold medal for America, if not another world
	record - during this, his fourth surely his last appearance in the 
	World Olympics, and realizing that his legs could no longer carry him down ..."

	stringstream ss(sentence);

	// you want to put word by word into vector array! 

	vector <string> words; //creating string vector array
	string word;
	int count = 0; 
	while(ss >> word) { //this will automatically extract the word by word. 
		words.push_back(word); //expanding words array and storing the information into vector array
		count++; // and count the how many words are in the entire text 
	}

	cout << count << "words:\n" << endl;
	for(unsigned int i = 0; i < world.size(); i++)
	{
		cout << worlds[i] << endl;
	}//for
}//main()

// what if datas are not seperated by space but comma? :D 
// simple goes like
// while(getline(ss, token, ',')){}
// instead of stringstream ss()
// example is below

#include <iostream> 
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
	stringstream ss("2805 Janette Way,SAVRAMENTO,95815,CA,2,1,852,RESIDENTIAL,Wed May 21 00:00:00 EDT 2008")
	//want to seperate the information for every comma,

	string token; 
	while(getline(ss, token, ',')) //geline() keep getting "lines" from our stringstream, where each 'line'is seperated
								   //from the next 'line' by a comma :D 
	{
		cout << token << endl;
	}//while
}//main 



//*** EXAMPLES to getline Infile : ) 
while(getline(inFile, line))
{
	stringstream ss(line);
	string token;
	while(getline(ss, token, ','))
	{

	}
}