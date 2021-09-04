#include <iostream>
#include <vector>
#include <algorithm>
#include "swimmer.h"

bool compare(Swimmer *a, Swimmer *b)
{
    return a->getFinishTime() < b->getFinishTime();
}

int main()
{
    std::vector<Swimmer *> swim(6);
    std::string name;
    int speedMS;
    for(auto &s : swim)
    {
        std::cout<<"Enter name and speed swimmers: ";
        std::cin >> name >> speedMS;
        s = new Swimmer(name, speedMS);
    }


     for(auto &s : swim)
            s->start();

    bool end_swim{true};
    while(end_swim)
    {
        int col{0};
        for(const auto &s : swim)
        {
            if(s->isFinished())
                ++col;
        }   
        if(col == swim.size())
            end_swim = false;
    }


    std::sort(swim.begin(), swim.end(), compare);

    for(const auto &comp : swim)
        std::cout<<"The result of the swim: "<< comp->getName() <<" swam in " << comp->getFinishTime() <<" seconds"<<std::endl;
    
    for (auto si : swim)
        delete si;
}