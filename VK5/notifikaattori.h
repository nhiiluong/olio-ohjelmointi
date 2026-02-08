#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include <string>
#include "seuraaja.h"

class Notifikaattori
{
private:
    Seuraaja* seuraajat; //listan alku

public:
    Notifikaattori();
    ~Notifikaattori();

    void lisää(Seuraaja* uusi);
    void poista(Seuraaja* poistettava);

    void tulosta()const;
    void postita(const std::string& viesti);
};

#endif // NOTIFIKAATTORI_H
