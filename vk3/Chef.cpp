#include "Chef.h"
#include <iostream>
#include <algorithm>

//Chef luokan toteutukset

Chef::Chef(const std::string& nimi) : kokinNimi(nimi){
    std::cout << "[Chef] Konstruktori:" << kokinNimi <<std::endl;
}

Chef::~Chef(){
    std::cout << "[Chef] Destruktori: "<< kokinNimi << std::endl;

}

int Chef::teeSalaatti(int ainekset){
    std::cout <<kokinNimi << "tekee salaattia.." << std::endl;
    return ainekset / 5;
}

int Chef::teeKeitto(int ainekset){
    std::cout << kokinNimi << "keittää keittoa.." << std::endl;
    return ainekset / 3;
}

//luokan toteutukset

ItalianChef::ItalianChef(const std::string& nimi,int j,int v)
    : Chef(nimi),jauhot(j), vesi(v),salasana("pizza"){
    std::cout << "[ItalianChef] Konstruktori: " << kokinNimi << std::endl;
}

ItalianChef::~ItalianChef(){
    std::cout << "[ItalianChef] Destruktori:" << kokinNimi << std::endl;
}
int ItalianChef::teePizza(int j ,int v) {
    std::cout <<kokinNimi << "tekee pizzaa.." << std::endl;
    return std::min(j/5,v/5);
}
bool ItalianChef::kysySalainen(const std::string& annettu){
    if (annettu == salasana){
        std::cout << "salasana oikein" << std:: endl;
        std::cout << "Pizzoja:" << teePizza(jauhot,vesi) << std::endl;
        return true;
    }
    std::cout << " Väärä salasana!" << std::endl;
    return false;
}
