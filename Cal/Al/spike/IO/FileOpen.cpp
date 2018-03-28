#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// execute command: bin/ticket dd
int main(int argc, char ** argv)
{
    // can not write as "~/Downloads/.temp/...."
    string fileName= "/home/cc/Downloads/.temp/Workspace/Alex/Cal/Al/bin/routes.txt";
    ifstream inputFile;
    inputFile.open(fileName.c_str(), ifstream::in);
    if(!inputFile.is_open())
        cout << "open failed!" << endl;
    else
        cout << "open success" << endl;
    inputFile.close();

    return 0;
}
