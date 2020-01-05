/* 
mazeio.cpp

Author:

Short description of this file:
*/

#include <iostream>
#include <fstream>
#include "mazeio.h"
#include <cstdlib>

using namespace std;

/*************************************************
 * read_maze:
 * Read the maze from the given filename into a 
 *  2D dynamically  allocated array.
 * 
 * Return the pointer to that array.
 * Return NULL (a special address) if there is a problem, 
 * opening the file or reading in the integer sizes.
 *
 * The first argument is the filename of the maze input.
 *  You should use an ifstream to open and read from this
 *  file.
 *
 * We also pass in two pointers to integers. These are
 * output parameters (i.e. declared by the caller and 
 * passed-by-reference for this function to fill in).
 * Fill the integers pointed to by these arguments
 * with the number of rows and columns 
 * read (the first two input values).
 *
 *************************************************/
char** read_maze(char* filename, int* rows, int* cols) 
{
   // FILL THIS IN
    
    ifstream inFile;
    int rw, cl;
    
    inFile.open(filename, ios::in);
    
    if(inFile.fail()){
         return NULL;   
    }
    
    inFile>>rw;
    inFile>>cl;
    if(inFile.fail()){
         return NULL;
    }
    *rows = rw;
    *cols = cl;
    
    char ** maze = new char*[rw];
    
    for(int i = 0; i < rw; i++){
        maze[i] = new char [cl];    
    }
    
    char x;
    for(int i = 0; i<rw; i++){
        for(int j = 0; j<cl; j++){
            inFile>>x;
            maze[i][j] = x;
        }
    }
    
    inFile.close();
    
    return maze;
    
        
}

/*************************************************
 * Print the maze contents to the screen in the
 * same format as the input (rows and columns, then
 * the maze character grid).
 *************************************************/
void print_maze(char** maze, int rows, int cols) 
{
   cout<<rows<<" "<<cols<<endl;
    
    for(int i = 0; i < rows ; i++){
        for(int j = 0; j < cols; j++){
             cout<<maze[i][j];   
        }
        cout<<endl;
    }
    
}