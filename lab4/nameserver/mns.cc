#include "mns.h"
#include <string>
#include <algorithm>
#include <map>
#include <utility>

using std::map;
using std::pair;
using std::find_if;
using std::make_pair;
using std::remove_if;

MNS::MNS(){};

void MNS::insert(const HostName& hn, const IPAddress& ip) {
    mns[hn] = ip;
}

bool MNS::remove(const HostName& hn) {
    map<HostName, IPAddress>::iterator it = find_if(mns.begin(), mns.end(), [&hn](const pair<HostName, IPAddress>& p) {
        return p.first == hn;
    });
    if (it != mns.end()) {
        mns.erase(it);
        return true;
    }
    return false;
}

IPAddress MNS::lookup(const HostName& hn) const {
    map<HostName, IPAddress>::iterator it = find_if(mns.begin(), mns.end(), [&hn](const pair<HostName, IPAddress>& p) {
        return p.first == hn;
    });
    if (it != mns.end()) {
        return it->second;
    }
    return NON_EXISTING_ADDRESS;
}