#include "bits/stdc++.h"
using namespace std;

struct edge {int to, cost;};

int n, m;
vector<vector<edge>> adj;
vector<int> dist;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    adj.resize(n);
    dist.resize(n, INT_MAX);

    // Inputs can be modified as needed before the below runs

    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // (distance, node)

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const edge& e : adj[u]) {
            int v = e.to;
            int cost = e.cost;

            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }

    // If dist[i] is still INT_MAX, node i is unreachable from the source
}