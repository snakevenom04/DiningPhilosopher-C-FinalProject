#ifndef TABLE_H
#define TABLE_H

#include "chopstick.h"
#include <array>
#include <atomic>

struct Table
{
	std::atomic<bool> ready{ false };//Trying atomic to synchronise the starting point of each thread.

	std::array<Chopstick, 5> chopsticks;
};

#endif