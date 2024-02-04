#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[3][1001][32]; // [자두나무위치][떨어지는시간(초)][남은움직임횟수]

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, W, res=0;
    cin >> T >> W;

    for(int i=1; i<=T; i++)
    {
        cin >> arr[i];
    }

    for(int i=1; i<=T; i++)
    {
        for(int k=1; k<=W+1; k++)
        {
            if(arr[i]==1)
            {
                dp[1][i][k] = max(dp[1][i-1][k]+1, dp[2][i-1][k-1]+1);
                dp[2][i][k] = max(dp[1][i-1][k-1], dp[2][i-1][k]);
            }
            else
            {
                if(i==1 && k==1) continue;                          // 처음 시작했을 때, 2번에 있는 자두를 먹기 위해 움직이는 경우
                dp[1][i][k] = max(dp[1][i-1][k], dp[2][i-1][k-1]);
                dp[2][i][k] = max(dp[1][i-1][k-1]+1, dp[2][i-1][k]+1);
            }
        }


    }
    for(int i=1; i<=W+1; i++)
    {
        res = max(res, max(dp[1][T][i], dp[2][T][i]));
    }
    cout << res;
}