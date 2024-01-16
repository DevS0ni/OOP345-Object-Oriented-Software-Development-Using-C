#include <iostream>
#include <thread>

int sum = 0;
class Add{
    public:
        Add() = default;
        void operator()(int a, int b){
            sum = a+b;
        }
};

int main(){
    std::thread t1([]()
          {
            Add a;
            a(3,4);
          });
    std::thread t2([]()
          {
            Add a;
            a(5,5);
          });
    t1.join();
    t2.join();
    std::cout << sum << "\n";
    return 0;
}