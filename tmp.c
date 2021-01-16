#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> data = 0;
std::atomic<bool> ready(false);
constexpr int TIME_TO_SLEEP = 3000;

void sender() {
	data.store(42, std::memory_order_relaxed); // must be executed before next STORE
	std::this_thread::sleep_for(std::chrono::milliseconds(TIME_TO_SLEEP));
	ready.store(true, std::memory_order_relaxed);
}
void receiver() {
	int r;
	while (!ready.load(std::memory_order_relaxed)) {
	}
	r = data.load(std::memory_order_relaxed);  // must be executed after previous LOAD
	printf("data = %d\n",r);
}

int main()
{
	std::thread t1(sender);
	std::thread t2(receiver);

	t1.join();
	t2.join();
}



