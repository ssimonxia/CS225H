#include <vector>
#include <iostream>
#include "set.h"
#include <chrono>
#include <random>
#include <fstream>

int main() {
    auto start{std::chrono::steady_clock::now()};
    auto end{std::chrono::steady_clock::now()};
    std::ofstream os("./output.csv");
    std::ofstream os2("./output2.csv");
    os<<"Rec"<<std::endl;
    os2<<"Dynamic Programming"<<std::endl;
    for (int x = 10; x <= 50000; x+=500){
        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> randint(1, 100000);
        std::vector<int> vec;

        std::random_device rd2;  // a seed source for the random number engine
        std::mt19937 gen2(rd2()); // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> randint2(1, 10000);
        int number =  randint2(gen2);
        for(int i = 0; i < x; i++) {
            vec.push_back(randint(gen));
        }
        double firstsec;
        for(int i = 0; i < 10; i++) {
            start = std::chrono::steady_clock::now();
            bool first = checkSum(vec, number, 0);
            end = std::chrono::steady_clock::now();
            std::chrono::duration<double> checkSumrec{end - start};
            firstsec+=checkSumrec.count();
        }
        os<<firstsec/10<<std::endl;
        double secondsec;
        for(int i = 0; i < 10; i++) {
            start = std::chrono::steady_clock::now();
            bool second = isSubsetSum(vec, int(vec.size()), number);
            end = std::chrono::steady_clock::now();
            std::chrono::duration<double> checkSumdy2{end - start};
            secondsec += checkSumdy2.count();
        }
        os2<<secondsec/10<<std::endl;
    }
    /*std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(34);
    vec.push_back(4);
    vec.push_back(12);
    vec.push_back(5);
    vec.push_back(2);
    for(int i = 2; i <= 200; i++) {
        if (checkSum(vec, i, 0) != isSubsetSum(vec, vec.size(), i)){
            std::cout<<i<<": "<<checkSum(vec, i, 0)<<" "<<isSubsetSum(vec,vec.size(),i)<<std::endl;
        }
        //std::cout<<checkSum(vec, i, 0)<<" "<<isSubsetSum(vec, vec.size(), i)<<std::endl;
    }*/
    os.close();
    return 0;
}

bool checkSum(std::vector<int> s, int sum, int i) {
    if (sum == 0) {
        return true;
    }
    if (i >= s.size()) {
        return false;
    }
    //std::cout<<sum<<" "<<s[i]<<std::endl;
    if (sum < s[i]) {
        return checkSum(s, sum, i+1);
    } else {
        return checkSum(s, sum-s[i], i+1) || checkSum(s, sum, i+1);    
    }
}

bool isSubsetSum(std::vector<int> s, int n, int sum)
{
    std::vector<bool> prev(sum + 1);
    prev[0] = true;
 
    for (int i = 1; i <= sum; i++)
        prev[i] = false;
 
    std::vector<bool> curr(sum + 1);
 
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j < s[i - 1])
                curr[j] = prev[j];
            if (j >= s[i - 1])
                curr[j] = prev[j] || prev[j - s[i - 1]];
            //std::cout<<curr[j]<<" ";
        }
        //std::cout<<std::endl;
        prev = curr;
    }
    return prev[sum];
}
