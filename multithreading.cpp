// Hello World of Concurrency 
#include <iostream>
#include <thread> // 1

void hello()  // 2. Has to have an inital function
{
    std::cout << "Hello Concurrent World\n";
}

int main() 
{
    std::thread t(hello); // 3
    t.join(); // 4. Wait for the thread associated with std::thread object 

    return EXIT_SUCCESS;
}