#include <bits/stdc++.h>
using namespace std;

int n, m; // 입력
int arr[10];     // 수열에 담을 배열
bool isUsed[10]; // 특정 수가 쓰였는가? true or false
 
void func(int k){ // 현재 k개까지 수를 택했음
    if(k==m){      // m개를 모두 택했다면,
        for(int i=0; i<m; i++){
            cout << arr[i] << " "; // arr에 기록해둔 수를 출력
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=n; i++){    // 1부터 n까지의 수에 대해
        if(!isUsed[i]){ // 아직 i가 사용되지 않았으면
            arr[k]=i;   // k번째 수를 i로 정함
            isUsed[i]=1;// i가 사용되었음을 표시    
            func(k+1);  // 다음 수를 정하기 위해 한 단계 더 들어감
            isUsed[i]=0;// k번째 수를 i로 정한 모든 경우에 대해 다 확인했으므로, i가 사용되지 않았다고 표시함
        }
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    func(0);
    return 0;
}