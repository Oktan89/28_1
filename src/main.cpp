#include <iostream>
#include <thread>
#include <mutex>

void swim()
{
    std::cout<<"swim"<<std::endl;
}

int main()
{
    std::thread t(swim);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(4));
}