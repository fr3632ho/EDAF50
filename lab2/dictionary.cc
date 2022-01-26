#include "trigrams.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include "dictionary.h"


#define WORD_SIZE 25

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::pair;

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

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const {
	int len = word.length();
	if (len > 0 && len < 26) {
		if (len > 1) {
			for (Word w : words[len - 2]) {
				suggestions.push_back(w.get_word());
			}
		}
		for (Word w : words[len - 1]) {
			suggestions.push_back(w.get_word());
		}
		if (len < 25) {
			for (Word w : words[len]) {
				suggestions.push_back(w.get_word());
			}
		}
	}
}

int edit_distance(const string& w1, const string& w2) {
	int d[26][26];
	for (int i = 0; i < 26; i++) {
		d[i][0] = i;
		d[0][i] = i;
	}
	int alignCost = 0;
	for (int i = 1; i < w1.length() + 1; i++) {
		for (int j = 1; j < w2.length() + 1; j++) {
			if (w1[i - 1] == w2[j - 1]) {
				alignCost = 0;
			} else {
				alignCost = 1;
			}
			d[i][j] = std::min({d[i - 1][j - 1] + alignCost, d[i - 1][j] + 1, d[i][j - 1] + 1});
		}
	}
	return d[w1.length()][w2.length()];
}

struct by_edit {
	bool operator()(pair<int, string> const &a, pair<int, string> const &b) const {
		return a.first < b.first;
	}
};


void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const {
	// cout << edit_distance("book", "back") << " should be 2" << endl;
	// cout << edit_distance("help", "terminator") << " should be 9" << endl;
	// cout << edit_distance("hankypants", "motherland") << " should be 9" << endl;
	// cout << edit_distance("aleko", "tim") << " should be 5" << endl;
	// cout << "word is := " << word << ", number of suggestions := "<< suggestions.size() << endl;
	vector<pair<int, string>> pairs;
	pair<int, string> p; 
	for (string sugg : suggestions) {
		p = {edit_distance(word, sugg), sugg};
		pairs.push_back(p);
	}
	sort(pairs.begin(), pairs.end(), by_edit());
	// for (int i = 0; i < pairs.size() && i < 10; i++) {
	// 	cout << pairs[i].first << " " << pairs[i].second << endl;
	// } 
	suggestions.clear();
	for (pair<int, string> pp : pairs) {
		suggestions.push_back(pp.second);
	}
}

void Dictionary::trim_suggestions(vector<string>& suggestions) const {
	if (suggestions.size() > 5) {
		suggestions.resize(5);
	}
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

std::vector<std::vector<Word>> Dictionary::get_word_matrix() const {
	return words;
}
