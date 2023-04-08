#include <string>
#include <iostream>
#include <vector>
using namespace std;
#include "pollution.h"

//pollution only starts in industrial zone
void getpollution(vector<vector<Cell>>& regions)
{
    for (int i = 0; i < regions.size(); ++i)
    {
        for (int j = 0; j < regions[0].size(); ++j)
        {
            regions[i][j].pollution = regions[i][j].population;
            int pollution = regions[i][j].pollution;
            spreadpollution(regions,i,j,pollution);
        }
    }
};

//arguments: 2D arrays of the layout/cell | the 2D arrays size cell.size() and cell[0].size | cell.pollution
void spreadpollution(vector<vector<Cell>>& regions, int row, int col, int pollution)
{
    if(row < 0 || col < 0 || row >= regions.size() || col >= regions[0].size())
    {
        return; //out of bound
    }
    if (pollution <= 0 || regions[row][col].pollution  >= pollution) 
    {
        return; 
        //pollution stop spreading when pollution is equal
        //and when pollution of adjacent cell is equal pollution spreading
    }

    //the cell gets pollution
    regions[row][col].pollution = pollution;
    spreadpollution(regions, row, col-1 , pollution-1); //left
    spreadpollution(regions, row, col+1, pollution-1); //right
    spreadpollution(regions, row+1, col, pollution-1); //top
    spreadpollution(regions, row-1, col, pollution-1); //bottom
    spreadpollution(regions, row+1, col-1, pollution-1); //diagonal left top
    spreadpollution(regions, row+1, col-1, pollution-1); //diagonal right top
    spreadpollution(regions, row-1, col-1, pollution-1); //diagonal left bottom
    spreadpollution(regions, row-1, col+1, pollution-1); //diagnoal right bottom

};

//total pollution
int totalpollution(vector<vector<Cell>>& regions)
{
    int totalpollution = 0;
    for(int i = 0; i < regions.size(); ++i)
    {
        for(int j = 0; j < regions[0].size(); ++i)
        {
            totalpollution += regions[i][j].pollution;
        }
    }
    return totalpollution;
};

//dispay pollution layout