#include "Table.h"
#include <random>
#include <string>

class Philosophers
{
private:
    std::string const name;
    table const& dinnertable;//reference to the array of chopsticks and the atomic value
    
    const chopstick& left_chopstick;
    const chopstick& right_chopstick;

    std::thread life; //This will start each object on its own thread
    std::mt19937 rng{ std::random_device{}() }; // rng will be used for random time generation

    void eat();
    void think();
    void print(const std::string& text);

public:
    Philosophers(std::string n, table const& t, const chopstick& l, const chopstick& r);

    ~Philosophers();//deconstructor to join the threads once this is done

    void dine();// this will start the process


 
};