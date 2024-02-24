#include <bits/stdc++.h>
using namespace std;

// 비교 함수 : cmp
// cmp(앞에 위치해야 하는 원소, 뒤에 위치해야 하는 원소) = true 가 되어야 함.
// cmp(a, a)는 반드시 false여야 한다.

// 예를 들어, 절대값 힙에 여러개의 값이 있다면 -1은 그 중에서 우선 순위가 높은 값이므로,
// cmp(다른 원소, -1) = true가 되어야 한다.

class cmp{
public:
    bool operator() (int a, int b){
        if(abs(a) != abs(b)) return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; 
    cin >> n;

    priority_queue<int, vector<int>, cmp> pq;

    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;

        if(x == 0)
        {
            if(pq.empty()) cout << "0\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
            
        }
        else
        {
            pq.push(x);
        }
    }
    return 0;
}