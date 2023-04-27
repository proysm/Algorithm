#include <bits/stdc++.h>
using namespace std;

int A[100005];
int Min = 0x7fffffff; // 아주 큰 값을 넣어준다.
int N, M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A, A+N);

    int en = 0;
    for(int st=0; st<N; st++){
        while(en < N && A[en]-A[st] < M) en++;
        if(en == N) break; // en이 범위를 벗어나면 종료
        Min = min(Min, A[en]-A[st]);
    }
    cout << Min;
}