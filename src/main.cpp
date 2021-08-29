#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "swimmer.h"

void swim()
{
    std::cout<<"swim"<<std::endl;
}

int main()
{
    std::vector<Swimmer*> swim(6);

    for(auto &s : swim)
        s = new Swimmer;
    
    for(auto s : swim)
        std::cout<<s->getName();

    for(auto si : swim)
        delete si;


 
}