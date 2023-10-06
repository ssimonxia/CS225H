#include <iostream>
#include <random>
#include<chrono>

#include "vector.h"
//#include "list.h"

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "random: must specify number" << std::endl;
        return (404);
    }
    int number = atoi(argv[1]);

    List list;

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> randint(1, 100);

    auto start{std::chrono::steady_clock::now()};
    auto end{std::chrono::steady_clock::now()};

    //Time for Insert in order
    start = std::chrono::steady_clock::now();
    for(int i = 0; i < number; ++i){    
        int number =  randint(gen);
        list.insert(number);
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> insert_second{end - start};
    std::cout<<"Time for insert: "<< insert_second.count()<<"s\n";


    //Time for traversing ordered list
    start = std::chrono::steady_clock::now();
    list.print();
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> traverse_second{end - start};
    std::cout<<"Time for traversing ordered list: "<< traverse_second.count()<<"s\n";


    //Time for getting value at the front
    start = std::chrono::steady_clock::now();
    int a = list.front();
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> front_second{end - start};
    std::cout<<"Time for getting value at the front: "<< front_second.count()<<"s\n";


    //Time for getting value at the back
    start = std::chrono::steady_clock::now();
    int b = list.back();
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> back_second{end - start};
    std::cout<<"Time for getting value at the back: "<< back_second.count()<<"s\n";


    //Time for removal
    start = std::chrono::steady_clock::now();
    for(int i = number; i > 0; --i){
        int index = randint(gen) % i;
        list.remove(index);
        // list.print();
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> remove_second{end - start};
    std::cout<<"Time for removal: "<< remove_second.count()<<"s\n";


    //Time for adding value at the front
    start = std::chrono::steady_clock::now();
    for(int i = 0; i < number; ++i){    
        int number =  randint(gen);
        list.push_front(number);
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> insertFront_second{end - start};
    std::cout<<"Time for insert at the front: "<< insertFront_second.count()<<"s\n";


    //Time for traversing unordered list
    start = std::chrono::steady_clock::now();
    list.print();
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> traverseun_second{end - start};
    std::cout<<"Time for traversing unordered list: "<< traverseun_second.count()<<"s\n";


    //Time for removing value at the front
    start = std::chrono::steady_clock::now();
    for(int i = number; i > 0; --i){
        list.removeFront();
        // list.print();
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> removeFront_second{end - start};
    std::cout<<"Time for removing value at the front: "<< removeFront_second.count()<<"s\n";


    //Time for adding value at the back
    start = std::chrono::steady_clock::now();
    for(int i = 0; i < number; ++i){    
        int number =  randint(gen);
        list.push_back(number);
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> insertBack_second{end - start};
    std::cout<<"Time for adding value at the back: "<< insertBack_second.count()<<"s\n";

    //Time for removing value at the back
    start = std::chrono::steady_clock::now();
    for(int i = number; i > 0; --i){
        list.removeBack();
        // list.print();
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> removeBack_second{end - start};
    std::cout<<"Time for removing value from the back: "<< removeBack_second.count()<<"s\n";


    start = std::chrono::steady_clock::now();
    for(int i = 0; i < number; ++i){    
        int number =  randint(gen);
        list.insertMid(number);
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> insertMid_second{end - start};
    std::cout<<"Time for adding value in the middle: "<< insertBack_second.count()<<"s\n";

    return 0;
}