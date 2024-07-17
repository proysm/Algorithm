#include <bits/stdc++.h>
using namespace std;

int f[501];
vector<vector<int>> v(501);

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }


    vector<int> temp;

    for(auto e : v[1]){
        f[e] = 1;
        temp.push_back(e);
    }

    for(auto e : temp){
        for(auto k : v[e]){
            f[k] = 1;
        }
    }

    int cnt = 0;
    for(int i=2; i<=n; i++){
        if(f[i]==1) cnt++;
    }
    cout << cnt;
    return 0;
}