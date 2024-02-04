#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int dp[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, res=0;
    cin >> T;
    fill(dp, dp+1005, 1); // 1로 초기화

    for(int i=1; i<=T; i++)
    {
        cin >> arr[i];
    }

    for(int i=1; i<=T; i++)
    {
        for(int k=1; k<i; k++)
        {
            if(arr[k] < arr[i]) dp[i] = max(dp[i], dp[k]+1);
        }
        res = max(res, dp[i]);
    }
    cout << res;
    // sort(dp, dp+1005);
    // cout << dp[1004];
}