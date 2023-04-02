#include <bits/stdc++.h>
using namespace std;

// "올바른 괄호 문자열" 검증
bool check(string str){

    stack<char> S;

    for(auto c : str){
        if(c == '(') S.push(c);
        else {
            if(S.empty()) return false;
            S.pop();
        }
    }
    return S.empty();
}

string solution(string str){
    string answer = "";
    // 1. 입력이 빈 문자열인 경우, 빈 문자열 반환
    if(str.length() == 0) return answer;
    
    string u = "", v = "";
    int l=0, r=0;

    // 2. u, v로 분리
    for(int i=0; i<str.length(); i++){
        if(str[i] == '(') l++;
        else r++;

        if(l==r){ // "균형잡힌 괄호 문자열로" 더 이상 분리할 수 없어야 하기 때문에 반복문 안에 넣는다.
            u = str.substr(0, i+1);
            v = str.substr(i+1);
            break;
        }
    }
    // 3. u가 "올바른 괄호 문자열" 이라면
    if(check(u)){
        answer += u + solution(v);
    }
    // 4. u가 "올바른 괄호 문자열"이 아니라면
    else{
        answer = "(" + solution(v) + ")";
        for(int i=1; i<u.length()-1; i++){
            answer += (u[i] =='(' ? ')' : '(');
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    string str = "()))((()";
    string answer = solution(str);
    cout << answer;
}