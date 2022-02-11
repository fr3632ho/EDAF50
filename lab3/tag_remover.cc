#include "tag_remover.h"

#include <iostream>
#include <sstream>
#include <regex>

TagRemover::TagRemover(std::istream &instream) {
    std::string line;
    while (getline(instream, line)) {
        if (!html.empty()) {
            html.append("\n");
        }
        html.append(line);                
    }
    
}

void TagRemover::print(std::ostream &out) {
    untag();
    translate();
    out << html;
}

void TagRemover::untag() {
    std::regex pattern("<[^>]*>");
    html = std::regex_replace(html, pattern, "");
    
    std::regex pattern_empty("[ ]+");
    html = std::regex_replace(html, pattern_empty, " ");
}

void TagRemover::translate() {
    std::regex lt("\\&lt");
    std::regex gt("\\&gt");
    std::regex nbsp("\\&nbsp");
    std::regex amp("\\&amp");

    html = std::regex_replace(html, lt, "<");
    html = std::regex_replace(html, gt, ">");
    html = std::regex_replace(html, nbsp, " ");
    html = std::regex_replace(html, amp, "&");
}