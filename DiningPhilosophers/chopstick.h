#ifndef CHOPSTICK_H
#define CHOPSTICK_H

#include <mutex>

struct Chopstick
{
	std::mutex mutex;
};


#endif
