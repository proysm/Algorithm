#include <bits/stdc++.h>
using namespace std;

int n, m;
int relation[101][101];
int dist[101][101];

int main(){
    cin >> n >> m;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        relation[a][b] = 1;
        relation[b][a] = 1;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(k==i || k==j || i==j) continue;
                if(dist[i][k] != 0 && dist[k][j] != 0){
                    if(dist[i][j] == 0){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    else{
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
    int mn = 0xfffff;
    int node = 101;
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=1; j<=n; j++){
            sum += dist[i][j];
        }
        if(sum < mn) {
            mn = sum;
            node = i;
        }
        else if(sum == mn){
            node = min(node, i);
        }
    }

    cout << node;

}