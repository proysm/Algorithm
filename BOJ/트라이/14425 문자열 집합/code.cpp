#include <bits/stdc++.h>
using namespace std;

int n, m;
string str;

const int ROOT = 1;
int unused = 2;
const int MX = 500 * 10000 + 5;

bool chk[MX]; // 문자열 끝인지 여부
int nxt[MX][26]; // 자식 노드 정점번호 
// ex) nxt[4][3] = 2 4번노드의 자식인 3(d)의 노드는 2

int c2i(char c){
    return c - 'a';
}

void insert_(string& str){
    int cur = ROOT;
    for(auto c : str){
        if(nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}

bool find_(string& str){
    int cur = ROOT;

    for(auto c : str){
        if(nxt[cur][c2i(c)] == -1) return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

int main(){

    for(int i = 0; i < MX; i++) fill(nxt[i], nxt[i]+26, -1);
    
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> str;
        insert_(str);
    }

    int ans = 0;
    for(int i=0; i<m; i++){
        cin >> str;
        if(find_(str)) ans++;
    }

    cout << ans;
}