#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pii pair<long long, int>

const int MX = 100000 + 2;

long long d[MX]; // 최소시간
int pre[100005]; // 이전 노드 기록
const long long INF = 77777777777;

vector<pair<int, int>> node[MX]; // node[1] = {주기, 노드} 노드1에서 갈 수 있는 노드
priority_queue<pii, vector<pii>, greater<pii>> pq;



int main(){

    fill(d, d+MX, INF);

    int n, m; // 지역의 수, 주기
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        node[a].push_back({i, b});
        node[b].push_back({i, a});
    }
        
    // 이 두 줄 순서 바꿔서 계속 틀렸었음 ㅠㅠ
    d[1]=0;
    pq.push({d[1], 1}); // {비용, 노드}

    const int MOD = m;

    while(!pq.empty()){
        auto cur = pq.top(); 
        pq.pop();
        if(d[cur.Y] != cur.X) continue; // 이거 추가하기!!! => 최적화를 위해서

        for(auto nxt : node[cur.Y]){
            
            long long nd = (nxt.X - cur.X) % MOD;
            if(nd < 0) nd += MOD;
            
            long long cost = nd+cur.X +1; // d[cur.Y] = cur.X 둘 중 아무거나 사용해도 됨.

            if(d[nxt.Y] <= cost) continue;

            d[nxt.Y] = cost;
            
            pq.push({d[nxt.Y], nxt.Y});
        }

    }

    cout << d[n];

    return 0;
}