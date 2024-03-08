#include <bits/stdc++.h>
using namespace std;

int note[42][42]; // 실제
int paper[12][12]; // 스티커
int n, m, k;
int r, c; // 스티커 크기

void rotate() // 90도 회전  
{
    int temp[12][12];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            temp[i][j] = paper[i][j];
    for(int i=0; i<c; i++)
        for(int j=0; j<r; j++)
            paper[i][j] = temp[r-1-j][i];
        
    swap(r, c); // 스티커의 가로 세로 길이가 바뀌었음.
}

bool patchable(int x, int y)
{
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(note[x+i][y+j]==1 && paper[i][j]==1) 
                return false;
    // 위의 반복문을 통과했다는 것은 스티커를 붙일 수 있다는 것.

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
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
        cin >> r >> c;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cin >> paper[i][j];

        for(int rot=0; rot<4; rot++) // 총 3번 돌린다. (기본, 90, 180, 270)
        {
            bool is_patch = false;
            for(int i=0; i<=n-r; i++)
            {
                if(is_patch) break;
                for(int j=0; j<=m-c; j++)
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