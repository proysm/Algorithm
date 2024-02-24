#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1002];
bool vis[1002];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        ans++;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur])
            {
                if(vis[nxt]) continue;
                vis[nxt]=1;
                q.push(nxt);
            }
        }
    }
    cout << ans;

    return 0;
}