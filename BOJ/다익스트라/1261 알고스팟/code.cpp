#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define X first
#define Y second

const int INF = 0x3f3f3f3f;

// 상하좌우
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int miro[105][105];
int d[105][105]; // 해당 칸 까지 벽을 부순 횟수

int main(){
    int n, m;
    cin >> m >> n;

    for(int i=1; i<=n; i++){
        char str[105];
        cin >> str;
        for(int j=1; j<=m; j++){
            miro[i][j] = str[j-1]-48;
        }
    }

    for(int i=1; i<=n; i++) fill(d[i], d[i]+m+1, INF);
    d[1][1] = 0;
    

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    
    pq.push({0, {1, 1}});

    while(!pq.empty()){
        auto cur = pq.top(); 
        pq.pop();
        
        for(int i=0; i<4; i++)
        {
            int x = cur.Y.X + dx[i];
            int y = cur.Y.Y + dy[i];

            if(x < 1 || y < 1 || x > n || y > m) continue; // 범위초과

            if(miro[x][y] == 0){
                if(d[x][y] > d[cur.Y.X][cur.Y.Y]){
                    d[x][y] = d[cur.Y.X][cur.Y.Y];
                    pq.push({d[x][y], {x, y}});
                }                 
            }
            else{
                if(d[x][y] > d[cur.Y.X][cur.Y.Y]+1){
                    d[x][y] = d[cur.Y.X][cur.Y.Y]+1;
                    pq.push({d[x][y], {x, y}});
                } 
            }
        }
    }
    cout << d[n][m];

    return 0;
}