#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10005];
int tmp[10];

void func(int k){
    if(k==m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; i++){
        int t = tmp[i];
        if(!isUsed[t]){
            arr[k] = t;
            isUsed[t] = 1;
            func(k+1);
            isUsed[t] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> tmp[i];
    }
    sort(tmp, tmp+n);
    func(0);
}