#include<bits/stdc++.h>
using namespace std;

// (()[[]])([])
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> S;
    string str;
    cin >> str;
    int size = str.size();
    int answer=0, temp=1;

    for(int i=0; i<size; i++)
    {
        if(str[i]=='('){
            S.push(str[i]);
            temp *= 2;
        }
        else if(str[i]==')'){
            if(S.empty() || S.top()!='('){
                answer = 0; 
                break;
            }
            if(str[i-1]=='('){
                answer += temp;
                temp /= 2;
                S.pop();
            }
            else{
                temp /= 2;
                S.pop();
            }
        }
        else if(str[i]=='['){
            S.push(str[i]);
            temp *= 3;
        }
        else if(str[i]==']'){
            if(S.empty() || S.top()!='['){
                answer = 0; 
                break;
            }
            if(str[i-1]=='['){
                answer += temp;
                temp /= 3;
                S.pop();
            }
            else{
                temp /= 3;
                S.pop();
            }
        }
    }
    if(!S.empty()) answer = 0;
    cout << answer;
    //freopen("input.txt", "r", stdin);
    return 0;
}