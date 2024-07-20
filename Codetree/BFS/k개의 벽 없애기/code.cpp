#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pii pair<int,int>

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int board[101][101];
int vis[101][101];
vector<pii> wall;

int n, k;
int r1, c1, r2, c2;

int mn = 0xfffff;

void calc(){

    memset(vis, 0, sizeof(vis));
    
    int cnt = 0;

    queue<pair<int,pii>> q;

    q.push({0, {r1, c1}});
    vis[r1][c1] = 1;

    while(!q.empty()){
        pair<int, pii>& cur = q.front();
        q.pop();

        if(cur.Y.X == r2 && cur.Y.Y == c2){
            mn = min(mn, cur.X);
        }

        for(int i=0; i<4; i++){
            int nx = cur.Y.X + dx[i];
            int ny = cur.Y.Y + dy[i];
            if(nx<1 || nx>n || ny<1 || ny>n) continue;

            if(vis[nx][ny]==0 && board[nx][ny]==0){
                vis[nx][ny]=1;
                q.push({cur.X+1, {nx, ny}});
            }
        }
    }

}

void dfs(int idx, int cnt){

    if(cnt == k){
        calc();
        return;
    }

    else if(idx >= wall.size()) return;

    dfs(idx+1, cnt);

    board[wall[idx].X][wall[idx].Y] = 0;
    dfs(idx+1, cnt+1);
    board[wall[idx].X][wall[idx].Y] = 1;
}

int main() {
    // 여기에 코드를 작성해주세요.

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
            if(board[i][j]==1) wall.push_back({i,j});
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;

    dfs(0, 0);

    if(mn == 0xfffff) cout << -1;
    else cout << mn;

    return 0;
}