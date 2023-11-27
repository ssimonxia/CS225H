#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include "maxFlow.h"
using namespace std;

// Find an available path from start to end using BFS and record path in path vector
// If there is no path from start to end, then we have the max flow
// Parameter: g: the residual graph to traverse
//            start: the start node    end: the end node
//            path: record the previous node of current node.
//            It can represent a random single linked list from end to start but ensure the shortest distance
bool bfs(vector<vector<int>> g, int start, int end, vector<int> & path) {
    vector<bool> visit;
    for(int i = 0; i < g.size(); i++) {
        visit.push_back(0);
    }
    queue<int> node;
    node.push(start);
    visit[start] = true;
    path[start] = -1;
    while(!node.empty()) {
        int curr = node.front();
        node.pop();
        for (int j = 0; j < g.size(); j++) {
            if (visit[j] == 0 && g[curr][j] > 0) {
                if (j == end) {
                    path[j] = curr;
                    return true;
                }
                node.push(j);
                path[j] = curr;
                visit[j] = true;
            }
        }
    }
    return false;
}

int maxFlow(vector<vector<int>> g, int start, int end) {
    vector<vector<int>> re = g;
    int maxx = 0;
    vector<int> path(g.size());
    while(bfs(re, start, end, path)) {
        int flow = 999999;
        int curr = end;
        while(curr != start){
            int pre = path[curr];
            if (flow > re[pre][curr]) {
                flow = re[pre][curr];
            }
            curr = pre;
        }
        curr = end;
        while (curr != start) {
            int pre = path[curr];
            re[pre][curr] -= flow;
            re[curr][pre] += flow;
            curr = pre;
        }
        maxx += flow;
        path.clear();
    }
    return maxx;
}
