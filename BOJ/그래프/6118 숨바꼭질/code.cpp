#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define X first
#define Y second

int dist[20001];
vector<int> road[20001];

bool cmp(pii a, pii b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}


int main(){

    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }


    queue<int> q; 
    
    fill(dist, dist+20001, -1);
    q.push(1);
    dist[1] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto e : road[cur]){
            if(e != 1 && dist[e] == -1) {
                dist[e] = dist[cur]+1;
                q.push(e);
            }
        }

    }    

    vector<pii> res;
    for(int i=2; i<=n; i++){
        res.push_back({dist[i], i});
    }

    sort(res.begin(), res.end(), cmp);

    int r, g, c=0;
    r = res[0].second;
    g = res[0].first;
    for(auto e : res){
        if(e.first == g) c++;
    }
    cout << r << " " << g << " " << c;

    return 0;
}