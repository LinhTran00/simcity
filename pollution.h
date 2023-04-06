#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Cell 
{
    char type;
    int population;
    int pollution;
};

void getpollution(vector<vector<Cell>>& regions);
void spreadpollution(vector<vector<Cell>>& cell, int row, int col, int pollution);