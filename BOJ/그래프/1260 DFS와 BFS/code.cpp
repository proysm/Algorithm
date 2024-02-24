#include <bits/stdc++.h>
using namespace std;


vector <int> adj[1001];
int vis[1001];


void dfs(int cur){
    vis[cur] = 1;
    cout << cur << " ";
    for(auto nxt : adj[cur])
    {
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

void bfs(int cur){
    queue<int> q;
    q.push(cur);
    vis[cur] = 1;
    while(!q.empty()){
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for(auto nxt : adj[cur])
        {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
        }
    }

}

int main(void){ 

    int n, m, v;
    cin >> n >> m >> v;

    while(m--){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);
    cout << "\n";
    fill(vis+1, vis+n+1, false);
    bfs(v);
    return 0;
}