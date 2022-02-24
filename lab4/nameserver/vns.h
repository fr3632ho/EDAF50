#include <vector>
#include "nameserverinterface.h"

class VNS : public NameServerInterface {
public:
    VNS();
    void insert(const HostName& hn, const IPAddress& ip) override;
    bool remove(const HostName& hn) override;
    IPAddress lookup(const HostName&) const override;
private:
    std::vector<std::pair<HostName, IPAddress > > vns;
};