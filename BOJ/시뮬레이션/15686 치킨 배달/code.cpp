#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>

int N, M;
vector<pii> house;
vector<pii> chicken;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    
    int tmp;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> tmp;
            if(tmp == 1) house.push_back({i, j});
            if(tmp == 2) chicken.push_back({i, j});
        }
    }

    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin()+chicken.size()-M, 0);


    int res = 0xfffff;
    do{
        int dist = 0;
        for(auto h : house){
            int temp = 100;
            for(int i=0; i<chicken.size(); i++){
                if(brute[i] == 0) continue;
                temp = min(abs(chicken[i].X - h.X)+abs(chicken[i].Y - h.Y), temp);
            }   
            dist += temp;
        }
        res = min(dist, res);
        
    }while(next_permutation(brute.begin(), brute.end()));

    cout << res;
}   