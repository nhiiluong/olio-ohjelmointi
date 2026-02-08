#include "notifikaattori.h"
#include <iostream>

Notifikaattori::Notifikaattori()
    : seuraajat(nullptr)
{
}

Notifikaattori::~Notifikaattori()
{
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen != nullptr) {
        Seuraaja* seuraava = nykyinen->getNext();
        delete nykyinen;
        nykyinen = seuraava;
    }
}

void Notifikaattori::lisää(Seuraaja* uusi)
{
    if (uusi == nullptr) return;

    uusi->setNext(seuraajat);
    seuraajat = uusi;
}

void Notifikaattori::poista(Seuraaja* poistettava)
{
    if (poistettava == nullptr || seuraajat == nullptr) return;

    if (seuraajat == poistettava) {
        seuraajat = seuraajat->getNext();
        delete poistettava;
        return;
    }

    Seuraaja* edellinen = seuraajat;
    Seuraaja* nykyinen = seuraajat->getNext();

    while (nykyinen != nullptr) {
        if (nykyinen == poistettava) {
            edellinen->setNext(nykyinen->getNext());
            delete nykyinen;
            return;
        }
        edellinen = nykyinen;
        nykyinen = nykyinen->getNext();
    }
}

void Notifikaattori::tulosta() const
{
    std::cout << "Seuraajat:" << std::endl;
    Seuraaja* nykyinen = seuraajat;

    while (nykyinen != nullptr) {
        std::cout << "-" << nykyinen->getNimi() << std::endl;
        nykyinen = nykyinen->getNext();
    }
}

void Notifikaattori::postita(const std::string& viesti)
{
    Seuraaja* nykyinen = seuraajat;

    while (nykyinen != nullptr) {
        nykyinen->päivitys(viesti);
        nykyinen = nykyinen->getNext();
    }
}
