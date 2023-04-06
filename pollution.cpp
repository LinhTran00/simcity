#include <string>
#include <iostream>
#include <vector>
using namespace std;

void spreadpollution(vector<vector<int>> &layout, int row, int col, int pollution)
{
    if()

    layout[row][col] = pollution;
    spreadpollution(layout, row, col-1 , pollution-1); //left
    spreadpollution(layout, row, col+1, pollution-1); //right
    spreadpollution(layout, row+1, col, pollution-1); //top
    spreadpollution(layout, row-1, col, pollution-1); //bottom
    spreadpollution(layout, row+1, col-1, pollution-1); //diagonal left top
    spreadpollution(layout, row+1, col-1, pollution-1); //diagonal right top
    spreadpollution(layout, row-1, col-1, pollution-1); //diagonal left bottom
    spreadpollution(layout, row-1, col+1, pollution-1); //diagnoal right bottom

};