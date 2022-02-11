#ifndef TAG_REMOVER
#define TAG_REMOVER

#include <iostream>
#include <string>

class TagRemover {
public:
    TagRemover(std::istream &instream);
    void print(std::ostream &out);
    void untag();
    void translate();
private:
    std::string html;
};

#endif