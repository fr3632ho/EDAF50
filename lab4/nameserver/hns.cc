#include "hns.h"
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using std::find_if;
using std::hash;
using std::make_pair;
using std::pair;
using std::remove_if;
using std::size_t;
using std::vector;


HNS::HNS(int n){
    // extra capacity for load
    for (int i = 0; i<n+(n*0.25); i++) {
        vector<pair<HostName, IPAddress> > v(0);
        hns.push_back(v);
    }
}

size_t hash_host(const HostName& hn) {
    hash<HostName> hasher;
    return hasher(hn);
}

void HNS::insert(const HostName& hn, const IPAddress& ip) {
    int idx = std::abs((int)(hash_host(hn) % hns.size()));
    auto it = find_if(hns[idx].begin(), hns[idx].end(), [&hn](const pair<HostName, IPAddress>& p) {
        return p.first == hn;
    });
    if (it == hns[idx].end()) {
        hns[idx].push_back(make_pair(hn, ip));
    }
}

bool HNS::remove(const HostName& hn) {
    int idx = std::abs((int)(hash_host(hn) % hns.size()));
    auto it = remove_if(hns[idx].begin(), hns[idx].end(), [&hn](const pair<HostName, IPAddress>& p) {
        return p.first == hn;
    });
    if (it != hns[idx].end()) {
        hns[idx].erase(it, hns[idx].end());
        return true;
    }
    return false;
}

IPAddress HNS::lookup(const HostName& hn) const {
    int idx = std::abs((int)(hash_host(hn) % hns.size()));
    auto it = find_if(hns[idx].begin(), hns[idx].end(), [&hn](const pair<HostName, IPAddress>& p) {
        return p.first == hn;
    });
    if (it != hns[idx].end()) {
        return (*it).second;
    }
    return NON_EXISTING_ADDRESS;
}