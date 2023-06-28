#include <bits/stdc++.h>
using namespace std;


int s, n;
int cnt=0;
int arr[22];

void func(int cur, int sum){
    if(cur == n){
        if(sum == s){
            cnt++;
        }
        return;
    }
    func(cur+1, sum); // 해당 숫자를 더하지 않음
    func(cur+1, sum+arr[cur]); // 해당 숫자를 더함
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> s;
    for(int i=0; i<n; i++) cin >> arr[i];
    func(0, 0);       // (cur, sum)
    if(s == 0) cnt--; // 공집합을 빼준다.
    cout << cnt;
    return 0;
}