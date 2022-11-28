#include "TextControl.hpp"


TextControl::TextControl():
Observer()
{

}


TextControl::~TextControl()
{

}


void TextControl::handleKeyPressed(std::string key)
{
    if (key == "Enter" || 
        key == "Right" || 
        key == "Left" || 
        key == "Up" || 
        key == "Down" || 
        key == "Escape" || 
        key == "Control" || 
        key == "Shift" || 
        key == "RControl" || 
        key == "RShift" || 
        key == "Tab"||
        key == "Unknown")
        return;

    if (key == "BackSpace")
    {
        if (string.size() > 0)
            string.pop_back();
    } 

    else if (key == "Space")
    {
        string += " ";
    }

    else
    {
        string += key;
    }
}


void TextControl::handleKeyReleased(std::string key)
{

}


std::string TextControl::getString() const
{
    return string;
}


void TextControl::resetString()
{
    string = "";
}