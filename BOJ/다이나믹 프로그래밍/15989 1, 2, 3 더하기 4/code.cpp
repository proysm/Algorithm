#include <bits/stdc++.h>
using namespace std;

int sum[10005][4];

int main(){

    int T, num;
    cin >> T;

    sum[1][1]=1;
    sum[1][2]=0;
    sum[1][3]=0;

    sum[2][1]=1;
    sum[2][2]=1;
    sum[2][3]=0;

    sum[3][1]=1;
    sum[3][2]=1;
    sum[3][3]=1;

    for(int i=4; i<=10000; i++)
    {
        sum[i][1] = sum[i-1][1];
        sum[i][2] = sum[i-2][1] + sum[i-2][2];
        sum[i][3] = sum[i-3][1] + sum[i-3][2] + sum[i-3][3];
    }

    while(T--)
    {
        cin >> num;
        cout << sum[num][1]+sum[num][2]+sum[num][3] << "\n";
    }

}