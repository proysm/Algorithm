#include <bits/stdc++.h>
using namespace std;

vector<long long> v[201];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    long long n, t, tmp;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> t;
        for(int j=0; j<t; j++){
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    for(int i=1; i<=n; i++){
        
        int target = v[i].size() / 2 + 1;

        sort(v[i].begin(), v[i].end());

        long long m = v[i][0];
        int cnt = 0;
        bool ch = false;

        for(const long long& c : v[i]){
            if(c == m) cnt++;
            else{
                if(cnt >= target){
                    cout << m << "\n";
                    ch = true;
                    break;
                }
                else{
                    m = c;
                    cnt = 1;
                }
            }
        }
        if(cnt >= target && !ch) cout << m << "\n";
        else if(!ch) cout << "SYJKGW" << "\n";
    }
}