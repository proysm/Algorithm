#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[1001];
int dist[1001];
bool visited[1001];

void dfs(int node, int d) {
    visited[node] = true;
    dist[node] = d;
    
    for (auto &p : adj[node]) {
        int next_node = p.first;
        int weight = p.second;
        if (!visited[next_node]) {
            dfs(next_node, d + weight);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; ++i) {
        int n1, n2, d;
        cin >> n1 >> n2 >> d;
        adj[n1].push_back({n2, d});
        adj[n2].push_back({n1, d});
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        
        memset(visited, 0, sizeof(visited));
        dfs(u, 0);
        
        cout << dist[v] << "\n";
    }

    return 0;
}
