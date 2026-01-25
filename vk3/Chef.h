
#define CHEF_H
#include <string>
using namespace std;

class Chef {
protected:
    std::string kokinNimi;
public:
    Chef(const std::string& nimi);
    ~Chef();
    int teeSalaatti(int ainekset);
    int teeKeitto(int ainekset);
};

class ItalianChef : public Chef {
private:
    std::string salasana;
    int jauhot;
    int vesi;
    int teePizza(int j,int v);
public:
    ItalianChef(const std::string&nimi, int j,int v);
    ~ItalianChef();
    bool kysySalainen(const std::string& annettu);
};
