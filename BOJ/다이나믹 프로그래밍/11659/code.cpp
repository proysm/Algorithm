#include <bits/stdc++.h>
using namespace std;

int d[100005];
int s[100005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        cin >> s[i];
        d[i] = d[i-1] + s[i];
    }

    while(M--){
        int i, j;
        cin >> i >> j;
        cout << d[j]-d[i-1] <<"\n";
    }
    return 0;
}