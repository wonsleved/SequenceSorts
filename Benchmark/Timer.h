#ifndef MYLAB2_TIMER_H
#define MYLAB2_TIMER_H

#include <ctime>

class ITimer {
public:
    virtual void    start() = 0;
    virtual double  stop()  = 0;
    virtual double  getElapsedTime() = 0;
};


class Timer : public ITimer
{
private:
    clock_t _start;
    clock_t _end;
public:
    Timer();

    void    start() override;
    double  stop()  override;
    double getElapsedTime() override;
    double getElapsedTimeInMs();

    Timer& operator = (const Timer&) = delete;
};



#endif
