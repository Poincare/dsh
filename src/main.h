#include <string>
#include <vector>

using namespace std;
class CommandOpts {
    public:
        string command;    
        vector<string> opts;
  
        void execute(void);
};
