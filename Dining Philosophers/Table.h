#ifndef TABLE_H
#define TABLE_H


#include "Chopsticks.h"
#include <array>
#include <atomic>

struct table
{
	std::atomic<bool> ready{ false };//Trying atomic to synchronise the starting point of each thread.

	std::array<chopstick, 5> chopsticks;
};

#endif
