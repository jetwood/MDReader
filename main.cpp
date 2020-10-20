#include <iostream>
#include <regex>
#include "regexRules.h"

int main(int argc, char **argv) {
    using namespace std;
    if (argc < 2){
        cerr << "Usage: " << argv[0] << " should have two arguments!\n";
        exit(EXIT_FAILURE);
    }
    
    ifstream fIn;

    fIn.open(argv[1], ios_base::in);
    if (!fIn.is_open())
    {
        cerr << "Could not open " << argv[1] << endl;
        fIn.clear();
    }

    ofstream fOut;
    string fileName = argv[2];
    if (!regex_match(argv[2],regex(".*\\.html")))
        fileName += ".html";

    fOut.open(fileName, ios_base::out|ios_base::trunc);
    if (!fOut.is_open())
    {
        cerr << "Opening " << argv[2] << "is failed." << endl;
        fOut.clear();
    }

    string copy = copyFile(fIn);
    code_block(copy);
    blockQuote(copy);
    unordered_list(copy);
    fOut << copy;
    
    return 0;
}
