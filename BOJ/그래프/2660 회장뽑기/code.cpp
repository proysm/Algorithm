#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

bool cmp(pii a, pii b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int fri[51][51];
int dist[51][51];
int score[51];
vector<pii> res;

int main(){

    int n;
    cin >> n;

    int a, b;
    while(1){
        cin >> a >> b;
        if(a == -1 && b == -1) break;

        fri[a][b] = 1;
        fri[b][a] = 1;
        dist[a][b] = 1;
        dist[b][a] = 1;
        
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j || k == i || k == j) continue;
                else if(fri[i][j] == 1) dist[i][j] = 1;
                else if(dist[i][k] != 0 && dist[k][j] != 0){
                    int mn = min(dist[i][j], dist[i][k]+dist[k][j]);
                    if(dist[i][j] == 0){
                        dist[i][j] = dist[i][k]+dist[k][j];
                        dist[j][i] = dist[i][k]+dist[k][j];
                    }
                    else {
                        dist[i][j] = mn;
                        dist[j][i] = mn;
                    }
                    
                }
                
            }
        }
    }

    for(int i=1; i<=n; i++){
        int mx = 0;
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            mx = max(mx, dist[i][j]);
        }
        score[i] = mx;
    }


    for(int i=1; i<=n; i++){
        res.push_back({score[i], i});
    }

    sort(res.begin(), res.end(), cmp);

    int x, y=0, z;
    x = res[0].first;
    for(auto e : res){
        if(e.first == x) y++;
    }
    cout << x << " " << y << "\n";
    for(int t=0; t<y; t++){
        cout << res[t].second << " ";
    }

    return 0;
}