#include <bits/stdc++.h>
using namespace std;

int board[51][51];
int dp[51][51];

int main() {
    // 여기에 코드를 작성해주세요.

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> board[i][j];
        }
    }

    for(int i=2; i<=n; i++){
        dp[i][1] = -1;
    }
    for(int i=2; i<=m; i++){
        dp[1][i] = -1;
    }
    dp[1][1] = 1;

    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            

            for(int k=1; k<i; k++){
                for(int l=1; l<j; l++){
                    if(dp[k][l] == -1) continue;

                    if(board[i][j] > board[k][l]){
                        dp[i][j] = max(dp[i][j], dp[k][l]+1);
                    }
                }
            }

            if(dp[i][j] == 0) dp[i][j] = -1; // 이 부분 주의하기
        }
    }



    int mx = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // cout << dp[i][j] << " ";
            mx = max(mx, dp[i][j]);
        }
        // cout << "\n";
    }
    cout << mx;

    return 0;
}