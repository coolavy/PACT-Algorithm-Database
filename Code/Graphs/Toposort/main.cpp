// Author: coolavy
// Language: C++
// Date: 12/6/2025

#include "bits/stdc++.h"
using namespace std;

int n; // can be assigned a value in main function
vector<vector<int>> adj;
vector<bool> vis;
vector<int> ans;

// copy-pasted from DFS/main.cpp and added line 21
void dfs(int u) {
	if (vis[u]) {
        return;
    }

	vis[u] = true;

	for (int v : adj[u]) {
        dfs(v);
    }

    ans.push_back(u);
}

// There is a version using BFS, named Khan's Algorithm.
void toposort() {
    vis.assign(n, false);
    ans.clear();
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    reverse(ans.begin(), ans.end());
}