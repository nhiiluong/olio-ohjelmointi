#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <string>
#include <iostream>

class Seuraaja
{
private:
    std::string nimi;
    Seuraaja* next;

public:
    Seuraaja(const std::string& uusiNimi);

    std::string getNimi() const;

    void päivitys(const std::string& viesti);

    Seuraaja* getNext()const;
    void setNext(Seuraaja* seuraava);
};

#endif // SEURAAJA_H
