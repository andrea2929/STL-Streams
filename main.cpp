#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Patient {
    string fname;
    string mname;
    string lname;
    string suffix;
    vector<string> ailments;
    string doctor;
    bool treated;
    int priority;
};

vector<Patient> readfile(string filename) {

    ifstream myfile;
    myfile.open(filename);

    string line;

    vector<Patient> patients(3);
    Patient current;
    int n = 0;

    while ( getline(myfile,line) )
    {

        if (!line.empty()) {
            if (!line.substr(0,line.find(":")).compare("firstName"))
                current.fname = line.substr(line.find(":") + 1);
            if (!line.substr(0,line.find(":")).compare("middleName"))
                current.mname = line.substr(line.find(":") + 1);
            if (!line.substr(0,line.find(":")).compare("lastName"))
                current.lname = line.substr(line.find(":") + 1);
            if (!line.substr(0,line.find(":")).compare("suffix"))
                current.suffix = line.substr(line.find(":") + 1);
            if (!line.substr(0,line.find(":")).compare("doctor"))
                current.doctor = line.substr(line.find(":") + 1);
        }
        else {
            patients[n] = current;
            n++;
        }
    }

    patients[n] = current;

    return patients;
}

void printPatients(vector<Patient> patients) {

    for(int i = 0; i < patients.size(); i++) {
        cout << patients[i].fname
             << " "
             << patients[i].mname
             << " "
             << patients[i].lname
             << " goes to doctor "
             << patients[i].doctor
             << endl;
    }
}

int main() {
    vector<Patient> p = readfile("/Users/andreahalenkamp/ClionProjects/Project3/patients.txt");

    printPatients(p);
}