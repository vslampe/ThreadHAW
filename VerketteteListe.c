//
// Created by vincent on 28.11.21.
//
#include <stdio.h>
#include <stdlib.h>

struct Elem {
    int val;
    struct Elem *next;
    struct Elem *prev;
};

/***
 * Erzeugt ein neues Element
 * @return
 */
struct Elem* erzeuge_neues_element(){
    return (struct Elem*)malloc(sizeof(struct Elem));
}
/***
 * Erzeugt eine neue leere Liste
 * @return
 */
struct Elem* erzeuge_neue_liste(){
    struct Elem * root = erzeuge_neues_element();
    root->val= -1;
    root->next = NULL;
    root->prev = NULL;
}
/**
 * Gibt den Speicher einer Liste frei mit free.
 * @param root
 */
void liste_freigeben(struct Elem* root){
    struct Elem *curr_elem = root->next;
    while(curr_elem != NULL){
        struct Elem * prev_element = curr_elem;
        curr_elem=curr_elem->next;
        free(prev_element);
    }
}
/**
 *
 * Sortiertes Einfügen in die Liste:
 * 1. Fall:Einfügen an das Ende der Liste,
 * 2. Fall:Einfügen zwischen zwei Elemente
 * @param e
 * @param root
 */
void einfuegen( struct Elem *root, int number) {

    struct Elem *curr_elem = root;
    while (curr_elem != NULL && curr_elem->val != number) {
        //Gültige Position erreicht
        if (curr_elem->val < number) {
            struct Elem *next_elem = curr_elem->next;
            //Element hat keinen Nachfolger
            if (next_elem == NULL) {
                struct Elem * e = erzeuge_neues_element();
                e->val=number;
                curr_elem->next = e;
                e->prev = curr_elem;
                return;
            }
            if(next_elem->val > number) {
                struct Elem * e = erzeuge_neues_element();
                e->val=number;
                curr_elem->next = e;
                e->next = next_elem;
                next_elem->prev = e;
                e->prev = curr_elem;
                return;
            }

        }
        curr_elem=curr_elem->next;
    }

}

/**
 * Um das kleinste Element zu entnehmen muss der next Zeiger des Root Elements auf das zweite Element
 * gesetzt werden. Dann muss der prev Zeiger des zweiten Elements auf root gesetzt werden.
 * Anschließend muss der Speicher freigegeben werden
 * @param e
 * @param root
 */
struct Elem * entnehme_kleinstes(struct Elem *root) {

    struct Elem *first = root->next;
    struct Elem *second = first->next;

    if (second == NULL && first == NULL) {
        printf("Error: Aus leerer Liste kann kein Element entnommen werden!");
    } else if (second == NULL) {
        root->next = NULL;
        return first;
    }
    second->prev = root;
    root->next = second;
    return first;
}
