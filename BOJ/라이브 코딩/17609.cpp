#include <bits/stdc++.h>
using namespace std;

int check(int st, int en, string str){
    while (st < en) {
        if (str[st] != str[en]) return 0;
        st++;
        en--;
    }
    return 1;
}

int main(){
    int t;
    string str;

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> str;
        int st = 0, en = str.size()-1;
        
        bool b = false;
        while(st < en){
            if(str[st] != str[en]){
                if(check(st+1, en, str) || check(st, en-1, str)) cout << 1 << "\n";
                else cout << 2 << "\n";
                b = true;
                break;
            }
            st++;
            en--;
        }
        if(b == false) cout << 0 << "\n";
    }
}