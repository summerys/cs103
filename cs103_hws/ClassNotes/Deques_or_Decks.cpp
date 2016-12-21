/*
	Vetor : single ended queue. 
			vector does not have push_front or pop_front
			but only push_back and pop_back. 
	Deque: provides ALL FOUR 
			push_front, push_back 
			pop_front , pop_back 
*/


#include <iostream>
#include <deque>

using namespace std;

int main(){

	deque <int> deck1, <int> deck2; 

	cout << "push_front()\n";
	for(int i=1; i<=10; ++i){
			deck1.push_front(i*1.5); 
		}// will print out like 
		// ... 3.0  1.5  0 
		// <-------------going this order

//push_front lets the array grow from right to left. 


	for(unsigned int i=0; i<deck1.size(); ++i)
        cout << deck1[i] << ' ';
    cout << endl;

    // insert elements at the back
    cout<<"\npush_back()\n";
    for(int i=1; i<=10; ++i)
        deck2.push_back(i*(1.5));

    // print all elements separated by a space
    for(unsigned int i=0; i<deck2.size(); ++i)
        cout << deck2[i] << ' ';
    cout << endl;

    // pop, print
    cout << "\npop" << endl;
    for(int i=0;i<5;i++)
        deck1.pop_back(); // extracting 5 times out from back

    for(int i=0;i<5;i++)
        deck2.pop_front(); // extracting 5 itmes from front 

    for(unsigned int i=0; i<deck2.size(); ++i)
        cout << deck1[i] << ' ';
    cout << endl;
    
    for(unsigned int i=0; i<deck2.size(); ++i)
        cout << deck2[i] << ' ';
    cout << endl;

    return 0;
}// main()
}//main