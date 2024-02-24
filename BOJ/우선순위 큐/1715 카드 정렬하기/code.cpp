#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        pq.push(x);
    }

    int ans = 0;
    while(pq.size() > 1)
    {
        int nx = pq.top(); pq.pop();
        int ny = pq.top(); pq.pop();
        ans += (nx+ny);
        pq.push(nx+ny);
    }
    cout << ans;

    return 0;
}