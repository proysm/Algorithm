#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b, c;
int bus[102][102];
const int INF = 0x3f3f3f3f;

int main(){

    ios::sync_with_stdio(0);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        fill(bus[i], bus[i]+n+1, INF);
    }
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        bus[a][b] = min(bus[a][b], c);
    }

    for(int i=1; i<=n; i++) bus[i][i]=0;

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){    
                bus[i][j] = min(bus[i][j], bus[i][k]+bus[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(bus[i][j] == INF) cout << "0 ";
            else cout << bus[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
