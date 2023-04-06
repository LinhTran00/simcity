#include <string>
#include <iostream>
#include <vector>
using namespace std;

//need to figure out agrument to pass in these functions. 

void spreadpollution(vector<vector<Cell>>& cell, int row, int col, int pollution)
{
    if(row < 0 || col < 0 || row >= cell.size() || col >= cell[0].size())
    {
        return; //out of bound
    }
    if (pollution <= 0 || cell[row][col] >= pollution)
    {
        return; 
        //pollution stop spreading when pollution is equal
        //and when pollution of adjacent celll is equal pollution spreading
    }

    //the celll gets pollution
    cell[row][col] = pollution;
    spreadpollution(cell, row, col-1 , pollution-1); //left
    spreadpollution(cell, row, col+1, pollution-1); //right
    spreadpollution(cell, row+1, col, pollution-1); //top
    spreadpollution(cell, row-1, col, pollution-1); //bottom
    spreadpollution(cell, row+1, col-1, pollution-1); //diagonal left top
    spreadpollution(cell, row+1, col-1, pollution-1); //diagonal right top
    spreadpollution(cell, row-1, col-1, pollution-1); //diagonal left bottom
    spreadpollution(cell, row-1, col+1, pollution-1); //diagnoal right bottom

};

// void displaypollution(vector<vector<Cell>> &cell, int)