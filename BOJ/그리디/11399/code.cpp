#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }    
    sort(arr, arr+N);
    int ans = 0;
 
    for(int k=0; k<N; k++){
        int tmp=0;
        for(int i=0; i<=k; i++){
            tmp += arr[i];
        }
        ans += tmp;
    }

    cout << ans;
    return 0;
}

// 1 + 1+2 + 1+2+3 1+2+3+4 1+2+3+4+5 