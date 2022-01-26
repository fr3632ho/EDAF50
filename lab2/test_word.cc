#include <stdio.h>
#include <iostream>
#include <fstream>
#include "trigrams.h"
#include "word.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string file_name;
    cin >> file_name;
    std::ifstream inputfile(file_name);

    vector<Word> words;
    string line;
    while (std::getline(inputfile, line)) {
        Word w(line, get_trigrams(line));
        words.push_back(w);
    }
    inputfile.close();

    for (Word w : words) {
        cout << w.get_word() << endl;
    }
    cout << endl;

    for (int i = 0; i < words.size(); i++) {
        cout << "\nTESTING MATCHES FOR WORD => " << words[i].get_word() << endl;
        for (int j = i + 1 ; j < words.size(); j++) {
            cout << words[j].get_word() << " MATCHES := " <<words[i].get_matches(words[j].get_word_trigrams()) << endl;
        }
    }

    return 0;
}