#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define X first
#define Y second

const int INF = 0x3f3f3f3f;

int d[1005];
int pre[1005];

int main(){
    int n, m;
    cin >> n >> m;

    fill(d, d+n+1, INF);
    vector<pii> adj[100005];

    while(m--){
        int st, en, c;
        cin >> st >> en >> c;
        adj[st].push_back({c, en}); // adj[시작지] = {비용, 목적지}
    }

    int st, en;
    cin >> st >> en; // 출발점, 도착점

    d[st] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq; //{비용, 노드(목적지)}

    pq.push({d[st], st}); // {0, 출발점}

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop(); // {X:비용, Y:노드(목적지)}
        if(d[cur.Y] != cur.X) continue;

        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }

    cout << d[en] << "\n";
    vector<int> path;
    
    while(en != st){
        path.push_back(en);
        en = pre[en];
    }
    path.push_back(en);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for(auto e : path) cout << e << " ";

}