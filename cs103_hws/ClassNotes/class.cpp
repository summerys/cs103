/*
IMPORTANT TOPIC :) 
1) Structs 2) Class 3) Dynamic members 4) pointer to objects 5) Composition 6) Function overloading 
*/

// 1. STRUCTS :) 
// so far, we only learned unpackaged built-in datatypes such as int, bool, double, array..
// however in real world, we have tntities which are described not just by 
// one datatype, but a set(group) of them. :) driver's license, student, car, 3D vector, RGB color...
// therefore, we need a way to GROUP primative datatypes(int, array etc etc.. ) into a more meaningful whole. 
// Struct can encapsulate data (not functions)

Struct example)

	struct color{
		int r, g, b; // r,g,b are "members" of the color type (created new type called color)
	};

	struct student{
		int id;
		char clsssif;
		float GPA;
	};

	student s1, s3;

	s1.id = 12345; 
	s1.classif = 'J';
	s1.GPA = 3.8;

	s2.id = 13579;
	s2.classif = 'M';
	s2.GPA = 2.98;

	cout << s2.id << endl;
	cout << s2.GPA << endl;

	//Based on these examples, we can learn that struct contain
	// tne elements needed for one object
	//and by dot (.) operator, the value can be accessed. :D:D:D

	//How to bundle data and accociate functions togeter
	//using a 'class' definition, :) 
	// class had two huge benefits compared to struct
	//1. EMCAPSULATIOn : everything is in one place - easy to carry over elsewhere, simpler function signatures
	//2. INHERITANCE : more functionality can be added on top of existing functonality ... 

	#include <iostream>
	using namespace std;

	struct vector{
		float x,y,z;

		//below are called METHODS. 
		void setVec(float a; float b; float c){
			x = a;
			y = b;
			z = c;
		} // for setting x,y,z in float. 
		//this void setVec is for when trying to access from
		// main function! 

		void printVec(){
			cout << x << "," << y << "," << z << endl;
		}

		void add(vector B){
			x += B.x;
			y += B.y;
			z += B.z;
		}
	};

	int main(){
		vector u = {1,0,0}, v = {0,1,0}
		u.printVec();
		v.pringVec();

		u.add(v);
		u.printVec();

		return0;
	}


	//EXAMPLE OF CLASS :) 
	//in CLASS, you can use Private and Public.. 

	class vector{
	private: 
		float x,y,z;

	public:
		void setVec(float a, float b, float c);
		void printVec();
	};
	//for Class, we set public method 
	//OUTSIDE of the CLASS{}

	//THEREFORE...


	#include <iostream>
	using namespace std;

	class vector{
		private:
			float x,y,z;

		public: 
			void setVec(float a, float b, float c);
			void prtVec();
	}; 

	void vector::setVec(float a, float b, float c){
		x=a;
		y=b;
		z=c;
	}//NOTICE that we are setting the method/function outside of the class
	//using [vector::] !!! 

	int main(){
		vector v;
		v.prtVec; //NOT been initialized yet 

		v.setVec(1,2,3);
		v.prtVec();

		return 0;
	}


// 3. CLASSES WITH DINAMICALLY CREATED MEMBER DATA
	// USE CONSTRUCTOR & DESTRUCTOR 
	// constuctor is a special member function of a class
	// that is executed whenever we create new objects of that class...
	// without constructor, you cannot just call class type.  

	#include <iostream>
	using namespace std;

	class row{
		private: 
			int len, *ptr;
	

		public: 
			//constructor : the funtion that gets to called automatically
			//as soon as as you create an object 
			//as soon as you create an "object" it just calles constructor 
			//constructor never have return type 
			// constructor name is always the same as type names 
			row(int n=3)
			{ //what do you want as soon as you make the object? 
			//main reason : to get variables and initial value !! 
				len = n;
				ptr = new int[n];

				for(int i=0; i<len; i++)
					{ptr[i] = i;}
			}

			~row(){
				delete[] ptr; // []needed since we are deleting a ptr to an array 
			}
			//when do desturcotr of the ARRAY,,, you have to delete array too! 

			void printRow(string label);
	}; //class row

	void row::printRow(string l)
	{
		cout << l;
		for(int i=0; i<len; i++)
		{
			cout << ptr[i] << " ";
		}
		cout << endl;
	}//printRow{()

	void towRows(){

		row r,s(10);

		s.printRow("s: ");
		r.printRow("r: ");

	}//void


	int main(){
		twoRows();
		return 0;
	}



//4. Pointers to objects!!!! 
	// we can also creat a pointer to an object...using -> operator 
	// to access the objects' methods and members :) 

	row *rp = new row(10); // rp points to a row object created on the heap !! 
							// row(10) is created on the heap memory 
	rp -> printRow("r, via rp : ")

	int x[10] = {1,3,5,7,9,11,13,15,17,19};
	rp -> setRow(x);

	// object.member
	// pointer -> member 
	//ex)
	// row *rp;
	// rp -> setRow(x)
	//ONLY USE ARROW OPERATOR FOR A POINTER :) 


	//if you want to make an 2D array on heap memory, 

	row **rows = new row*[5];
	for(int i=0; i<5 i++)
	{
		rows[i] = new row(4);
	}





















