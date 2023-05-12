#include <bits/stdc++.h>
using namespace std;

string board[105]; // 문제에서 각각의 수들은 붙어서 입력으로 주어진다고 했기 때문
int dis[105][105]; // 0,0에서 부터 현재 노드까지의 칸 수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define X first
#define Y second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int mn = 0; //지나야 하는 최소 칸 수
    int n, m; //n: 행, m: 열
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> board[i];
    }
    for(int i=0; i<m; i++){
        fill(dis[i], dis[i]+m, -1);
    }
    queue<pair<int, int>> Q;
    dis[0][0]=0;
    Q.push({0, 0});

    while(!Q.empty()){
        pair<int, int> cur = Q.front(); 
        Q.pop();

        for(int dir=0; dir<4; dir++){
            
            int nx = cur.X + dx[dir];
            int my = cur.Y + dy[dir];

            if(nx<0 || my<0 || nx>=n || my>=m) continue;
            if(dis[nx][my]>=0 || board[nx][my]!='1') continue;
            dis[nx][my] = dis[cur.X][cur.Y] + 1; // 이 전 값에서 1을 더해주면 된다.
            Q.push({nx, my});
        }
    }
    cout << dis[n-1][m-1]+1;
    return 0;
}