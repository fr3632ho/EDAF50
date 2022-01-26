#ifndef DICTIONARY_H
#define DICTIONARY_H

#define WORD_SIZE 25


#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "word.h"
#include "trigrams.h"

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	std::vector<std::vector<Word>> get_word_matrix() const;
private:
	std::unordered_set<std::string> dictionary;
	std::vector<std::vector<Word>> words;
};

#endif