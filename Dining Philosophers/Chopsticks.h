#ifndef CHOPSTICKS_H
#define CHOPSTICKS_H
#include <mutex>

struct chopstick
{
	std::mutex mutex;
};

#endif
