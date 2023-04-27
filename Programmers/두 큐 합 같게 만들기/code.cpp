#include <bits/stdc++.h>
using namespace std;

int answer = 0;
vector<int>::iterator ptr1, ptr2;
long long sum1 = 0, sum2 = 0;

int solution(vector<int> queue1, vector<int> queue2) {
    ptr1 = queue1.begin();
    ptr2 = queue2.begin();

    for(auto e : queue1) sum1 += e;
    for(auto e : queue2) sum2 += e;

    if((sum1+sum2)%2 != 0) return -1; // 합이 홀수이면 문제의 조건을 만족할 수 없음.
    
    while(1){
        
        if(sum1 == sum2) break;   // 종료조건 1 

        if(ptr1 == queue2.end() || ptr1 == queue1.end()) { // 종료조건 2
            answer = -1;
            break;
        } 

        if(sum1 > sum2){
            sum1 -= *ptr1;
            sum2 += *ptr1;

            ptr1++;
            if(ptr1 == queue1.end()) ptr1 = queue2.begin(); 
        }
        else{
            sum2 -= *ptr2;
            sum1 += *ptr2;
            

            ptr2++;
            if(ptr2 == queue2.end()) ptr2 = queue1.begin(); 
        }
        answer++;
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << "유수민";    

    vector<int> v1 = {3, 2, 7, 2};

    vector<int> v2 = {4, 6, 5, 1};

    cout << solution(v1, v2);
    return 0;
}