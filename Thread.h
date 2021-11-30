//
// Created by vincent on 28.11.21.
//

#ifndef THREAD_THREAD_H
#define THREAD_THREAD_H

void *producer_thread(void *vptr);
void create_producer_threads();
void * consumer_thread(void *vptr);
void create_cons_threads();
void create_observer_thread();

#endif //THREAD_THREAD_H
