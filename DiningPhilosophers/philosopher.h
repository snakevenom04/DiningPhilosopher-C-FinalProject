#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H


#include "table.h"
#include <random>
#include <string>

class Philosopher
{
private:
    std::string const name;
    Table const& dinnertable;//reference to the array of chopsticks and the atomic value
    
    const Chopstick& left_chopstick;
    const Chopstick& right_chopstick;

    std::thread life; //This will start each object on its own thread
    std::mt19937 rng{ std::random_device{}() }; // rng will be used for random time generation

    void eat();
    void think();
    void print(const std::string& text);

public:
    Philosopher(std::string n, Table const& t, const Chopstick& l, const Chopstick& r);

    ~Philosopher();//deconstructor to join the threads once this is done

    void dine();// this will start the process


 
};

#endif