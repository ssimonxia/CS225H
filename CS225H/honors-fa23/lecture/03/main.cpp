#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include<chrono>
#include "radixSort.h"
int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "random: must specify number" << std::endl;
        return (404);
    }
    int number = atoi(argv[1]);

    std::vector<int> vec;
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> randint(1, 100);
    //std::uniform_int_distribution<> randint(-100, 100);
    //std::uniform_int_distribution<> randint(-1000, 1000);
    
    for(int i = 0; i < number; ++i){    
        int number =  randint(gen);
        vec.push_back(number);
    }

    Sort s;
    auto start{std::chrono::steady_clock::now()};
    auto end{std::chrono::steady_clock::now()};

    //s.print(vec);

    start = std::chrono::steady_clock::now();
    s.radixSort(vec);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> radix_second{end - start};
    std::cout<<"Time for radix sort: "<< radix_second.count()<<"s\n";

    //s.print(vec);

    s.shuffleVector(vec);

    //s.print(vec);

    start = std::chrono::steady_clock::now();
    s.stlSort(vec);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> stl_second{end - start};
    std::cout<<"Time for stl sort: "<< stl_second.count()<<"s\n";

    //s.print(vec);

    s.shuffleVector(vec);

    //s.print(vec);
    if (number <= 100000) {
        start = std::chrono::steady_clock::now();
        s.bucketSort(vec);
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double> bucket_second{end - start};
        std::cout<<"Time for bucket sort: "<< bucket_second.count()<<"s\n";
        s.shuffleVector(vec);
    }
    
    
    //s.print(vec);

    

    //s.print(vec);
    if (true) {
        start = std::chrono::steady_clock::now();
        s.heapSort(vec);
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double> heap_second{end - start};
        std::cout<<"Time for heap sort: "<< heap_second.count()<<"s\n";
    }
    

    //s.print(vec);

    s.shuffleVector(vec);
    
    

    //s.print(vec);

    /*start = std::chrono::steady_clock::now();
    s.bucketSortII(vec);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> bucketII_second{end - start};
    std::cout<<"Time for bucketII sort: "<< bucketII_second.count()<<"s\n";

    //s.print(vec);

    s.shuffleVector(vec);*/

    //s.print(vec);

    start = std::chrono::steady_clock::now();
    s.quickSort(vec, 0, number - 1);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> quick_second{end - start};
    std::cout<<"Time for quick sort: "<< quick_second.count()<<"s\n";

    //s.print(vec);

    s.shuffleVector(vec);

    //s.print(vec);

    start = std::chrono::steady_clock::now();
    s.mergeSort(vec, 0, number - 1);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> merge_second{end - start};
    std::cout<<"Time for merge sort: "<< merge_second.count()<<"s\n";

    s.shuffleVector(vec);

    //s.print(vec);

    start = std::chrono::steady_clock::now();
    s.introSort(vec);
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> intro_second{end - start};
    std::cout<<"Time for intro sort: "<< intro_second.count()<<"s\n";

    //s.print(vec);
}