/*
	Enumerations are "named integer constants" that are used in situations when 
	something has a LIMITED, DISCRETE number of values. 
	ex) a machine's execution atatus could be 
	NOTREADY, READY, RUNNING, DONE or ERRORED 
	: in these cases, an enumeration could be made! 
*/

#include <iostream>
using namespace std;

//***write "enum" 
enum machineState {NOTREADY, READY, RUNNING, DONE, ERRORED}
//NOTREADY is equivalent to number '0'
//READY is equivalent to number '1' and so forth

machineState getMachineState(){
	if((rand()%2)==0)
		return ERRORED; //in this case it is more clear to understand
	else
		return READY;
}//getMachineState()

//In main funtion, set up the random number using srand(time(NULL))
//and call the getMachineState to get the result of either ERRORED or READY, 
//and print out if Machie is in working condition or broken. 
int main(){
	srand(time(NULL));
	machineState mS = getMachineState();

	if(mS != ERRORED){
		cout << "Machine is in working condition" << endl;
	}//if
	else{
		cout << "Machine is Broken!" << endl;
	}
}//main()


/*
	More examples of enum:
		1) enum primaryColor{RED, BLUE, YELLOW} // Red = 0, BLUE = 1, YELLOW = 2
		2) enum rotAxis {X,Y,Z}; 
		3_ enum countryOfOrigin{Ireland, Israel, India};
		4) enum cardSuit {Diamonds, Hearts, Clubs, Spades};

		*** enum help avoid writing code such as 'if(direction==0)', instead making it
			possible to write more readable code such as 'if(direction==X)'

*/