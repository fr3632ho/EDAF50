#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) {
	// setup
	this->word = w;
	this->trigrams = t;
}

string Word::get_word() const {
	return word;
}

std::vector<std::string> Word::get_word_trigrams() const {
	return trigrams;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int count = 0;
	int i = 0, j = 0;
	while (i < trigrams.size() && j < t.size()) {
		int comp = trigrams[i].compare(t[j]);
		if (comp == 0) {
			count++;
			j++;
		}
		else if (comp < 0)
		{
			i++;
		}
		else {
			j++;
		}
		
	}
	return count;
}
