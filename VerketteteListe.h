//
// Created by vincent on 28.11.21.
//

#ifndef THREAD_VERKETTETELISTE_H
#define THREAD_VERKETTETELISTE_H
struct Elem* erzeuge_neues_element();
struct Elem* erzeuge_neue_liste();
void liste_freigeben(struct Elem* root);
void einfuegen( struct Elem *root, int number);
struct Elem * entnehme_kleinstes(struct Elem *root);
#endif //THREAD_VERKETTETELISTE_H


