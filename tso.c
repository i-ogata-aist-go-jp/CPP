#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> x = 0;
std::atomic<int> y = 0;

constexpr int TIME_TO_SLEEP = 3;

void th1() {
	int r1;
	y.store(1, std::memory_order_release); // can be executed after LOAD
	std::this_thread::sleep_for(std::chrono::milliseconds(TIME_TO_SLEEP));
	r1 = x.load(std::memory_order_seq_cst); // can be executed before STORE
	printf("r1 = %d\n",r1);
}
void th2() {
	int r2;
	x.store(1, std::memory_order_release); // can be executed after LOAD
	std::this_thread::sleep_for(std::chrono::milliseconds(TIME_TO_SLEEP));
	r2 = y.load(std::memory_order_seq_cst); // can be executed before STORE
	printf("r2 = %d\n",r2);
}

int main()
{
	std::thread t1(th1);
	std::thread t2(th2);

	t1.join();
	t2.join();
}
