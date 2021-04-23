#include "Philosophers.h"
#include <thread>
#include <iostream>
#include <iomanip>

std::mutex g_lockprint;

Philosophers::Philosophers(std::string n, table const& t, const chopstick& l, const chopstick& r) :
    name(n), dinnertable(t), left_chopstick(l), right_chopstick(r), life(&Philosophers::dine, this)
{
}

Philosophers::~Philosophers()
{
    life.join();
}

void Philosophers::dine()
{
    while (!dinnertable.ready);//this is using the atomic var to start the process at the same time

    for(int i=0; i<6;i++)
    {
        think();
        eat();
    }
}


void Philosophers::eat()
{
    std::lock(const_cast<chopstick&>(left_chopstick).mutex, const_cast<chopstick&>(right_chopstick).mutex);

    std::lock_guard<std::mutex> left_lock(const_cast<chopstick&>(left_chopstick).mutex, std::adopt_lock);
    std::lock_guard<std::mutex> right_lock(const_cast<chopstick&>(right_chopstick).mutex, std::adopt_lock);

    print(" started eating.");//getting some warning here, not sure why. Net says its a visual studio bug

    static thread_local std::uniform_int_distribution<> dist(1, 5);//random time for eating
    std::this_thread::sleep_for(std::chrono::milliseconds(dist(rng) * 1000));

    print(" finished eating.");//getting some warning here, not sure why. Net says its a visual studio bug
}

void Philosophers::think()
{

    print(" is thinking. ");

    static thread_local std::uniform_int_distribution<> wait(1, 3);
    std::this_thread::sleep_for(std::chrono::milliseconds(wait(rng) * 1000));

    print(" is done thinking. ");
}

void Philosophers::print(const std::string& text)
{
    std::unique_lock<std::mutex> cout_lock(g_lockprint);// locks cout so printing is proper
    std::cout << std::left << std::setw(10) << std::setfill(' ') << name << text << std::endl;
}