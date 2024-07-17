#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int n;

int path[101][101];
int res[101][101];

int main(){
    
    cin >> n;

    int num;

    vector<pii> v;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> num;
            if(num == 1) {
                path[i][j] = 1; 
                v.push_back({i, j});
            }
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(path[i][j] == 1) continue;
                else if(i == k || j == k) continue;
                else if(path[i][k] == 1 && path[k][j] == 1) path[i][j] = 1;
            }
        }
    }

    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}