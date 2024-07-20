#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define X first
#define Y second

int board[51][51];
bool vis[51][51];
bool water[51][51];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool cmp(pii a, pii b){
    if(a.X == b.X) return a.Y < b.Y;
    return a.X > b.X;
}

int main() {
    // 여기에 코드를 작성해주세요.

    int n, m;
    cin >> n >> m;

    int mx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            mx = max(mx, board[i][j]);
        }
    }

    vector<pii> res;
    for(int d=1; d<=mx; d++){
        // 높이 : d
        for(int i=0; i<n; i++) fill(vis[i], vis[i]+m, false);
        vector<pii> start;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] <= d) water[i][j] = true;
                else {
                    water[i][j] = false;
                    start.push_back({i,j});
                }
            }
        }

        int cnt = 0;
        for(const pii& node : start){
            if(vis[node.X][node.Y]) continue;
            else cnt++;

            queue<pii> q;
            q.push({node.X, node.Y});

            while(!q.empty()){
                pii cur = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];

                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if(!vis[nx][ny] && !water[nx][ny]){
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                
            }  
        }
        res.push_back({cnt, d});
    }

    sort(res.begin(), res.end(), cmp);
    cout << res[0].Y << " " << res[0].X;
    return 0;
}