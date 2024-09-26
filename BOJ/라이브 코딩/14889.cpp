#include <bits/stdc++.h>
using namespace std;

int n;
int arr[21][21];
int MN = INT_MAX;

int calc(vector<int> v){
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            sum += (arr[v[i]][v[j]] + arr[v[j]][v[i]]);
        }
    }
    return sum;
}

int main(){

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> brute(n, 1);
    fill(brute.begin(), brute.begin()+n/2, 0);

    do{
        int sum1 = 0, sum2 = 0;
        vector<int> star;
        vector<int> link;

        for(int i=0; i<n; i++){
            if(brute[i] == 1){
                star.push_back(i+1);
            }
            else{
                link.push_back(i+1);
            }
        }
        sum1 = calc(star);
        sum2 = calc(link);
        // cout << sum1 << " " << sum2 << "\n";
        MN = min(MN, abs(sum1-sum2));
    }while(next_permutation(brute.begin(), brute.end()));
    
    cout << MN;
}