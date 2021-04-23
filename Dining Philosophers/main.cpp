#include"Philosophers.h"

#include <thread>
#include <chrono>
#include <iostream>
#include <iomanip>




void dine()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Dinner started!" << std::endl;

    {
        table table;
        std::array<Philosophers, 5> philosophers
        {
           {
              { "Aristotle", table, table.chopsticks[0], table.chopsticks[1] },
              { "Platon",    table, table.chopsticks[1], table.chopsticks[2] },
              { "Descartes", table, table.chopsticks[2], table.chopsticks[3] },
              { "Kant",      table, table.chopsticks[3], table.chopsticks[4] },
              { "Nietzsche", table, table.chopsticks[4], table.chopsticks[0] },
           }
        };//object created and threads spawned

        table.ready = true;//atomic variable set to true all threads start working
        

    }//object destructor called, all threads joined.

    std::cout << "Dinner done!" << std::endl;
}

int main()
{
    dine();

    return 0;
}