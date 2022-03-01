#include "umns.h"
#include <string>
#include <algorithm>
#include <unordered_map>
#include <utility>

using std::unordered_map;
using std::pair;
using std::find_if;
using std::make_pair;
using std::remove_if;

UMNS::UMNS(){};

void UMNS::insert(const HostName& hn, const IPAddress& ip) {
    umns.insert(make_pair(hn, ip));
}

bool UMNS::remove(const HostName& hn) {
    return umns.erase(hn) > 0;
}

IPAddress UMNS::lookup(const HostName& hn) const {
    auto it = umns.find(hn);
    if(it != umns.end()){
        return it->second;
    }
    else { 
        return NON_EXISTING_ADDRESS;
    }
}