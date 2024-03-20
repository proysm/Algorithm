#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define X first
#define Y second

int V, E, K;
int u, v, w;
const int INF = 0x3f3f3f3f;

// 최단 거리 테이블
int d[20005];
// {비용, 정점번호}
vector<pii> adj[20005];


int main(){
    cin >> V >> E;
    cin >> K;

    for(int i=0; i<E; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    fill(d,d+V+1,INF);

    d[K] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({d[K], K}); // 시작점

    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();

        if(d[cur.Y] != cur.X) continue;

        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    for(int i=1; i<=V; i++){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }

}