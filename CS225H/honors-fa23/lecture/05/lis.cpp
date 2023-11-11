#include <iostream>
#include <vector>
#include "lis.h"
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>

int main() {
    auto start{std::chrono::steady_clock::now()};
    auto end{std::chrono::steady_clock::now()};
    std::vector<int> a;
    /*a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    a.push_back(9);
    a.push_back(5);
    a.push_back(8);
    a.push_back(6);
    a.push_back(7);*/
    //a.push_back(10);
    //a.push_back(15);
    //a.push_back(12);
    //a.push_back(13);
    std::ofstream os("./lis1.csv");
    os<<"lisRec, lisIter"<<std::endl;
    for(int i = 5; i < 120; i+=5) {
        std::vector<int> vec;
        for(int j = 0; j < i; j++) {
            std::random_device rd2;  // a seed source for the random number engine
            std::mt19937 gen2(rd2()); // mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<> randint2(1, 1000);
            int number =  randint2(gen2);
            vec.push_back(number);
            //std::cout<<number<<" ";
        }
        //std::cout<<std::endl;
        start = std::chrono::steady_clock::now();
        lisRec(vec, 0, -1);
        //std::cout<<"number: "<<lisRec(vec, 0, -1)<<std::endl;
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double> lisRecSec{end - start};

        start = std::chrono::steady_clock::now();
        lisIter(vec);
        //std::cout<<"number: "<<lisIter(vec)<<std::endl;
        end = std::chrono::steady_clock::now();
        std::chrono::duration<double> lisIterSec{end - start};
        
        os<<lisRecSec.count()<<", "<<lisIterSec.count()<<std::endl;
    }
    
    /*std::vector<std::vector<int>> table;
    for(int i = 0; i < a.size(); i++) {
        std::vector<int> tmp;
        for(int j = 0; j < a.size(); j++) {
            tmp.push_back(0);
        }
        table.push_back(tmp);
    }
    std::cout<<"number: "<<lisRecT(table, a, 0, -1)<<std::endl;
    for(int i = 0; i < a.size(); i++) {
        if (i+1 < a.size()){
            table[i][i] = table[i+1][i] + 1;
        } else {
            table[i][i] = 1;
        }
        for(int j = 0; j <= i; j++) {
            std::cout<<table[i][j]<<" ";
        }
        std::cout<<std::endl;
    }*/
    
    std::vector<int> ex;
    ex.push_back(6);
    ex.push_back(5);
    ex.push_back(4);
    ex.push_back(3);
    ex.push_back(2);
    ex.push_back(1);
    int c1 = 0;
    lisRecT(c1, ex, 0, -1);
    std::cout<<c1<<" ";

    std::vector<int> ex2;
    ex2.push_back(1);
    ex2.push_back(2);
    ex2.push_back(3);
    ex2.push_back(4);
    ex2.push_back(5);
    int c2 = 0;
    lisRecT(c2, ex2, 0, -1);
    std::cout<<c2<<std::endl;
}

int lisRec(std::vector<int> a, int i, int j) {
    if (i >= a.size()) {
        return 0;
    }
    if (a[i] > j) {
        int x = 1+lisRec(a, i+1, a[i]);
        int y = lisRec(a, i+1, j);
        return x > y ? x : y;
    } else {
        return lisRec(a, i+1, j);
    }
}

int lisIter(std::vector<int> a) {
    std::vector<int> s(a.size());
    s[0] = 1;
    for(int i = 1; i < a.size(); i++) {
        s[i]=1;
        for(int j = 0; j < i; j++) {
            if (a[i] > a[j] && s[i] < s[j] + 1) {
                s[i] = s[j] + 1;
            }
        }
    }
    return *std::max_element(s.begin(), s.end());
}

int lisRecT(int & countt, std::vector<int> a, int i, int j) {
    countt++;
    if (i >= a.size()) {
        return 0;
    }
    if (a[i] > j) {
        int x = 1+lisRecT(countt ,a, i+1, a[i]);
        int y = lisRecT(countt, a, i+1, j);
        return x > y ? x : y;
    } else {
        return lisRecT(countt, a, i+1, j);
    }
}