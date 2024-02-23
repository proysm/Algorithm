#include <bits/stdc++.h>
using namespace std;


int n, m;
int arr[10];
bool isUsed[10002];

void func(int k)
{
    if(k == m){
        for(int i=0; i<m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    int st = 0;
    if( k != 0) st = k;
    for(int i=st; i<n; i++){
        if(!isUsed[arr[i]]){
            arr[k] = arr[i];
            isUsed[arr[i]]=1;
            func(k+1);
            isUsed[arr[i]]=0;
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr, arr+n);

    func(0);

    return 0;
}