#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    for(int i=1; i<=len1; i++)
    {
        for(int k=1; k<=len2; k++)
        {
            if(str1[i-1] == str2[k-1]) 
            {
                dp[i][k] = dp[i-1][k-1]+1;
            }
            else
            {
                dp[i][k] = max(dp[i][k-1], dp[i-1][k]);
            }
        }
    }

    cout << dp[len1][len2];
    

    return 0;
}