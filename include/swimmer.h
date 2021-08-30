#pragma once
#include <iostream>
#include <string>

class Swim
{
protected:
    int _finishTime{0};
    int _howSwim{0};
};

class Swimmer : Swim
{
    std::string _name{"No name"};
    int _speed{0};
    bool finish{false};
    
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
    bool isFinished()
    {
        return finish;
    }

    void operator()(int time)
    {
        _howSwim += _speed;
        if(_howSwim >= 100)
        {
            finish = true;
            _finishTime = time;
            std::cout<<"The swemmer "<<_name<<" finished in "<<_finishTime<<" seconds"<<std::endl;
        }
        else
        {
            std::cout<<"The swemmer "<<_name<<" swam "<<_howSwim<<" meters"<<std::endl;
        }
        
    }
};