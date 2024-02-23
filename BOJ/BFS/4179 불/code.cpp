#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[1002];
int dist1[1002][1002]; // 불
int dist2[1002][1002]; // 지훈

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<pair<int, int>> Q1; // 불
    queue<pair<int, int>> Q2; // 지훈

    cin >> n >> m;

    for(int i=0; i<n; i++){
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
    }
    for(int i=0; i<n; i++) cin >> board[i];
    
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            if(board[i][k] == 'F') 
            {
                Q1.push({i, k});
                dist1[i][k] = 0;
            }
            if(board[i][k] == 'J')
            {
                Q2.push({i, k});
                dist2[i][k] = 0;
            }
            
        }
    }

    // 불
    while(!Q1.empty())
    {
        auto cur = Q1.front();
        Q1.pop();

        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 이미 방문했거나 벽인 경우
            dist1[nx][ny] = dist1[cur.first][cur.second]+1;
            Q1.push({nx, ny});
        }
    }

    // 지훈
    while(!Q2.empty())
    {
        auto cur = Q2.front();
        Q2.pop();

        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) // 범위가 벗어난 것은 탈출 성공
            {
                cout << dist2[cur.first][cur.second]+1;
                return 0;
            }
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 이미 방문했거나 벽인 경우
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second]+1) continue; // 불이 먼저 번진 경우
            dist2[nx][ny] = dist2[cur.first][cur.second]+1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}