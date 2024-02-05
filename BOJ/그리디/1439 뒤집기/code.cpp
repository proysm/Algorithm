#include <bits/stdc++.h>
using namespace std;

int cnt1, cnt0;
string str;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;

    char check = str[0];
    for(auto c : str)
    {  
        if(check == '1' && check == c) continue;
        else if(check == '0' && check == c) continue;
        else if(check == '1' && check != c) {
            cnt1++; 
            check=c;
        }
        else {
            cnt0++; 
            check=c;
        }
    }
    if(check=='1') cnt1++;
    else cnt0++;
    cout << min(cnt1, cnt0);
    return 0;
}