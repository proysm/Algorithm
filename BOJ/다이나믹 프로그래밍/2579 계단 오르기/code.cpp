#include <bits/stdc++.h>
using namespace std;

int score[305]; // 계단의 점수
int d[305][3]; // 밟았는지 확인

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> score[i];
    }
    
    d[1][1] = score[1];
    d[2][1] = score[2];
    d[2][2] = score[1] + score[2];

    for(int i=3; i<=N; i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + score[i];
        d[i][2] = d[i-1][1] + score[i];
    }

    cout << max(d[N][1], d[N][2]);
}