#include "VerketteteListeTest.h"
#include "VerketteteListe.h"
//
// Created by vincent on 29.11.21.
//
void testeListe(){
    struct Elem * root = erzeuge_neue_liste();
    einfuegen(root,4);
    einfuegen(root, 5);
    einfuegen(root, 3);
    einfuegen(root, 10 );
    entnehme_kleinstes(root);
    entnehme_kleinstes(root);
    liste_freigeben(root);

}
