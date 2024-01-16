// Thread Class
// thread.cpp

#include <iostream>
#include <string>
#include <thread>

void task(const std::string& name)
{
    std::cout << "Hi " << name << "\t";
    std::cout << "This thread ID: " << std::this_thread::get_id() << "\n";

}

int main()
{
    // spawn child thread t1
    std::thread t1(task, "John");

    // spawn child thread t2
    std::thread t2(task, "Joe");

    // continue executing main thread
    task("Jane");

    // synchronize - IMPORTANT!
    t2.join();
    t1.join();
}