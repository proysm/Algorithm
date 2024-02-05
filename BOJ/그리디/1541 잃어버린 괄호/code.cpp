#include <bits/stdc++.h>
using namespace std;

string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
    
    int res=0, tmp=0;
    int check = 1; // 1 : +, -1 : -
    for(auto c : str)
    {
        if(c == '+')
        {
            res += (tmp * check);
            tmp = 0;
        }
        else if(c == '-')
        {
            res += (tmp * check);
            tmp = 0;
            check = -1;
        }
        else
        {
            tmp *= 10;
            tmp += c - '0';
        }
    }
    res += (tmp * check);
    cout << res;

    return 0;
}