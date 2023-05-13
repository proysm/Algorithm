#include <bits/stdc++.h>
using namespace std;

int t;
int board[55][55];
bool vis[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
# define X first
# define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        int m, n, k, cnt=0;
        cin >> m >> n >> k;
        queue<pair<int, int>> Q;
        for(int i=0; i<n; i++){
            fill(vis[i], vis[i]+m, 0);
            fill(board[i], board[i]+m, 0);
        }

        for(int s=0; s<k; s++){
            int i, j;
            cin >> i >> j;
            board[j][i]=1; // 틀렸던 이유 (가로의 길이:i, 세로의 길이:j)
        }

        for(int i=0; i<n; i++){ // 시작점이 매번 다르기 때문에 이중 for문을 사용해야 한다.
            for(int j=0; j<m; j++){
                if(board[i][j]==1 && vis[i][j]==0){
                    
                    vis[i][j]=1;
                    Q.push({i, j});

                    while(!Q.empty()){
                        auto cur = Q.front();
                        Q.pop();
                        
                        
                        for(int dir=0; dir<4; dir++){
                            int nx = cur.X + dx[dir];
                            int my = cur.Y + dy[dir];

                            if(nx<0 || nx>=n || my<0 || my>=m) continue;
                            if(vis[nx][my]==1 || board[nx][my]!=1) continue;
                            vis[nx][my]=1;
                            Q.push({nx, my});
                        } 
                    }
                    cnt++;




                }
            }
        }

        cout << cnt << '\n';
    }
    
    return 0;
}