//
// Created by vincent on 28.11.21.
//

#ifndef THREAD_WARTESCHLANGE_H
#define THREAD_WARTESCHLANGE_H

#endif //THREAD_WARTESCHLANGE_H

/**
 * Überprüft ob es bereits ein Element in der Warteschlange gibt, mit dem Int aus dem Parameter
 *
 * @return
 */
int paket_existiert(int);
int qmax_erreicht();
void arbeitspaket_einfuegen(int);
int arbeitspaket_nehmen();
int warteschlange_ist_leer();
int print_warteschlange();