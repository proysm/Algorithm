#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> event;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, s, t;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> s >> t;
        event.push_back({s, 1});
        event.push_back({t, -1});
    }
    sort(event.begin(), event.end());

    int current = event[0].X; // 현재 시간
    int cur = 0; // 현재 시간에 열려있는 강의실 개수
    int idx=0, res=0;

    while(true)
    {
       while(idx < 2*N && event[idx].X == current)
       {
            cur += event[idx].Y;
            idx++;
       }

       res = max(cur, res);
       if(idx == 2*N) break;
       current = event[idx].X;
    }
    
    cout << res;

    return 0;

}