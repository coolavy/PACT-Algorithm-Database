// Author: coolavy
// Language: C++
// Date: 12/6/2025

#include <bits/stdc++.h>
using namespace std;

int n; // can be assigned a value in main function
vector<vector<int>> adj(n);
vector<bool> vis(n);

void dfs(int u) {
	if (vis[u]) {
        return;
    }

	vis[u] = true;

	for (int v : adj[u]) {
        dfs(v);
    }
}