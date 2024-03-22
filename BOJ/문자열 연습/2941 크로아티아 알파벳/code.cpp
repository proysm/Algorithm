#include <bits/stdc++.h>
using namespace std;

vector<string> alphas = {"c=", "c-", "dz=", "d-", "lj", "nj" ,"s=", "z="};


int main()
{
    string str;
    cin >> str;

    for(auto alph : alphas){
        
        while(true){
            int pos = str.find(alph);
            if(pos == string::npos) break;
            str.replace(pos, alph.size(), "#");    
        }
    }
    
    cout << str.size();
}