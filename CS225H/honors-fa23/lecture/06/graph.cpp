#include <vector>
#include <random>
#include <iostream>
#include "graph.h"
using namespace std;

// This function will generate a random directed graph with source 0 and sink num-1
// with specific ratio between backward flow and forward flow
// Define: given a SUHA hash function f(x) = x where x is the id of the node
// backward flow as from node with large hash value to smaller hash value
// forward flow as from node with smaller hash value to larger smaller hash value
// para: the number of node in the graph
// ratio: the largest ratio between backward flow and forward flow

vector<vector<int>> graphGeneration(int num, double ratio) {
    vector<vector<int>> out(num);
    for (int i = 0; i < num; i++) {
        vector<int> tmp(num);
        out[i] = tmp;
    }
    //cout<<out.size()<<" "<<out[0].size()<<endl;
    std::random_device rd1; 
    std::mt19937 gen1(rd1()); 
    std::uniform_int_distribution<> randint1(0, num-1);
    std::random_device rd2; 
    std::mt19937 gen2(rd2()); 
    std::uniform_int_distribution<> randint2(0, num-2);
    std::random_device rd3; 
    std::mt19937 gen3(rd3()); 
    std::uniform_int_distribution<> randint3(1, 50);

    int minForward = num - 1;
    int minBackward = ratio * minForward;
    int numForward = 0;
    int numBackward = 0;
    int ratioF = 0;
    int checkRatio = 1/ratio;
    int countt = 0;
    int maxForward = num * (num - 1) / 2;
    while(numForward < maxForward) {
        int x = randint1(gen1);
        int y = randint2(gen2);
        int weight = randint3(gen3);
        int f = 0;
        if (y < x && out[x][y] == 0) {
            numForward++;
            ratioF++;
            f = 1;
        } else if (y > x && ratioF >= checkRatio && out[x][y] == 0) {
            numBackward++;
            ratioF = 0;
            f = 1;
        }
        if (x != y && out[x][y] == 0 && f == 1) {
            out[x][y] = weight;
        }
        
        if (numForward >= minForward && numBackward >= minBackward) {
            int check = 0;
            for(int i = 0; i < num-1; i++) {
                int flag1 = 0;
                int flag2 = 0;
                for(int j = 0; j < num; j++) {
                    if (out[j][i] == 0) {
                        flag1++;
                    }
                    if (out[i][j] == 0) {
                        flag2++;
                    }
                }
                if (flag1 == num || flag2 == num) {
                    check = 1;
                    break;
                }
            }
            if (check == 0) {
                break;
            }
        }
        /*countt++;
        if (countt>101) {
            cout<<numForward<<endl;
        }*/
    }
    return out;
}
/*
int main() {
    int num = 6;
    vector<vector<int>> out = graphGeneration(num, 0.33);
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            cout<<out[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/