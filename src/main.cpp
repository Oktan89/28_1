#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include "swimmer.h"

bool compare(Swimmer *a, Swimmer *b)
{
    return a->getFinishTime() < b->getFinishTime();
}

int main()
{
    int swimmingPoll{100};
    std::vector<Swimmer *> swim(6);
    std::string name;
    int speedMS;
    for(auto &s : swim)
    {
        std::cout<<"Enter name and speed swimmers: ";
        std::cin >> name >> speedMS;
        s = new Swimmer(name, speedMS);
    }
        

   
    std::vector<std::thread> swimers(swim.size());
    int k = 0;
    for (int i = 0; i < swimmingPoll && k < swimers.size(); ++i)
    {
        k = 0;
     
        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (int j = 0; j < swimers.size(); ++j)
        {
            if (swim[j]->isFinished())
            {
                ++k;
            }
            else
            {
                swimers[j] = std::thread(std::ref(*swim[j]), i);
                swimers[j].join();
            }
        }
    }

    std::sort(swim.begin(), swim.end(), compare);

    for(const auto &comp : swim)
        std::cout<<"The result of the swim: "<< comp->getName() <<" swam in " << comp->getFinishTime() <<" seconds"<<std::endl;
    
    for (auto si : swim)
        delete si;
}