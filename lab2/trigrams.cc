#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <boost/algorithm/string/join.hpp>

#define pb push_back

using std::vector;
using std::string;

using std::cout;
using std::endl;
using std::getline;

//using std::ofstream;
using std::ifstream;

vector<string> get_trigrams(const string& word) {
    vector<string> trigrams;
    int l = word.length() - 2;
    for (int i = 0; i < l; i++) {
        trigrams.pb(word.substr(i, 3));
    }
    std::sort(trigrams.begin(), trigrams.end());
    return trigrams;
}

string join_vector(vector<string> vec) {
    std::ostringstream string_stream;
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<string>(string_stream, " "));
    return string_stream.str();
}

vector<string> create_trigrams_list(string file_name) {
    ifstream input_file(file_name);

    vector<string> output;
    string line;
    while (getline(input_file, line)) {
        int l = line.length() - 2;
        // turn every word into lower case
        std::for_each(line.begin(), line.end(), [](char &c){
            c = ::tolower(c);
        });

        vector<string> trigrams = {line, std::to_string(l)};
        if (l > 0) {
            vector<string> temp_trigrams = get_trigrams(line);
            trigrams.insert(trigrams.end(), temp_trigrams.begin(), temp_trigrams.end());
        }
        
        output.pb(join_vector(trigrams));
    }
    std::sort(output.begin(), output.end());
    input_file.close();
    return output;
}

void create_trigrams_file(string filename) {
    vector<string> trigrams = create_trigrams_list(filename);
    std::ofstream outfile;
    outfile.open("words.txt");
    for (string s : trigrams) {
        outfile << s << endl;
    }
    outfile.close();
}

