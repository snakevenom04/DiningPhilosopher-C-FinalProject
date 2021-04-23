#ifndef Chopsticks_h
#define Chopsticks_h

#include <mutex>

struct chopstick
{
	std::mutex mutex;
};

#endif
