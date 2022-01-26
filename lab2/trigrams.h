
#ifndef TRIGRAMS
#define TRIGRAMS

#include <string>
#include <vector>


std::vector<std::string> get_trigrams(const std::string& word);

std::vector<std::string> create_trigrams_list(std::string file_name);

void create_trigrams_file(std::string filename);

#endif