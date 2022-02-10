#ifndef TAG_REMOVER
#define TAG_REMOVER

#include <iostream>

class TagRemover {
public:
    TagRemover(std::istream &instream);
    void print(std::ostream &out);
    void untag() const;
    void translate() const;
};

#endif