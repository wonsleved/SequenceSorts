#include "Timer.h"

Timer::Timer() : _start(0), _end(0) {};


void Timer::start() {
    _start = clock();
}

double Timer::stop() {
    _end = clock();
    return getElapsedTime();
}

double Timer::getElapsedTime() {
    return difftime(_end, _start);
}

double Timer::getElapsedTimeInMs() {
    return getElapsedTime() / CLOCKS_PER_SEC;
}

