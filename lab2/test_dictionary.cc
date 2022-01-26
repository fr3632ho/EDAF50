#include <stdio.h>
#include <iostream>
#include <fstream>
#include "trigrams.h"
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string file_name;
    cin >> file_name;
    Dictionary d;
    std::ifstream inputfile(file_name);
    string line;
    while (std::getline(inputfile, line)) {
        cout << "word \"" << line << "\" in dict := " << d.contains(line) << endl;
    }

    vector<vector<Word>> w = d.get_word_matrix();
    cout << endl;
    cout << line.max_size() << endl;
    for (int i = 0; i < 25; i++) {
        cout << "length of word(s) := " << i << " => ";
        for (int j = 0; j < 5; j++) {
            cout << w[i][j].get_word() << ", ";
        }
        cout << endl;
    }    
    return 0;
}