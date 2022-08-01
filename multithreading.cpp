#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <atomic>

class SpinLock {
private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:
    void lock()
    {
        while( flag.test_and_set());
        std::cout << "Locked\n";
    }

    void unlock()
    {
        flag.clear();
        std::cout << "Unlocked\n";
    }

};

SpinLock spin;
static int balance{0}; 

void addMoney(int value)
{
    spin.lock();
    balance += value;
    std::cout << value << '\n';
    spin.unlock();
}

int main()
{
    std::thread t1(addMoney, 100);
    std::thread t2(addMoney, 200);

    t2.join();
    t1.join();

    //std::cout << balance << '\n';

    return EXIT_SUCCESS;
}