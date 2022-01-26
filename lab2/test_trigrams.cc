#include <stdio.h>
#include <iostream>
#include "trigrams.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string file_name;
    cin >> file_name;
    create_trigrams_file(file_name);
    vector<string> word_trigram = get_trigrams("hello");
    cout << word_trigram[0] << endl;
    cout << word_trigram[1] << endl;
    cout << word_trigram[2] << endl;
    return 0;
}