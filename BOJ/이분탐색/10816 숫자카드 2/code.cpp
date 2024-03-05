#include <bits/stdc++.h>
using namespace std;

int a[500005];

int upper_idx(int target, int n)
{
    int st = 0; 
    int en = n;
    while(st < en)
    {
        int mid = (st+en)/2;
        if(a[mid] > target) en = mid; // target 보다 큰 수가 나온 최초의 위치이기 때문
        else st = mid+1;
    }
    return st;
}

int lower_idx(int target, int n)
{
    int st = 0; 
    int en = n;
    while(st < en)
    {
        int mid = (st+en)/2;
        if(a[mid] >= target) en = mid;
        else st = mid+1;
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int m;
    cin >> m;
    while(m--){
        int t;
        cin >> t;
        //cout << upper_idx(t, n)-lower_idx(t, n) << "\n";
        cout << upper_bound(a, a+n, t) - lower_bound(a, a+n, t) << "\n";
    }
}