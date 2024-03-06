#include <bits/stdc++.h>
using namespace std;

int a[1000005];
vector<int> tmp, uni;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        tmp.push_back(a[i]);
    }
    sort(tmp.begin(), tmp.end());

    /* unique 라는 STL을 사용하면 더 간단해진다.
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i=0; i<n; i++)
    {
        cout << lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin() << " ";
    }
    */

    for(int i=0; i<n; i++)
    {
        if(i==0 || tmp[i-1] != tmp[i]) uni.push_back(tmp[i]);
    }

    
    for(int i=0; i<n; i++)
    {
        cout << lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin() << " ";
        // lower_bound는 iterator를 반환하기 때문에 uni.begin()를 빼야한다.
    }
    
}