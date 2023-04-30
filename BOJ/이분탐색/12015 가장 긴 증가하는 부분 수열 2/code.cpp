#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int n;
vector<int> v;

void binarysearchT(int num){
    int st=0, en=v.size()-1, mid;
    int Max = 1000005;
    while(st <= en){
        mid = (st+en)/2;
        if(num <= v[mid]){
            if(mid < Max) Max = mid;
            en = mid-1;
        }
        else{ // num > v[mid]
            st = mid+1;
        }
    }
    v[Max]=num;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    v.push_back(a[0]);
    for(int i=1; i<n; i++){
        if(v.back() < a[i]) v.push_back(a[i]);
        else binarysearchT(a[i]);
    }

    cout << v.size();

    return 0;
}