#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countMatches' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid1
 *  2. STRING_ARRAY grid2
 */

bool visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void Exit(const int &n, int x, int y, const vector<string> &v1)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
            continue;
        if (v1[nx][ny] == '1')
            Exit(n, nx, ny, v1);
    }
}
bool DFS(const int &n, int x, int y, const vector<string> &v1, const vector<string> &v2)
{
    if (v1[x][y] != v2[x][y])
    {
        if (v1[x][y] == '1')
        {
            Exit(n, x, y, v1);
        }
        else
        {
            Exit(n, x, y, v2);
        }
        return false;
    }

    visited[x][y] = true;
    bool flag = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
            continue;
        if (v1[nx][ny] == v2[nx][ny] && v1[nx][ny] == '0')
            continue;
        if (v1[nx][ny] != v2[nx][ny] || !DFS(n, nx, ny, v1, v2))
            flag = false;
    }
    return flag;
}
int countMatches(vector<string> grid1, vector<string> grid2)
{
    int n = grid1.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j])
                continue;
            if (grid1[i][j] == '1' && grid2[i][j] == '1')
            {
                if (DFS(n, i, j, grid1, grid2))
                    cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grid1_count_temp;
    getline(cin, grid1_count_temp);

    int grid1_count = stoi(ltrim(rtrim(grid1_count_temp)));

    vector<string> grid1(grid1_count);

    for (int i = 0; i < grid1_count; i++) {
        string grid1_item;
        getline(cin, grid1_item);

        grid1[i] = grid1_item;
    }

    string grid2_count_temp;
    getline(cin, grid2_count_temp);

    int grid2_count = stoi(ltrim(rtrim(grid2_count_temp)));

    vector<string> grid2(grid2_count);

    for (int i = 0; i < grid2_count; i++) {
        string grid2_item;
        getline(cin, grid2_item);

        grid2[i] = grid2_item;
    }

    int result = countMatches(grid1, grid2);

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
