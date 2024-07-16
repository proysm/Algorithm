#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define pii pair<int,int>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int vis[21][21];

char board[21][21];
int N;
pii st, en;

int mn = 100000;

int calc(vector<pii>& v){

    int tot = 0;

    for(int t=0; t<v.size(); t++){

        if(t == v.size()-1) break;

        int x = v[t].X;
        int y = v[t].Y; // 시작점
        int d1 = v[t+1].X;
        int d2 = v[t+1].Y; // 도착점

        int tmp = abs(x-d1) + abs(y-d2);
        tot += tmp;
    }
    return tot;
}

int main() {
    cin >> N;

    int cnt = 0;
    vector<pair<int,pii>> number;
    vector<int> brute;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j] == 'S') st = {i, j};
            else if(board[i][j] == 'E') en = {i, j};
            else if(board[i][j] != '.') {
                cnt++;
                number.push_back({board[i][j]-'0', {i, j}});
            }
        }
    }
    sort(number.begin(), number.end());

    if(cnt < 3){
        cout << -1;
        return 0;
    }

    for(int i=0; i<cnt; i++){
        if(i<3) brute.push_back(0);
        else brute.push_back(1); 
    }

    vector<vector<pii>> cases;

    do{
        vector<pii> temp;
        temp.push_back(st);
        for(int i=0; i<brute.size(); i++){
            if(brute[i] == 0) temp.push_back(number[i].Y);
        }
        temp.push_back(en);
        cases.push_back(temp);
    }while(next_permutation(brute.begin(), brute.end()));

    for(auto v : cases){
        mn = min(mn, calc(v));
    }

    cout << mn;

    return 0;
}