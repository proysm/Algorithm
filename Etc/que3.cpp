#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



// Complete the tasks function below.
vector<int> adj[100005];
bool visited[100005];
bool onStack[100005];
unordered_set<int> cycleNodes;

bool dfs(int node) {
    if (visited[node]) return cycleNodes.count(node) > 0;
    visited[node] = true;
    onStack[node] = true;
    for (int next : adj[node]) {
        if (onStack[next] || dfs(next)) {
            cycleNodes.insert(node);
            return true;
        }
    }
    onStack[node] = false;
    return false;
}

int tasks(int n, vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); ++i) {
        adj[b[i]].push_back(a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) dfs(i);
    }

    int cnt = count_if(visited, visited + n + 1, [](bool v) { return v; });

    cnt -= cycleNodes.size();

    cnt += cycleNodes.empty() ? 0 : 1;

    return cnt;
}



int main()
{

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    string b_count_temp;
    getline(cin, b_count_temp);

    int b_count = stoi(ltrim(rtrim(b_count_temp)));

    vector<int> b(b_count);

    for (int i = 0; i < b_count; i++) {
        string b_item_temp;
        getline(cin, b_item_temp);

        int b_item = stoi(ltrim(rtrim(b_item_temp)));

        b[i] = b_item;
    }

    int res = tasks(n, a, b);

    cout << res << "\n";


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
