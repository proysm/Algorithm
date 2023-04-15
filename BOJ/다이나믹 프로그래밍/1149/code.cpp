#include <bits/stdc++.h>
using namespace std;

int house[1005][4];
int a[1005][4];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> house[i][1] >> house[i][2] >> house[i][3]; 
    }
    a[1][1] = house[1][1];
    a[1][2] = house[1][2];
    a[1][3] = house[1][3];
    for(int i=2; i<=n; i++){
        a[i][1] = min(a[i-1][2], a[i-1][3]) + house[i][1];
        a[i][2] = min(a[i-1][1], a[i-1][3]) + house[i][2];
        a[i][3] = min(a[i-1][1], a[i-1][2]) + house[i][3];
    }
    int res;
    if(a[n][1] > a[n][2]){
        res = a[n][2] < a[n][3] ? a[n][2] : a[n][3];
        cout << res;
    }
    else{
        res = a[n][1] < a[n][3] ? a[n][1] : a[n][3];
        cout << res;
    }

    return 0;
}