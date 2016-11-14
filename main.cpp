#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream myfile;
    myfile.open("/Users/andreahalenkamp/ClionProjects/Project3/patients.txt");

    string line;

    while ( getline(myfile,line,',') )
    {
        cout << line << endl;
    }
}