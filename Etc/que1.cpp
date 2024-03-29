#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'maxTrailing' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int maxTrailing(vector<int> arr) {
    
    const int ress = -2 * 1000000;
    int res = ress;
    
    if(arr.size() <= 1) return -1;
    
    int len = arr.size();
    int maxNum = arr[len -1];
    
    for(int i=len-2; i>=0; i--)
    {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        } else {
            int temp = maxNum - arr[i];
            res = max(res, temp);
        }
    }
    if(res == 0) return -1;
    return res == ress ? -1 : res;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = maxTrailing(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
