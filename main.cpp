#include <iostream>
#include <string>
#include <vector>

#include <unistd.h>

#include "main.h"

#define MAX_LEN 1024

using namespace std;


string SYMBOL = "$";
int complete = 0;

void CommandOpts::execute() {
    
}

void readLine(char *line) {
    cin.getline(line, MAX_LEN);
    
    if(!cin) {
        complete = 1;
        return;
    }
}

void writeSymbol() {
    cout << SYMBOL << " ";
}

CommandOpts fillCO(char *line) {
    string command;
    vector<string> opts;

    CommandOpts co;
    co.command = command;
    co.opts = opts;

    return co;
}
 
void iterate(void) {
    char line[MAX_LEN];

    writeSymbol();
    
    readLine(line);

    CommandOpts COs = fillCO(line);
    
    if(!complete) {
        COs.execute();
    }
}

int main (void) {
    while(!complete) {
        iterate();
    }    
}
