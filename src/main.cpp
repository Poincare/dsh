#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include <unistd.h>

#include "main.h"

#define MAX_LEN 1024

using namespace std;


string SYMBOL = "$";
int complete = 0;

void fillCOObject(string command, vector<string> opts, CommandOpts &co);

//read command line from STDIN, and fill out object
void fillCO(CommandOpts &toFill) {
    string command;
    vector<string> opts;

    string entireLine;

    getline (cin, entireLine);
    stringstream lineParser;
    
    lineParser.clear();
    lineParser.str("");
    lineParser << entireLine;

    lineParser >> command;

    string opt;

    //parse the line that just came in
    while(lineParser >> opt) {
        cout << "Reading" << endl;

        lineParser >> opt;
        opts.push_back(opt); 
    }

    //fill out object with the stuff we just got
    fillCOObject(command, opts, toFill);
}

//write the shell symbol; currently defaulted to $
//TODO give options for symbols
void writeSymbol() {
    cout << SYMBOL << " ";
}

//Fill out CommandOpts object
//TODO don't use vector<string>
void fillCOObject(string command, vector<string> opts, CommandOpts &co) {
    co.command = command;
    co.opts = opts;
}
 
void iterate(void) {
    CommandOpts COs;

    writeSymbol();
    
    fillCO(COs);

    if(!complete) {
        COs.execute();
    }
}

int main (void) {
    while(!complete) {
        iterate();
    }    
}
