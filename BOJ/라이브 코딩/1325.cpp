#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define X first
#define Y second

int n, m;
vector<int> trust[10001];
int vis[10001];

vector<pii> ans;

bool cmp(pii a, pii b){
    if(a.X == b.X) return a.Y < b.Y;
    return a.X > b.X;
}

int main(){

    cin >> n >> m;

    int a, b;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        trust[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        queue<int> q;
        fill(vis, vis+n+1, 0);

        q.push(i);
        vis[i] = 1;
        int cnt = 0;

        while(!q.empty()){
            int cur = q.front();
            cnt++;
            q.pop();

            for(const int e : trust[cur]){
                if(vis[e] == 0){
                    q.push(e);
                    vis[e] = 1;
                } 
            }
        }

        ans.push_back({cnt, i});
    }

    sort(ans.begin(), ans.end(), cmp);

    int mx = ans[0].X;

    for(int i=0; i<ans.size(); i++){
        if(ans[i].X == mx) cout << ans[i].Y << " ";
    }
}