/*
    Copyright (c) 2020 Victorien Elvinger
    Licensed under the zlib license (https://opensource.org/licenses/zlib).
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define TIME_BEFORE_SLEEPING 12
/*
 * \r           cursor at the begining of the line
 * \x1b[K       erase the line
 * \x1b[1;31m   light red
 * \x1b[0m      end of style
 */
#define FORMAT "\r\x1b[K\x1b[1;31m %s \x1b[0m"

const char *faces[] = {
    "😐",
    "😉",
    "😏",
    "😀"
};

const char *sleeping_face = "😴";
const char *fear_face = "😱";


void tamagotchi_awake();
void tamagotchi_bye();
void tamagotchi_sleep();


int main() {
    tamagotchi_awake();
    return 0; /* unreachable code */
}

void do_nothings() {}

void set_signals() {
    signal(SIGINT, &tamagotchi_bye);
    signal(SIGALRM, &tamagotchi_sleep);
    alarm(TIME_BEFORE_SLEEPING);
}

void tamagotchi_awake() {
    int i = 0;
    set_signals();
    while(1) {
        printf(FORMAT, faces[i]);
        fflush(stdout);
        sleep(2);
        i++;
        i = i % (sizeof(faces) / 8);
    }
}

void tamagotchi_bye() {
    signal(SIGALRM, &do_nothings); /* consume alarm signals */
    printf(FORMAT, fear_face);
    fflush(stdout);
    sleep(1);
    printf("\n");
    exit(0);
}

void tamagotchi_sleep() {
    printf(FORMAT, sleeping_face);
    fflush(stdout);
    signal(SIGINT, &do_nothings);
    pause();
    set_signals();
}

