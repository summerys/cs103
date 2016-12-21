/* 
maze.cpp

Author: Summer Yeonhee Seo 

Short description of this file:

This program finds the shortest path of the given maze between 
start point and finish point. 

The maze includs 4 different symbols : S,F,.,# 

   S: Start
   F: Finish
   .: normal path
   #: Wall

1.Creating a maze with given rows and colums from other file (maze). 
2.Program puts all the datas into the maze.
3.Using maze_search, program starts from "S" and visits all the possible 
normal paths until it finds "F". 
   -Visited array to keep track. 
4.Trace back from Finish to Start as it finds the shortest path. 
   -Achieved by predecessor. 
5.Mark the shortest path with '*'
6.Lastly, prints out the result! 

*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main() {
   int rows, cols, result;
   result = 0;
   char** mymaze; 
   // assigning 2D array pointer which is going to 
   // get values from read_maze funstion. 

   cin >> rows >> cols; 
   // accepting first two values from assigned file. 
   
   mymaze = read_maze(&rows, &cols); 
   //calling read_maze function in 
   //mazeio.cpp and putting into mymaze 2D array. 
   
   if (mymaze == NULL) { 
   //if there is no value in mymaze: meaning there was no input
      cout << "Error, input format incorrect" << endl; 
      return 1;  
   }
   
   result = maze_search(mymaze, rows, cols);

   // calling maze_search with the maze we called above. 
   // examine value returned by maze_search and print appropriate output

   if (result == 1) 
   { // path found!
      cout << rows << " " << cols << endl;
   // printing out values of rows and cols. 
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path 
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // Deleting 2d array pointers 
   // **mymaze 
   for(int i=0; i<rows; i++)
   {
      delete [] mymaze[i];
   }
   delete [] mymaze;


   return 0;
}

int maze_search(char** maze, int rows, int cols) {
   //In maze_search, 
   // 1. creating predecessor, visited 2D pointer array 
   // 2. Checks the all the neighbor arrays of current array. 
   // 3. Updates Queue, Visited, and Predecessor each time 
   //    current visits the neighbor array. 

   //predesessor is for keeping track of previous array value
         //later on use to trace back the shortest path.
   //Visited function is for keeping track if the array was visited.

   Location** predecessor = new Location* [rows];
   for(int i = 0; i < rows; i++)
   {
      predecessor[i] = new Location [cols];
   }

   bool** visited = new bool* [rows];
   for(int i = 0; i<rows; i++)
   {
      visited[i] = new bool [cols];
   }

   //putting all '0' : unvisited in visited 2d pointer array. 
   for(int i=0; i< rows; i++)
   {  
      for(int j=0; j < cols; j++)
      {
         visited[i][j] = 0;
      }
   }
   
   // Find the start and finish point to check if the maze is valid
   Location start;
   Location finish;
   int count_start = 0;
   int count_finish = 0;

   for(int i=0; i < rows; i++)
   {
      for(int j = 0; j < cols; j++)
      {
         if(maze[i][j] == 'S')
         {
            start.row = i;
            start.col = j;
            count_start ++;
            // found the start point 
         } 
         if(maze[i][j] == 'F')
         {
            finish.row = i;
            finish.col = j;
            count_finish ++; // found the finish point 
         }
      }//for
   }//for

      //check if there is more than one start or finish point
      //or if there is no start and finish point
      if(count_start != 1 || count_finish != 1 )
         {
            for(int i=0; i<rows; i++)
            {
            delete [] visited[i];
            }
            delete [] visited;

            for(int i=0; i<rows; i++)
            {
            delete[] predecessor[i];
            }
            delete [] predecessor;
         
         return -1 ;
         } //return invalid maze! 

   //creating queues of rows*cols  
   Queue queue( rows * cols );
   queue.add_to_back(start); //in queue.cpp, putting rows and cols value
                             //in Location start into very first queue

   // a while loop that runs until queue is empty.
   Location curr; 
   curr.row = 0;
   curr. col = 0;
   int* row_copy = &curr.row;
   int* col_copy = &curr.col;

   while(!queue.is_empty())
   {
      curr = queue.remove_from_front();
      int row = curr.row;
      int col = curr.col;

      *row_copy= curr.row;
      *col_copy= curr.col;

      if(maze[curr.row][curr.col] == 'F')
      {
         break; 
      } 

      Location start_Location = curr;
      
   //North
      row--;
      if(row >= 0 && row != rows && col >= 0 && col != cols)
      {
         if(visited[row][col] != 1)
         {
           if(maze[row][col] != '#')
           {
            curr.row--;
            queue.add_to_back(curr);
            visited[row][col] = 1;
            predecessor[row][col] = start_Location;
           } //if
         } //if
      } //if
      curr = start_Location;
      row = curr.row; 

   
//West
      col--;    
      if(row >= 0 && row != rows && col >= 0 && col != cols)
      {
         if(visited[row][col] != 1)
         {
           if(maze[row][col] != '#')
           {
            curr.col--;
            queue.add_to_back(curr);
            visited[row][col] = 1;
            predecessor[row][col] = start_Location;
           } //if
         } //if
      } //if  
      curr = start_Location;
      col = curr.col;

//South
      row++; 
      if(row >= 0 && row != rows && col >= 0 && col != cols)
      {
         if(visited[row][col] != 1)
         {
           if(maze[row][col] != '#')
           {
            curr.row++;
            queue.add_to_back(curr);
            visited[row][col] = 1;
            predecessor[row][col] = start_Location;
           } //if
         } //if
      } //if
     curr = start_Location;
     row = curr.row;

     
//East
      col++;
      if(row >= 0 && row != rows && col >= 0 && col != cols)
      {
         if(visited[row][col] != 1)
         {
           if(maze[row][col] != '#')
           {
            curr.col++;
            queue.add_to_back(curr);
            visited[row][col] = 1;
            predecessor[row][col] = start_Location;
           } //if
         } //if
      } //if
      curr = start_Location;
      col = curr.col;
   }//while 

   //When maze could not find the path to F, 
   //return "No path could be found!"
   if(maze[curr.row][curr.col] != 'F')
   { 

      for(int i=0; i<rows; i++)
      {
         delete [] visited[i];
      }
      delete [] visited;

      for(int i=0; i<rows; i++)
      {
         delete[] predecessor[i];
      }
      delete [] predecessor;

     return 0;
   } 

   if(maze[curr.row][curr.col] == 'F')
   {
      Location p = predecessor[curr.row][curr.col];

         while(maze[p.row][p.col] != 'S')
         {
            maze[p.row][p.col] = '*';
            p = predecessor[p.row][p.col];
         }
       //return success 
   }

   
   //deleting visited and predecessor. 
   for(int i=0; i<rows; i++)
      {
         delete [] visited[i];
      }
      delete [] visited;

   for(int i=0; i<rows; i++)
      {
         delete[] predecessor[i];
      }
      delete [] predecessor;
      

return 1;
}
