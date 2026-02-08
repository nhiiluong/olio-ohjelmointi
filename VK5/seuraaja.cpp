#include "seuraaja.h"

Seuraaja::Seuraaja(const std::string& uusiNimi)
    :nimi(uusiNimi),next(nullptr)
{
}

std::string Seuraaja::getNimi()const
{
    return nimi;
}
void Seuraaja::päivitys(const std::string& viesti)
{
    std::cout <<"Seuraaja" << nimi << "sai viestin: " << viesti << std::endl;
}

Seuraaja* Seuraaja::getNext()const
{
    return next;
}
void Seuraaja::setNext(Seuraaja* seuraava)
{
    next=seuraava;
}
