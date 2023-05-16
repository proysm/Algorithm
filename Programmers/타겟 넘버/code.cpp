#include <bits/stdc++.h>
using namespace std;

int answer;

void DFS(vector<int> num, int trg, int sum, int idx){
    if(idx==num.size()){
        if(sum==trg) answer++; 
        return;
    } 
    DFS(num, trg, sum+num[idx], idx+1);
    DFS(num, trg, sum-num[idx], idx+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 문제 입력
    vector<int> numbers1 = {4, 1, 2, 1};
    vector<int> numbers2 = {1, 1, 1, 1, 1};
    int target1 = 4, target2 = 3;
    
    DFS(numbers1, target1, 0, 0);

    cout << answer;
}