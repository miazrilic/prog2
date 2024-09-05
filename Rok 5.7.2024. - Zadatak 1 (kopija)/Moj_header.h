


#ifndef HEADER_H
#define HEADER_H

#define MAX_PACIJENTI 10
#define MAX_DUZINA 100

// Struktura pregleda
struct Pregled {
    char datumPregleda[12]; // u obliku dd.mm.yyyy.
    char dijagnoza[MAX_DUZINA];
    char imeLijecnika[MAX_DUZINA];
};

// Struktura pacijenta s jednim pregledom
struct Pacijent {
    char imePacijenta[MAX_DUZINA];
    struct Pregled pregled;
};



//deklaracije funkcija
void unosPacijenta(struct Pacijent* );  //unos podataka za jednog pacijenta i njegov pregled.


void unosPregleda(struct Pregled* ); //unos podataka za pregled

#endif //HEADER_H 