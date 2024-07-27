#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
    // 여기에 코드를 작성해주세요.

    string a, b;
    cin >> a >> b;

    int ans = INT_MAX;

    for(int i=0; i<=a.size(); i++){ 
        dp[i][0] = i;
    }

    for(int j=0; j<=b.size(); j++){
        dp[0][j] = j;
    }
    

    for(int i=1; i<=a.size(); i++){
        for(int j=1; j<=b.size(); j++){
            
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1});
            }
        }
    }   

    cout << dp[a.size()][b.size()];

    return 0;
}