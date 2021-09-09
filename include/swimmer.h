#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

class Swim
{
protected:
    int _finishTime{0};
    int _howSwim{0};

public:
    static constexpr int swimmingPoll{100};
    int getFinishTime()
    {
        return _finishTime;
    }
};

class Swimmer : public Swim
{
    std::string _name{"No name"};
    int _speed{0};
    bool finish{false};
    std::thread t_start;
    static std::mutex m_print;

public:
    Swimmer(const std::string &name = "No name", int speed = 0) : _name(name), _speed(speed)
    {
    }

    const char *getName()
    {
        return _name.c_str();
    }
    bool isFinished()
    {
        return finish;
    }
    void start()
    {
        t_start = std::thread(std::ref(*this));
    }

    void operator()()
    {
        std::size_t time{0};
        while (_howSwim < Swim::swimmingPoll)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            _howSwim += _speed;
            ++time;
            m_print.lock();
            std::cout << "The swemmer " << _name << " swam " << ((_howSwim > Swim::swimmingPoll) ? 100 : _howSwim) << " meters" << std::endl;
            m_print.unlock();
        }

        _finishTime = time;
        m_print.lock();
        finish = true;
        std::cout << "The swemmer " << _name << " finished in " << _finishTime << " seconds" << std::endl;
        m_print.unlock();
    }

    ~Swimmer()
    {
        if (t_start.joinable())
            t_start.join();
    }
};
std::mutex Swimmer::m_print;