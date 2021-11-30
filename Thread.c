//
// Created by vincent on 28.11.21.
//
#include <pthread.h>
#include "Thread.h"
#include "Config.h"
#include "utils.h"
#include "Warteschlange.h"

/**
 * Diese Threads erzeugen kontinuierlich neue Ar-
beitspakete mit zufälligen Paketnummern im Bereich 0 bis 99. Existiert in der
Warteschlange schon ein Paket mit dieser Nummer, so soll das einzufügende
Paket verworfen werden. Nach dem Erzeugen eines neuen Arbeitspaketes soll
der Producer-Thread 200 ms 1 schlafen. Ist die Warteschlange schon bis zu ei-
nem Maximalwert QMAX=25 mit Paketen gefüllt, so soll der Producer-Thread
für eine Sekunde in den Zustand “blocked“ wechseln und danach seine Aufgabe
fortsetzen. Haben die Producer-Threads insgesamt 1000 Arbeitspakete erzeugt,
so sollen sie sich beenden.
 * @param count
 */
void *producer_thread(void *vptr){
    while (1) {
        int r_int = get_random_int(0, 99);
        arbeitspaket_einfuegen(r_int);
        msleep(200);
    }
}
void create_producer_threads(){
    pthread_t threads [ANZAHL_PROD_THREADS];
    for(int i = 0;  i< ANZAHL_PROD_THREADS; i++){
        const char *param = "Test Parameter";
        pthread_create(threads[i], NULL, producer_thread, (void * )param);
    }
}
/**
 * : Diese Threads nehmen kontinuierlich das Arbeit-
spaket mit der niedrigsten Nummer aus der Warteschlange und verarbeiten
es. Diese “Verarbeitung“ soll zwischen 500 und 2000 ms (zufällig) dauern. Der
Speicherplatz der Arbeitspakete muss dabei korrekt freigegeben werden. Ist die
Warteschlange leer, so sollen die Consumer-Threads blockieren bis wieder ein
Element in der Warteschlange ist. Realisieren Sie dies über eine Conditional-
Variable. Wurden alle maximal 1000 Arbeitspakete verarbeitet, sollen sich alle
Consumer-Threads gleichzeitig beenden. Überlegen Sie in Ihrem Konzept wie
Sie dies realisieren können
 * @param vptr
 * @return
 */
void * consumer_thread(void *vptr){
    while(1){
        if(warteschlange_ist_leer()){
            //TODO Implementieren mithilfe Consumer Variable (Status BLOCKED)
        }
        int arbeitspaket = arbeitspaket_nehmen();
        int verarbeitungsDauer = get_random_int(500, 2000);
        msleep(verarbeitungsDauer);
    }
}
void create_cons_threads(){
    pthread_t threads [ANZAHL_CONS_THREADS];
    for(int i = 0;  i< ANZAHL_CONS_THREADS; i++){
        const char *param = "Test Parameter";
        pthread_create(threads[i], NULL, producer_thread, (void * )param);
    }
}
/**
 * Dieser Thread gibt jede Sekunde den Inhalt der Warteschlan-
ge und die Gesamtanzahl der bisher verarbeiteten Arbeitspakete aus. Wurden
alle 1000 Arbeitspakete abgearbeitet, soll der Observer-Thread Ëndeäuf der Kon-
sole ausgeben und sich ebenfalls beendenDieser Thread gibt jede Sekunde den Inhalt der Warteschlan-
ge und die Gesamtanzahl der bisher verarbeiteten Arbeitspakete aus. Wurden
alle 1000 Arbeitspakete abgearbeitet, soll der Observer-Thread Ëndeäuf der Kon-
sole ausgeben und sich ebenfalls beenden
 */
void create_observer_thread(){
    int max_pakete_erreicht = 0;
    while(!max_pakete_erreicht){
        print_warteschlange();
        msleep(1000);
    }
}
