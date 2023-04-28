#include<bits/stdc++.h>
using namespace std;


int N;

bool compare(pair<int,string> a, pair<int,string> b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    pair<int, string> x[N];

    for(int i=0; i<N; i++) cin >> x[i].first >> x[i].second;
    // for(auto &s : x) cin >> s.first >> s.second; 

    stable_sort(x, x+N, compare); // x, x+N 를 출력해보면 메모리 주소가 나온다.
    //stable_sort(x, x+N, [&](pair<int,string> a, pair<int,string> b) { return a.first < b.first;});

    for(auto p : x) cout << p.first << " " << p.second << "\n";
    //freopen("input.txt", "r", stdin);
    return 0;
}