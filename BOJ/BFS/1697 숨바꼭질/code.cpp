#include <bits/stdc++.h>
using namespace std;

int dist[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    fill(dist, dist+100005, -1);
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;

    int ans = 0;

    while(dist[k]==-1){
        int cur = Q.front();
        Q.pop();

        if(cur == k){
            cout << dist[cur];
            break;
        } 

        for(int nxt : {cur-1, cur+1, 2*cur}) {
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur]+1; 
            Q.push(nxt);
        }
    }
    cout << dist[k];
    return 0;
}