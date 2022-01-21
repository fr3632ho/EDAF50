#include <iostream>
#include <fstream>
#include "coding.h"

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

int main(int argc, const char** argv) {
    cout << "Start of decoding" << endl;
    ifstream inputfile(argv[1]);
    ofstream myfile;
    myfile.open("textfile.dec");
    char c;
    while (inputfile.get(c)) {
        myfile.put(decode(c));
    }
    myfile.close();
    inputfile.close();
    cout << "End of decoding" << endl;
}