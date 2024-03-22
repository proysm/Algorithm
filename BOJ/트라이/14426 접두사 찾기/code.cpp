#include <bits/stdc++.h>
using namespace std;

const int MX = 500 * 10000 + 5;
const int ROOT = 1;
int unused = 2;

int nxt[MX][26]; 
// nxt[4][3] = 2; 4번노드의 자식인 3(E)의 노드번호는 2

int c2i(char c){
    return c-'a';
}
void insert_(string& str){
    int cur = ROOT;
    for(auto s : str){
        if(nxt[cur][c2i(s)] == -1) nxt[cur][c2i(s)] = unused++;
        cur = nxt[cur][c2i(s)];
    }
}

bool find_(string& str){
    int cur = ROOT;
    for(auto s : str){
        if(nxt[cur][c2i(s)] == -1) return false;
        cur = nxt[cur][c2i(s)];
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<MX; i++)
    {
        fill(nxt[i], nxt[i]+26, -1);
    }

    string str;
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