#include <iostream>
#include <numeric>
#include <chrono>
#include <vector>
#include <thread>

double sum_parallel(std::vector<double> &vec){
    auto sum_up = [&vec] (std::size_t start, std::size_t end){
        double sum = 0.0;
        for(std::size_t i=start; i<end; i++){
            sum += vec[i];
        }
        return sum;
    };

    std::size_t length = vec.size();
    std::size_t middle = length / 2;

    double sum1 = 0.0, sum2 = 0.0;
    std::thread t1( [&]() {sum1 = sum_up(0, middle);});
    std::thread t2( [&]() {sum2 = sum_up(middle, length);});

    t1.join();
    t2.join();

    return sum1+sum2;
}

int main(){
    // 1 << 27 = 2^27, all elements are 0.5
    std::cout << "i\t\tSequential\t\tParallel\n";
    for(int i=1; i<28;i++){
        std::vector<double> x(1 << i, 0.5);

        
       
        // Sequential Sum
        auto start = std::chrono::steady_clock::now();
        double sum = std::accumulate(x.begin(), x.end(), 0.0);
        auto end =  std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_time = end - start;

        std::cout << i << "\t\t" << elapsed_time.count();
         // Parallel Sum
        start = std::chrono::steady_clock::now();
        sum = sum_parallel(x);
        end =  std::chrono::steady_clock::now();
        elapsed_time = end - start;
        std::cout << "\t\t" << elapsed_time.count() << "\n";
   
    }
    return 0;
}