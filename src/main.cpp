#include <iostream>
#include <thread>
#include <mutex>


void swim(int i)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<i<<std::endl;
}

int main()
{
   std::cout<<"test"<<std::endl;
    std::thread t(swim, 2);
   std::cout<<"test2"<<std::endl;
    t.detach();
   std::cout<<"test3"<<std::endl; 
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<< "test 4"<<std::endl;
    return 0;
}