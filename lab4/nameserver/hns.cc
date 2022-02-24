#include "hns.h"
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::find_if;
using std::make_pair;
using std::remove_if;

HNS::HNS(int n){
    // extra capacity for load
    for (int i = 0; i<n+(n*0.25); i++) {
        vector<pair<HostName, IPAddress> > v(0);
        hns.push_back(v);
    }
}

void HNS::insert(const HostName& hn, const IPAddress& ip) {
    
}

bool HNS::remove(const HostName& hn) {
    
}

IPAddress HNS::lookup(const HostName& hn) const {
    
}