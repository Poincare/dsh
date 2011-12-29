#include "main.h"
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

void CommandOpts::execv(string command, char **args) {
    execv(command.c_str(), args);
}

void CommandOpts::execute() {
    int opt_size = (this->opts).size();
    cout << "Opt_size " << opt_size << endl;
    
    char *args[opt_size];
   
    for(int i = 0; i<opt_size; i++) {
        cout << (char *) (this->opts)[i].c_str() << endl;
    } 

}
