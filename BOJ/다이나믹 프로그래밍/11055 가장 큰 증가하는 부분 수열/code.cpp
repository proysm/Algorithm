#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int dp[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, res=0;
    cin >> t;

    for(int i=1; i<=t; i++)
    {
        cin >> arr[i];
        dp[i] =  arr[i];
    }
   
    
    for(int i=1; i<=t; i++)
    {

        for(int k=1; k<i; k++)
        {
            if(arr[i] > arr[k]){
                dp[i] = max(dp[i], dp[k]+arr[i]);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}