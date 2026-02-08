#include <iostream>
#include "notifikaattori.h"
#include "seuraaja.h"

int main()
{
    Notifikaattori n;

    Seuraaja s1("A");
    Seuraaja s2("B");
    Seuraaja s3("C");

    n.lisää(&s1);
    n.lisää(&s2);
    n.lisää(&s3);

    n.tulosta();

    n.postita("Tama on viesti 1");

    n.poista(&s2);

    n.postita("Tama on viesti 2");

    return 0;
}
