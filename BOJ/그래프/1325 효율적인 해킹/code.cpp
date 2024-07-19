#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define X first
#define Y second


int n, m;
vector<int> truth[10001];
bool vis[10001];

bool cmp(pii a, pii b){
    if(a.X == b.X) return a.Y < b.Y;
    return a.X > b.X;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin >> n >> m;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        truth[b].push_back(a);
    }

    vector<pii> res;
    for(int i=1; i<=n; i++){
        
        fill(vis, vis+n+1, 0);
        queue<int> q;
        
        vis[i] = true;
        q.push(i);
        int cnt = 0;

        while(!q.empty()){ 
            int cur = q.front();
            q.pop();
            cnt++;
            for(const auto& e : truth[cur]){
                if(!vis[e]){
                    q.push(e);
                    vis[e] = true;
                }   
            }
        }
        res.push_back({cnt, i});
        
    }

    sort(res.begin(), res.end(), cmp);

    int mx = res[0].X;

    for(auto e : res){
        // cout << e.X << " " << e.Y << "\n";
        if(e.X == mx) cout << e.Y << " ";
    }


}