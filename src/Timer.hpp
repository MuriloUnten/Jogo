#pragma once


class Timer
{
private:
    float elapsedTime;
    float limit;

public:
    Timer(float newLimit=0);
    ~Timer();

    void setLimit(const float newLimit);
    const float getLimit() const;

    void restart();
    void update(const float dt);
    const float getElapsedTime() const;
};