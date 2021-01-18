#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> data(0);
std::atomic<bool> ready(false);

void producer() {
	data.store(42, std::memory_order_relaxed); // must be executed before next "store release"
	ready.store(true, std::memory_order_release);
}
void consumer() {
	int r;
	while (!ready.load(std::memory_order_acquire)) {
	}
	r = data.load(std::memory_order_relaxed);  // must be executed after previous "load acquire"
	printf("data = %d\n",r);
}

int main()
{
	std::thread t1(producer);
	std::thread t2(consumer);

	t1.join();
	t2.join();
}
