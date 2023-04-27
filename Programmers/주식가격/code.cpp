#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int n = prices.size();
    int en = 0;
    for(int st=0; st<n; st++){
        en = st;
        while(en < n && prices[st] <= prices[en]) en++;
        if(en == n) answer.push_back(en-st-1);
        else answer.push_back(en-st);
    }
    return answer;
}

int main(){
    vector<int> prices = {1, 2, 3, 2, 3};
    vector<int> answer = solution(prices);
    for(auto c: answer){
        cout << c << " ";
    }
}