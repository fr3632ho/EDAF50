#include "trigrams.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "dictionary.h"


#define WORD_SIZE 25

using std::string;
using std::vector;

Dictionary::Dictionary() {
	// setup 
	std::ifstream inputfile("table/words");

	words.resize(WORD_SIZE);

	string line;
	while (std::getline(inputfile, line)) {
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		// insert word into dictionary
		dictionary.insert(line);

		// create a word object
		vector<string> t = get_trigrams(line);

		Word word(line, t);

		int len = line.length();
		if (len <= 25) {
			words[len - 1].push_back(word);
		}
	}
}

bool Dictionary::contains(const string& word) const {
	return dictionary.find(word) != dictionary.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}

std::vector<std::vector<Word>> Dictionary::get_word_matrix() const {
	return words;
}
