#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair의 first, secode를 간단하게 쓰기 위함.

int board[502][502]; // 문제에서 입력받을 그림판
bool vis[502][502];  // 해당 칸을 방문했는지 여부를 저장
int n, m;            // n = 행의 수, m = 열의 수
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 상하좌우 네 방향을 의미

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int k = 0; k < m; k++)
            cin >> board[i][k];

    int mx = 0;  // 그림의 최댓값
    int num = 0; // 그림의 수

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (board[i][k] == 0 || vis[i][k] == 1) continue; // 방문할 필요가 없거나 이미 방문함.
            num++;        
            queue<pair<int, int>> Q;
            vis[i][k]=1;
            Q.push({i, k});
            int area = 0;// 그림의 넓이

            while(!Q.empty())
            {
                area++;
                pair<int, int> cur = Q.front();
                Q.pop();

                for(int dir=0; dir<4; dir++) //dir<4 인 이유는 한칸을 기준으로 상하좌우이기 때문
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue; // 범위를 벗어남.
                    if(vis[nx][ny]==1 || board[nx][ny] != 1) continue; // 이미 방문했거나 1이 아니면 큐에 넣을 이유가 없음
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
                mx = max(mx, area);
            }
        }
    }
    cout << num << "\n" << mx;
    return 0;
}