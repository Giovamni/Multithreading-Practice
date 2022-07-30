#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int counter = 0;
std::timed_mutex mtx;

void increase (uint16_t id) 
{
    auto sc = std::chrono::steady_clock::now();
    if(mtx.try_lock_until(sc + std::chrono::milliseconds(150))) {
        ++counter;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Thread " << id << " Entered" << std::endl;
        mtx.unlock();
    }
    else {
        std::cout << "Thread " << id<< " Couldn't Enter" << std::endl;
    }
}

int main ()
{
    std::thread t1(increase, 1);
    std::thread t2(increase, 2);

    t1.join();
    t2.join();

    return EXIT_SUCCESS;
} 