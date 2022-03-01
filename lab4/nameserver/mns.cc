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
    mns.insert(make_pair(hn, ip));
}

bool MNS::remove(const HostName& hn) {
    return mns.erase(hn) > 0;
}

IPAddress MNS::lookup(const HostName& hn) const {
    auto it = mns.find(hn);    
    if(it != mns.end()){
        return it->second;
    }
    else {
        return NON_EXISTING_ADDRESS;
    }
}