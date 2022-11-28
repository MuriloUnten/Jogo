#pragma once

#include "Observer.hpp"


class TextControl : public Observer
{
private:
    std::string string;    

public:
    TextControl();
    ~TextControl();

    void handleKeyPressed(std::string key);
    void handleKeyReleased(std::string key);


    std::string getString() const;
    void resetString();
};