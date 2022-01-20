#include <iostream>
#include <fstream>
#include "coding.h"

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

int main(int argc, const char** argv) {
    cout << "Start of encoding" << endl;
    ifstream inputfile(argv[1]);
    ofstream myfile;
    myfile.open("encoded.txt");
    char c;
    while (inputfile.get(c)) {
        myfile.put(encode(c));
    }
    myfile.close();
    inputfile.close();
    cout << "End of encoding" << endl;
}