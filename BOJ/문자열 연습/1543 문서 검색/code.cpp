#include <bits/stdc++.h>
using namespace std;

int main(){

    string docs, word;
    getline(cin , docs);
    getline(cin , word);
    // cin >> docs; -> 이렇게 작성하면 오류가 발생함. (공백을 기준으로 문자열을 구분하기 때문!)
    // cin >> word;

    int ans = 0;
    int pos = docs.find(word);
    while(pos != string::npos){
        ans++;
        pos = docs.find(word, pos + word.size());
    }
    cout << ans;
}