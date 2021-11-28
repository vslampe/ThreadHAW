#include <time.h>
#include <errno.h>
//
// Created by vincent on 28.11.21.
//
int get_random_int(int min_number, int max_number){
    return rand() % (max_number + 1 - min_number) + min_number
}

/* msleep(): Sleep for the requested number of milliseconds. */
int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}
