#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pii pair<int,int>

vector<pii> start;
vector<pii> dol;

int n, k, m;
int board[101][101]; // 1: 돌 O
bool vis[101][101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int mx = 0;

void calc() {
    memset(vis, 0, sizeof(vis)); 

    int cnt = 0;
    for (const pii& node : start) {
        queue<pii> q;
        if (!vis[node.X][node.Y] && board[node.X][node.Y] == 0) {
            q.push({node.X, node.Y});
            vis[node.X][node.Y] = true;
        }

        while (!q.empty()) {
            const pii& cur = q.front();
            q.pop();
            cnt++;

            for (int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];

                if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

                if (!vis[nx][ny] && board[nx][ny] == 0) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }
    mx = max(mx, cnt);
}

void dfs(int idx, int removeCnt) {
    if (removeCnt == m) {
        calc();
        return;
    }

    if (idx >= dol.size()) return;

    
    dfs(idx + 1, removeCnt);

    // 돌을 제거
    board[dol[idx].X][dol[idx].Y] = 0;
    dfs(idx + 1, removeCnt + 1);
    board[dol[idx].X][dol[idx].Y] = 1; // 원상복구
}

int main() {
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) dol.push_back({i, j});
        }
    }

    int r, c;
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        start.push_back({r, c});
    }

    if (m == dol.size()) {
        cout << n * n;
        return 0;
    }

    dfs(0, 0);

    cout << mx;
    return 0;
}
