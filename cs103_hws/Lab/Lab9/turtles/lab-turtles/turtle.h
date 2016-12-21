#include "draw.h"

class Turtle
{
	private: 
		double x0, y0, dir0;
		bool z;
		Color mc;
	
	public:
		Turtle (double x0, double y0, double dir0);	
		void turn(double angle);
		void move(double distance);
		void setColor(Color c);
		void on();
		void off();


};//class