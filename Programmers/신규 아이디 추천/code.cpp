#include <bits/stdc++.h>
using namespace std;

string solution(string new_id){
    string answer = "";

    // 1단계
    for(auto &e : new_id){
        if(e >=65 && e<=90) e += 32;
    }
    // 2단계
    string temp="";
    for(auto &e : new_id){
        if(isalpha(e) || isdigit(e) || e == '-' || e == '_' || e == '.') temp += e;
    }
    // 3단계
    for(int i=1; i<temp.length(); i++){
        if(temp[i] == '.' && temp[i-1] == '.') 
        {
            temp.erase(i-1, 1);
            i--; // 루프가 돌면 i가 1 증가되기 때문에 이를 방지하고자 1을 빼준다.
        } 
    }
    // 4단계
    if(temp.front() == '.') temp.erase(0, 1);
    if(temp.back() == '.') temp.erase(temp.length()-1, 1);
    // 5단계
    if(temp == "") temp += "a";
    // 6단계
    string temp2 = "";
    if(temp.length() >= 16){
        for(int i=0; i<15; i++) temp2 += temp[i];
        if(temp2.back() == '.') temp2.erase(temp2.length()-1, 1);
    }
    else temp2 = temp;
    // 7단계
    if(temp2.length() <= 2){
        char tt = temp2.back();
        while(temp2.length() != 3){
            temp2 += tt;
        }
    }
    answer = temp2;

    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str = "=.=";
    cout << solution(str);

    return 0;
}