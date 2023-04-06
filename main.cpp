//main.cpp


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Cell
{
    char type;
    int popullation;
    int pollution;
    int x;
    int y;
};

struct SimConfig { //struct for the configuration file
    string region_layout_filename;
    int time_limit;
    int refresh_rate;
};

struct Region { //struct for the csv file that has the region
    int size;
    vector<vector<char>> layout;
};

SimConfig readSimConfig(string filename) { //readin, parameter being what the user inputted
    SimConfig config;

    ifstream file(filename);

    if (!file.is_open()) { //if file cant be found, error message
        cerr << "Error: unable to open file " << filename << endl;
        exit(1); //exits program
    }

    string line;
    while (getline(file, line)) {
        int pos = line.find(":"); //reads in file with the same format as given (config1.txt)
        if (pos != string::npos) {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);

            if (key == "Region Layout") { //first section of the txt file starts with Region Layout
                config.region_layout_filename = value; //csv file to be read in as intial state
            } else if (key == "Time Limit") { //second section of the txt file starts with Time Limit
                config.time_limit = stoi(value); //how many time steps simulation will do
            } else if (key == "Refresh Rate") { //third section of the txt file starts with Refresh rate
                config.refresh_rate = stoi(value); //how often the program outputs current state
            }
        }
    }

    return config;
}

Region readRegionLayout(string filename) { //reading in csv file
    Region region;
    vector<vector<char>> layout;

    ifstream file(filename);

    if (!file.is_open()) { //same process as config file, if file doesnt exist/cant be found then error message
        cerr << "Error: unable to open file " << filename << endl;
        exit(1); //exits program
    }

    string line;
    while (getline(file, line)) { //initializing state, can be any size rectangle
        vector<char> row; //data structure as a vector to old state
        string cell;
        for (char c : line) {
            if (c == ',' || c == ' ' || c == '\t') {
                if (cell.size() > 0) {
                    row.push_back(cell[0]);
                    cell.clear();
                }
            } else {
                cell += c;
            }
        }

        if (cell.size() > 0) {
            row.push_back(cell[0]);
        }

        layout.push_back(row);
    }

    region.size = layout.size();
    region.layout = layout;

    return region;
}

int main() {
    string config_filename;
    cout << "Enter the configuration file name: "; //prompts user for config file name that includes csv file, time limit, and refresh rate
    cin >> config_filename; //reads in file name

    SimConfig config = readSimConfig(config_filename); //uses function to open config txt file
    Region region = readRegionLayout(config.region_layout_filename); //uses function to open region csv file

//cout to see if it read in file correctly
//    cout << "Time limit: " << config.time_limit << endl;
//    cout << "Refresh rate: " << config.refresh_rate << endl;
    cout << "Inital state layout:" << endl;

    for (int i = 0; i < region.size; i++) { //outputs inital state
        for (int j = 0; j < region.size; j++) {
            cout << region.layout[i][j] << " ";
        }

        cout << endl;
    }

//outputs state every refresh rate step


    return 0;
}

