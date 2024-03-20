#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countBetween' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY low
 *  3. INTEGER_ARRAY high
 */

vector<int> countBetween(vector<int> arr, vector<int> low, vector<int> high) {
    
    vector<int> result(low.size(), 0);
    sort(arr.begin(), arr.end());  

    for (int i = 0; i < low.size(); i++) {
        auto low_it = lower_bound(arr.begin(), arr.end(), low[i]);
        
        auto high_it = upper_bound(arr.begin(), arr.end(), high[i]);
        
        result[i] = high_it - low_it;
    }

    return result;

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

    string low_count_temp;
    getline(cin, low_count_temp);

    int low_count = stoi(ltrim(rtrim(low_count_temp)));

    vector<int> low(low_count);

    for (int i = 0; i < low_count; i++) {
        string low_item_temp;
        getline(cin, low_item_temp);

        int low_item = stoi(ltrim(rtrim(low_item_temp)));

        low[i] = low_item;
    }

    string high_count_temp;
    getline(cin, high_count_temp);

    int high_count = stoi(ltrim(rtrim(high_count_temp)));

    vector<int> high(high_count);

    for (int i = 0; i < high_count; i++) {
        string high_item_temp;
        getline(cin, high_item_temp);

        int high_item = stoi(ltrim(rtrim(high_item_temp)));

        high[i] = high_item;
    }

    vector<int> result = countBetween(arr, low, high);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
