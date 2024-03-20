#include <bits/stdc++.h>
using namespace std;

int bus[105][105];
int nxt[105][105];

const int INF = 0x3f3f3f3f;

int n, m;
int a, b, c;

int main(){

    cin >> n >> m;
    for(int i=1; i<=n; i++) fill(bus[i], bus[i]+n+1, INF);

    while(m--){
        cin >> a >> b >> c;
        bus[a][b] = min(bus[a][b], c);
        nxt[a][b] = b;
    }

    for(int i=1; i<=n; i++) bus[i][i] = 0;

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(bus[i][k]+bus[k][j] < bus[i][j]){
                    bus[i][j] = bus[i][k]+bus[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(bus[i][j] == INF) cout << "0 ";
            else cout << bus[i][j] << " ";
        }
        cout << '\n';
    }

    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=n; j++){
            
            if(bus[i][j] == INF || bus[i][j] == 0) {
                cout << "0\n";
                continue;
            }
            
            vector<int> path;
            int st = i;
            while(st != j){
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            
            cout << path.size() << " ";
            for(auto e : path) cout << e << " ";
            cout << '\n';
        }
    }
    return 0;
}