#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

unsigned char image[SIZE][SIZE];


void draw_rectangle(int top, int left, int height, int width) 
{
    
   for(int i = left; i < left + width; i++) 
   {
      if (top > 0 && top < 255 && i > 0 && i < 255)
      {
      image[top][i] = 0;
      }

      if (top+height > 0 && top+height < 255 && i > 0 && i < 255)
      {
      image[top+height][i] = 0;
      }
   }

   for(int i = top; i < top + height; i++)
   {
      if (left > 0 && left < 255 && i > 0 && i < 255)
      {
      image[i][left] = 0; 
      }

      if (left + width > 0 && left+width < 255 && i > 0 && i < 255)
      {
      image[i][left+width] = 0;
      }
   }
 
}

void draw_ellipse(int cy, int cx, int height, int width) 
{

double rx= width/2;
double ry= height/2;

   for (double theta=0.0; theta < 2*M_PI; theta += .01)  
   {
      double x = rx*cos(theta);
      double y = ry*sin(theta);
      x += cx;
      y += cy;

      if (x > 0 && x < 255 && y > 0 && y < 255)
      {
      image[(int)y][(int)x] = 0;
      }
   }
}


int main()
{
   
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
    while(int draw = 2)
   {
      draw = 0;
      int a, b, c, d;
      cout << "To draw a rectangle, enter: 0 top left height width" << endl;
      cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
      cout << "To save your drawing as 'output.bmp' and quit, enter: 2" <<endl; 
      
      cin >> draw;
         if (draw == 2) 
         {
            break;
         }

      cin >> a >> b >> c >> d;

         if(draw == 0)
         {
            draw_rectangle(a, b, c, d);
         }
         else if(draw == 1)
         {
            draw_ellipse(a, b, c, d);
         }
         
   }
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}
