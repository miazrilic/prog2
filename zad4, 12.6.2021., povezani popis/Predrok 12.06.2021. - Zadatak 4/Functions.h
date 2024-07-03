#ifndef HEADER_H
#define HEADER_H

typedef struct covid {
	char *ime;
	char *prezime;
	struct detalji *osoba;
	struct covid* noviCvor;
}COVID;

typedef struct detalji {
	int brKontakti;
	int ocjena;
	unsigned int cijepljeni;
}DETALJI;


void UpisOsobe(COVID* );
void IspisOsobe(COVID* );
COVID* kreiranjeListe();
COVID* ubaciNoviCvor(COVID*);
COVID* PretragaPopisa(COVID*, int );
COVID* OslobadjanjeOsoba(COVID* );
void IspisZeljeneOsobe(COVID*);
#endif