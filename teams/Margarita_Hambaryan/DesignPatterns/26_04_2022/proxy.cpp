#include <iostream>
#include <list>
#include <algorithm>

class OfficeInternetAcess {
public:
virtual void grantInternetAccess(std::string serverhost) = 0;
};

class RealInternetAccess: public OfficeInternetAcess {
public:

void grantInternetAccess(std::string serverhost) {
    std::cout << "Connecting to " << serverhost << "\n";  
}
};

class ProxyInternetAccess: public OfficeInternetAcess {
    private:
    OfficeInternetAcess* realaccess = new RealInternetAccess();
    std::list<std::string> bannedSites;  

    public:
    void grantInternetAccess(std::string serverName) {
        if (std::find(bannedSites.begin(), bannedSites.end(), serverName) != bannedSites.end()) {
                std::cout << "Access denied!\n";
        }else {
        realaccess->grantInternetAccess(serverName);
        }
    }
    void addingSites(std::string siteName) {
        this->bannedSites.push_back(siteName);
    }
};


int main() {
    ProxyInternetAccess* access1 = new ProxyInternetAccess();
    access1->addingSites("abc.com");
    access1->addingSites("def.com");
    access1->addingSites("ijk.com");

    access1->grantInternetAccess("abc.com");

    delete access1;
    return 0;
}