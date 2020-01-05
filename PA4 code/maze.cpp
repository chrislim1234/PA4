/* 
maze.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
   int rows, cols, result;
    //make mymaze equal to null
   char** mymaze=NULL;
   
   if(argc < 2)
   {
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
    //copy mymaze from code from mazeio
   mymaze = read_maze(argv[1],&rows,&cols);
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }
    
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (mymaze[i][j]!='#'&&mymaze[i][j]!='S'
                &&mymaze[i][j]!='F'&&mymaze[i][j]!='.') {
              cout << "Error, input format incorrect" << endl;
          return 1;
           }
        }
    }

    //use maze_search function
   result=maze_search(mymaze, rows, cols);

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated

for (int i = 0; i < rows; i++)
	{
		delete [] mymaze[i];
	}
	delete [] mymaze;
   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) 
{
    //create a start, which is a location, set up variables
    Location start;
    int startCount  = 0;
    int finishCount = 0;
    bool path = false;
    
    //find location of S and F and check if there is only one F and only one S
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (maze[i][j] == 'S') {
                start.row = i;
                start.col = j;
                startCount=startCount+1;
            }
            else if (maze[i][j]=='F') {
                finishCount=finishCount+1;
        }
    }
    }
   
    if (startCount!=1 || finishCount!=1) {
        return -1;
    }
    
    //create dynamic 2d arrays for visited (a queue)
    int x = rows * cols;
    
    Queue q(x);
        
    q.add_to_back(start);
    
    int ** visited = new int*[rows];
    
     for (int i = 0; i < rows; i++)  {
         visited[i] = new int[cols];  
     }   
      
    // make all indexes equal to zero
    
     for (int i = 0; i < rows; i++)  {   
         for (int j = 0; j < cols; j++)   {   
             visited[i][j] = 0;   
         }  
     }
    visited[start.row][start.col] = 1;
      
    
    //create a predecessor which is index of all location predecessors
    
    Location ** predecessor = new Location*[rows];
    
     for (int i = 0; i < rows; i++)  {
         predecessor[i] = new Location[cols];  
     }   
     
        
     while (!q.is_empty()) {
         //create current and move to next, deleting the first in array,
         //and with while loop, it runs through all of the members in queue
         Location current = q.remove_from_front();
         
         //finding the square above current
         Location up;
         //create location of square up including its row and column
         up.row = current.row-1;
         up.col = current.col;
         //check if in bound
         if (up.row>=0 && up.row<rows && up.col>=0 && up.col<cols) {
             if (maze[up.row][up.col]=='F') {
                 //if square is Final point
             while(maze[current.row][current.col]!='S') {
                 //while current is not S because if current was S 
                 //that would mean no need to add asterick
                 //add asterick and move to predecessor to track 
                 //back to the start
                 maze[current.row][current.col] = '*';
                 current = predecessor[current.row][current.col];
                 
             }
                 //so it can be returned that path works
                  path = true;
                 break;
            }
          
             else if (maze[up.row][up.col]=='.' && visited[up.row][up.col]==0) {
                 //if the point is unvisited and also is an open space, we turn 
                 //it to visited, add predecessor and add to back of queue
                 visited[up.row][up.col] = 1;
                 predecessor[up.row][up.col]= current; 
                 q.add_to_back(up);
             }
        }
             
       //finding the square to the bottom
       Location down;
         down.row = current.row+1;
         down.col = current.col;
         if (down.row>=0 && down.row<rows && down.col>=0 && down.col<cols) {
             if (maze[down.row][down.col]=='F') {
             while(maze[current.row][current.col]!='S') {
                 maze[current.row][current.col] = '*';
                 current = predecessor[current.row][current.col];
                 
             }
                  path = true;
                  break;
            }
          
             else if (maze[down.row][down.col]=='.' &&
                      visited[down.row][down.col]==0) {
                 visited[down.row][down.col] = 1;
                 predecessor[down.row][down.col]= current; 
                 q.add_to_back(down);
             }
        }
             
        //finding the square to the bottom
       Location left;
         left.row = current.row;
         left.col = current.col-1;
         if (left.row>=0 && left.row<rows && left.col>=0 && left.col<cols) {
             if (maze[left.row][left.col]=='F') {
             while(maze[current.row][current.col]!='S') {
                 maze[current.row][current.col] = '*';
                 current = predecessor[current.row][current.col];

                 
             }
                path = true;
                 break;
            }
          
             else if (maze[left.row][left.col]=='.' && 
                      visited[left.row][left.col]==0) {
                 visited[left.row][left.col] = 1;
                 predecessor[left.row][left.col]= current; 
                 q.add_to_back(left);
             }
        }
             
      //finding the square to the right
       Location right;
         right.row = current.row;
         right.col = current.col+1;
         if (right.row>=0 && right.row<rows && right.col>=0 && right.col<cols) {
             if (maze[right.row][right.col]=='F') {
             while(maze[current.row][current.col]!='S') {
                 maze[current.row][current.col] = '*';
                 current = predecessor[current.row][current.col];
                 
             }
                 path = true;
                 break;
            }
          
             else if (maze[right.row][right.col]=='.' && 
                      visited[right.row][right.col]==0) {
                 visited[right.row][right.col] = 1;
                 predecessor[right.row][right.col]= current; 
                 q.add_to_back(right);
             }
        }
     }
    
    //delete all the dynamic pointers
             
    for (int i = 0; i < rows; i++)  {  
        delete [] predecessor[i];
        delete [] visited[i];  
    }  
     delete [] predecessor;  
     delete [] visited;
    
    //return if path is found
        
    if (path==true) {
        return 1;
    }
    else  {
        return 0;
    }
}


