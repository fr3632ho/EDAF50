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
    umns[hn] = ip;
}

bool UMNS::remove(const HostName& hn) {
    unordered_map<HostName, IPAddress>::iterator it = find_if(umns.begin(), umns.end(), [&hn](const pair<HostName, IPAddress>& p) {
        return p.first == hn;
    });

    if (it != umns.end()) {
        umns.erase(it);
        return true;
    }
    return false;
}

IPAddress UMNS::lookup(const HostName& hn) const {
    unordered_map<HostName, IPAddress>::iterator it = find_if(umns.begin(), umns.end(), [&hn](const pair<HostName, IPAddress>& p) {
        return p.first == hn;
    });
    if (it != umns.end()) {
        return it->second;
    }
    return NON_EXISTING_ADDRESS;
}