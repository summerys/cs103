
#include "bigint.h"
#include <cstring>
#include <iostream>

using namespace std;


BigInt::BigInt(string s) {

	int len = 0;
	len = s.length();
	const char *c = s.c_str();

	for(int i = 0; i < len; i++) 
	{
		vec.push_back(c[i]-48);
	}
}


string BigInt::to_string(){

	char * temp = new char;
	for(int i = 0; i < vec.size(); i++)
	{ 

		temp[i] = (char)vec[i]+48;
		//cout << vec[i];
	}
	return string(temp);
}

void BigInt::add(BigInt b){

	for(int i=0; i < b.vec.size(); i++)
	{
		vec[i] = b.vec[i] + vec[i];		
	}

}

