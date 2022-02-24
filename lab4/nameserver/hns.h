#include "nameserverinterface.h"
#include <vector>

using std::vector;
using std::pair;

class HNS : public NameServerInterface {

public:
    HNS(int);
    void insert(const HostName& hn, const IPAddress& ip) override;
    bool remove(const HostName& hn) override;
    IPAddress lookup(const HostName&) const override;
private:
    vector<vector<pair<HostName, IPAddress> > > hns;
};