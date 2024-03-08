#include <bits/stdc++.h>
using namespace std;

int note[42][42]; // 실제
int paper[12][12]; // 스티커
int n, m, k;
int x, y; // 스티커 크기

void rotate() // 90도 회전  
{
    int temp[12][12];
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            temp[i][j] = paper[i][j];
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            paper[i][j] = temp[n-1-j][i];
        }
    }
    swap(x, y); 
}

bool patchable(int x, int y)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(note[x+i][y+j]==1 && paper[i][j]==1) 
                return false;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(paper[i][j]==1) note[i+x][j+y]=1;
    
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    while(k--)
    {        
        cin >> x >> y;
        for(int i=0; i<x; i++)
            for(int j=0; j<y; j++)
                cin >> paper[i][j];

        for(int rot=0; rot<4; rot++)
        {
            bool is_patch = false;
            for(int i=0; i<n-x; i++)
            {
                if(is_patch) break;
                for(int j=0; j<m-y; j++)
                {
                    if(patchable(i, j)){
                        is_patch = true;
                        break;
                    }
                }
            }
            if(is_patch) break;
            rotate();
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            ans += note[i][j];

    cout << ans << '\n';
}