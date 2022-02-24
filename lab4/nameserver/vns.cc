#include "vns.h"
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::find_if;
using std::make_pair;
using std::remove_if;

VNS::VNS(){}

void VNS::insert(const HostName& hn, const IPAddress& ip) {    
    vns.push_back(make_pair(hn, ip));
}

bool VNS::remove(const HostName& hn) {
    vector<pair<HostName, IPAddress> >::iterator it = find_if(vns.begin(), vns.end(), [&hn](const pair<HostName, IPAddress>& p) {
        return p.first == hn;
    });
    if (it != vns.end()) {
        vns.erase(it);
        return true;
    }
    return false;
}

IPAddress VNS::lookup(const HostName& hn) const {
    vector<pair<HostName, IPAddress> >::iterator it = find_if(vns.begin(), vns.end(), [&hn](const pair<HostName, IPAddress>& p) {
        return p.first == hn;
    });
    if (it != vns.end()) {
        return it->second;
    }
    return NON_EXISTING_ADDRESS;
}