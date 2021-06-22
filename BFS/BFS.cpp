#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

class Graph {
public:
    vector<vector<int>>adjList;
    vector<int> shortPath;
    vector<int> visitedBy;
    Graph(int n) {
        adjList.resize(n);
        shortPath.resize(n);
        visitedBy.resize(n);
        for (int i = 0;i < n ;i++) {
            visitedBy[i] = -1;
            shortPath[i] = -1;
        }
    }

    void add_edge(int u, int v) {
        adjList[u-1].push_back(v-1);
        adjList[v-1].push_back(u-1);
    }

    vector<int> shortest_reach(int start) {
        queue<int> q;
        q.push(start-1);
        shortPath[start-1] = 0;
        visitedBy[start-1] = start-1;
        while (!q.empty()) {
            int v = q.front();q.pop();
            for (auto u : adjList[v]) {
                if (visitedBy[u] == -1) {
                    visitedBy[u] = v;
                    shortPath[u] = shortPath[v] + 6;
                    q.push(u);
                }
            }
        }
        return shortPath;
    }
};

void test(vector<int> *x) {
    (*x)[0] = 2;
}

int main() {
    Graph g(4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    auto a=g.shortest_reach(2);
    for (auto i : a) {
        cout << i << endl;
    }

    vector<int> k;
    k.push_back(2);
    test(&k);

    return 0;
}