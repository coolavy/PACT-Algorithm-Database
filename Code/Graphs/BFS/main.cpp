// Author: coolavy
// Language: C++
// Date: 12/6/2025

#include "bits/stdc++.h"
using namespace std;

int main() {
    int n; // can be assigned a value
    vector<vector<int>> adj(n);
    vector<bool> vis(n);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
}