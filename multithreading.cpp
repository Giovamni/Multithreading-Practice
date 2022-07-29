#include <iostream>
#include <thread>
#include <utility>

void foo()
{
    std::cout << "Foo\n";
}

void bar() 
{
    std::cout << "Bar\n";
} 

int main() 
{
    std::thread t1(foo);
    std::thread t2{std::move(t1)}; // Ownership is transfered to t2 (has foo)

    t1 = std::thread(bar); // Associated with temporary std::thread object, bar

    std::thread t3;

    t3 = std::move(t2); // Ownership of t2 transfer to t3 (has foo)
    t1 = std::move(t3); // Terminates because t1 already has an associated thread. 

    return EXIT_SUCCESS;
}