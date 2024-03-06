#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, k;
int arr[10002];

bool solve(ll mid){
    ll cur = 0;
    for(int i=0; i<n; i++) cur += arr[i]/mid;
    return cur >= k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    ll st = 1;
    ll en = 0x7fffffff;
    while(st < en)
    {
        ll mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
}