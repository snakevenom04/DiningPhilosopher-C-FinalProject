#include <mutex>

struct chopstick
{
	std::mutex mutex;
};