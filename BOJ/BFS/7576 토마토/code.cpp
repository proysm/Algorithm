#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int board[1005][1005];
int dist[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    queue<pair<int, int>> Q;

    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            cin >> board[i][k];
            if(board[i][k]==1) Q.push({i, k});
            if(board[i][k]==0) dist[i][k] = -1; // 안익은 토마토
        }
    }
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for(int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            Q.push({nx, ny});
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            if(dist[i][k]==-1){
                cout << -1; 
                return 0;
            }
            ans = max(ans, dist[i][k]);
        }
    }
    cout << ans;

    return 0;
}