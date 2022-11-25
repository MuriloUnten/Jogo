#include "Timer.hpp"


Timer::Timer(float newLimit)
{
    limit = newLimit;
    elapsedTime = 0.0f;
}


Timer::~Timer()
{

}


void Timer::setLimit(const float newLimit)
{
    limit = newLimit;
}


const float Timer::getLimit() const
{
    return limit;
}


void Timer::restart()
{
    elapsedTime = 0.0f;
}


void Timer::update(const float dt)
{
    elapsedTime += dt;
    if(elapsedTime > limit)
        //elapsedTime = limit;
        restart();
}


const float Timer::getElapsedTime() const
{
    return elapsedTime;
}