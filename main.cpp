#include <iostream>
#include <fstream>

using namespace std;

int main() {
    //hello world
    ifstream myfile;
    myfile.open("/Users/andreahalenkamp/ClionProjects/Project3/patients.txt");

    string line;

    while ( getline(myfile,line,',') )
    {

    }
}