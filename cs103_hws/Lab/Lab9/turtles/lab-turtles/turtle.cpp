#include "turtle.h"
#include "draw.h"
#include <cmath>

//construct
Turtle::Turtle(double x1, double y1, double dir1)
{
	x0 = x1;
	y0 = y1;
	dir0 = dir1*(M_PI/180);
	z = 0;
	mc = draw::BLACK;
}	

void Turtle::turn(double angle)
{
	dir0 += angle*(M_PI/180);//changing to radians
}//turn

void Turtle::move(double distance)
{
	draw::setcolor(mc);
	double old_x = x0;
	double old_y = y0;

	x0 += distance * cos(dir0);
	y0 += distance * sin(dir0);
	
	if(z == 0)
	{
		draw::line(old_x, old_y, x0, y0);
	}
	
}//move

void Turtle::setColor(Color c)
{mc = c;}

void Turtle::off()
{z = 1;}

void Turtle::on()
{z = 0;}


