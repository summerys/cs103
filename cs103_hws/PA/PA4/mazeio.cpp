/* 
mazeio.cpp

Author: Summer Yeonhee Seo 

Short description of this file:

This program is to read the maze and print out the maze. 

To read maze:
1. setting up the 2D array of maze with the value of rows and cols
   got from maze.cpp main function. 
2. putting a character into each empty array 
   while 'cin' the file. 

To print maze: 
   
Print the final maze when main function in maze.cpp calls. 

*/

#include <iostream>
#include "mazeio.h"

using namespace std;

char** read_maze(int* rows, int* cols) {

   //if maze has zero or less number, it means maze does not exist. 
   //returning NULL
   if( *rows <=0 || *cols <= 0)
   { return NULL; }

   //creating 2D pointer array of maze in heap memory 
   char **maze = new char* [*rows];
   for(int i = 0; i<(*rows); i++)
   {
      maze[i] = new char [*cols];
   }
   //cin the file and putting each values into maze array. 
   for(int i=0; i < *rows; i++)
     {
         for(int j = 0; j < *cols; j++)
         {
           cin >> maze[i][j];
         }  
      }//for

   return maze;
}//end of read_maze
   

void print_maze(char** maze, int rows, int cols) {

//creating 2D maze array to print it out. 
   for(int i=0; i < rows; i++)
     {
         for(int j = 0; j < cols; j++)
         {
            cout << maze[i][j];
         }
         cout << endl;
     }
}
