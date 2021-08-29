#pragma once
#include <string>

class Swimmer
{
    std::string _name{"No name"};
    int _speed{0};
public:
    Swimmer(const std::string& name = "No name", int speed = 0) : _name(name), _speed(speed)
    {

    }
    int getSpeed()
    {
        return _speed;
    }
    const char* getName()
    {
        return _name.c_str();
    }
};