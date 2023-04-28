#include <bits/stdc++.h>
using namespace std;

int N;
int d[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    d[1] = 0;
    for(int i=2; i<=N; i++){
        d[i]= d[i-1] + 1; // +1은 1을 빼는 행위의 횟수 카운트.
        if(i%2 == 0) d[i] = min(d[i], d[i/2]+1); // 2로 나누어 지면 1로 빼는 것이 좋은지, 2로 나누는 것이 좋은지 확인한다.
        if(i%3 == 0) d[i] = min(d[i], d[i/3]+1); // 3으로 나누어 지면 1로 빼는 것이 좋은지, 2로 나누는 것이 좋은지 확인한다.
    }
    cout << d[N];

    return 0;
}