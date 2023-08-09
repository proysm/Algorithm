#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unordered_set<string> us;
    int n;
    cin >> n;
    while(n--)
    {
        string name, cmd;
        cin >> name >> cmd;
        if(cmd == "enter") us.insert(name);
        else if(cmd == "leave") us.erase(name);
    }
    vector<string> ans(us.begin(), us.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto x : ans) cout << x << '\n';
    
    return 0;
}