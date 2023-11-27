#include "maxFlow.h"
#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

int main() {
    vector<vector<int>> g1 = {
        { 0, 10, 10, 0, 0, 0 }, 
        { 0, 0, 0, 25, 0, 0 },
        { 0, 0, 0, 0, 15, 0 },  
        { 0, 0, 0, 0, 0, 10 },
        { 0, 6, 0, 0, 0, 10 },   
        { 0, 0, 0, 0, 0, 0 }
    };
    cout << "The maximum possible flow is " << maxFlow(g1, 0, 5)<<endl;
    
    vector<vector<int>> g2 = {
        { 0, 20, 10, 0 }, 
        { 0, 0, 6, 10 },
        { 0, 0, 0, 20 },  
        { 0, 0, 0, 0 }
    };
    cout << "The maximum possible flow is " << maxFlow(g2, 0, 3)<<endl;
    
    vector<vector<int>> g3 = {
        { 0, 16, 13, 0, 0, 0 }, 
        { 0, 0, 10, 12, 0, 0 },
        { 0, 4, 0, 0, 14, 0 },  
        { 0, 0, 9, 0, 0, 20 },
        { 0, 0, 0, 7, 0, 4 },   
        { 0, 0, 0, 0, 0, 0 }
    };
    cout << "The maximum possible flow is " << maxFlow(g3, 0, 5)<<endl;

    vector<vector<int>> g4 = {
        { 0, 10, 14, 11, 21}, 
        { 24, 0, 43, 35, 0 },
        { 0, 0, 0, 46, 0 },  
        { 10, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
    };
    cout << "The maximum possible flow is " << maxFlow(g4, 0, 4)<<endl;

    int num = 6;
    vector<vector<int>> tmp = graphGeneration(num, 0.5);
    vector<vector<int>> g5 = tmp;
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            g5[i][j] = tmp[j][i];
        }
    }
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            cout<<g5[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "The maximum possible flow is " << maxFlow(g5, 0, 4)<<endl;
    return 0;
}