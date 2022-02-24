#include "nameserverinterface.h"
#include <map>

class MNS : public NameServerInterface {
public:
    MNS();
    void insert(const HostName& hn, const IPAddress& ip) override;
    bool remove(const HostName& hn) override;
    IPAddress lookup(const HostName&) const override;
private:
    std::map<HostName, IPAddress> mns;
};