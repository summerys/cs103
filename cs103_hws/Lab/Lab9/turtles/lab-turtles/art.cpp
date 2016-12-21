#include "draw.h"
#include "turtle.h"

int main() {
   // set corners
   draw::setrange(-100, 100);


   // create turtle at x-position 0, y-position 0, facing angle 0 (east)   
   Turtle aa(0, 0, 0); 
   
   aa.setColor(draw::BLUE);
   for(int i=0; i<5; i++)
   {
      aa.move(80);
      draw::show(300);
      aa.turn(90);
   }
   aa.off();
   aa.move(80);
   draw::show(300);
   aa.turn(120);
   aa.on();
   for(int i=0; i<3; i++)
   { 
   aa.move(160);
   draw::show(300); 
   aa.turn(75);
   }

   Turtle bb(0, 10, 0);
   bb.setColor(draw::ORANGE);
   bb.move(30);
   draw::show(300);
   bb.turn(50);
   for(int i=0; i<30; i++)
   {
   bb.move(30);
   draw::show(300);
   bb.turn(60); 
   bb.off();
   bb.move(60); 
   draw::show(300);
   bb.on();
   bb.move(20);
   draw::show(300);
   }

   Turtle cc(20, 20, 0);
   cc.setColor(draw::RED);
   cc.move(80);
   draw::show(300);
   cc.turn(90);
   for(int i=0; i<25; i++)
   {
   cc.move(30);
   draw::show(300);
   cc.turn(110); 
   }
   cc.move(130);
   draw::show(300); 

   Turtle dd(30, 30, 210);
   dd.setColor(draw::GREEN);
   dd.move(80);
   draw::show(300);
   dd.turn(90);
   for(int i=0; i<30; i++)
   {
   dd.move(80);
   draw::show(300);
   dd.turn(120); 
   };
   dd.move(160); 
   draw::show(300);

   return 0;
}