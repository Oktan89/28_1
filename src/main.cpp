#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "swimmer.h"

int main()
{
    std::vector<Swimmer *> swim(3);

    /*for(auto &s : swim)
        s = new Swimmer("Test", 5);*/

    swim[0] = new Swimmer("Ruslan", 10);
    swim[1] = new Swimmer("Dima", 5);
    swim[2] = new Swimmer("Irina", 15);

    std::vector<std::thread> swimers(swim.size());
    int k = 0;
    for (int i = 0; i < 100 && k < swimers.size(); ++i)
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

    for (auto si : swim)
        delete si;
}