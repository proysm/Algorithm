#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
bool isUsed1[40];
bool isUsed2[40];
bool isUsed3[40];

void func(int cur){
    if(cur == n){
        cnt++;
        return;
    }
    for(int i=0; i<n; i++){
        if(isUsed1[i] || isUsed2[i+cur] || isUsed3[cur-i+n-1]){
            continue;
        }
        isUsed1[i] = 1;
        isUsed2[i+cur] = 1;
        isUsed3[cur-i+n-1] = 1;
        func(cur+1);
        isUsed1[i] = 0;
        isUsed2[i+cur] = 0;
        isUsed3[cur-i+n-1] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}