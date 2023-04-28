#include<bits/stdc++.h>
using namespace std;

// 닫힌 괄호가 레이저를 의미하는지 쇠막대기를 의미하는지는 앞의 괄호를 보면된다.
// 레이저를 쏠 때 몇 개가 잘려나가는지는 그 순간의 스택의 길이와 연관해서 생각해본다.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    stack<char> s;
    string str;
    cin >> str;

    int size = str.size();

    for(int i=0; i<size; i++)
    {
        if(str[i] == '(') s.push(str[i]);
        else
        {
            if(str[i-1] == '(') 
            {
                s.pop();
                cnt += s.size();
            }
            else
            {
                s.pop();
                cnt++;
            }
        }
    }
    cout << cnt;
    //freopen("input.txt", "r", stdin);
    return 0;
}