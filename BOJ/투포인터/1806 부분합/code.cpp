#include <bits/stdc++.h>
using namespace std;

int a[100005];
int mn = 0x7fffffff;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, tmp=0;
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        tmp+=a[i];
    }
    if(tmp < s){
        cout << 0;
        return 0;
    }

    int sum=a[0], en=0;
    for(int st=0; st<n; st++){
        while(en<n && sum<s) {
            en++; 
            if(en != n) sum+=a[en];
        } // while 문 안의 코드 순서 잘 생각하기       
        if(en == n) break; // en이 범위를 벗어나면 종료 (밑의 코드를 실행시키면 안됨)
        mn = min(mn, en-st);
        sum -= a[st]; // 빼주어야 한다. 계속 틀렸던 이유
    }
    cout << mn+1;
    return 0;
}