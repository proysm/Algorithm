#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(auto c : scoville) pq.push(c);
    int f1=0, f2=0;
    
    while(pq.top() < K) 
    {   
        if(pq.size() == 1) {
            answer=-1; 
            break;
        }
        f1 = pq.top();
        pq.pop();

        f2 = pq.top();
        pq.pop();

        pq.push(f1 + f2*2);
        answer++;
    }
    
    
    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;
    cout << solution(scoville, K);
}