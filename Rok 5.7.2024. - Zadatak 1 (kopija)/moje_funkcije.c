
///////
///definicije funkcija iz Moj_header.h
#include<stdio.h>
#include "Moj_header.h"
void unosPacijenta(struct Pacijent* pacijent){
    getchar();
    scanf(" %[^\n]",pacijent->imePacijenta);
    unosPregleda(&(pacijent->pregled));
}
void unosPregleda(struct Pregled* pregled){
    getchar();
    scanf(" %[^\n]",pregled->datumPregleda);
    getchar();
    scanf(" %[^\n]",pregled->dijagnoza);
    getchar();
    scanf(" %[^\n]",pregled->imeLijecnika);
}