#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>

int n;
int board[101][101];
bool water[101][101]; // true : 잠김
bool vis[101][101]; // true : 방문함.

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){

    cin >> n;
    int mx = 0;
    int res = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            mx = max(mx, board[i][j]);
        }
    }

    for(int d=0; d<=mx; d++){ // '아무 지역도 물에 잠기지 않을 수도 있다'고 했으므로 0~mx

        vector<pii> startNode;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] <= d) water[i][j] = true;
                else startNode.push_back({i,j});
            }
        }

        for(int i=0; i<n; i++) fill(vis[i], vis[i]+n+1, 0);

        int cnt = 0;
        for(const pii& sn : startNode){
            if(vis[sn.X][sn.Y] == true) continue;
            else cnt++;

            queue<pii> q;
            q.push({sn.X, sn.Y});
            vis[sn.X][sn.Y] = true;

            while(!q.empty()){
                pii cur = q.front();
                q.pop();
                vis[cur.X][cur.Y] = true;

                for(int i=0; i<4; i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];

                    if(nx<0 || nx>=n || ny<0 || ny>=n) continue;

                    if(vis[nx][ny] == false && water[nx][ny] == false) {
                        q.push({nx, ny});
                        vis[nx][ny] = true;
                    }

                }
            }
        }
        // cout << "d: " << d << ", cnt: " << cnt << "\n";
        res = max(cnt, res);
    }

    cout << res;

    return 0;
}