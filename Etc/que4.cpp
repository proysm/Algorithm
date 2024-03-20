#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'closestColor' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY pixels as parameter.
 */

vector<string> closestColor(vector<string> pixels) {
    vector<string> ans;
    vector<tuple<int, int, int, string>> colors = {
        {0, 0, 0, "Black"},
        {255, 255, 255, "White"},
        {255, 0, 0, "Red"},
        {0, 255, 0, "Green"},
        {0, 0, 255, "Blue"}
    };

    for (string pixel : pixels) {
        int red = stoi(pixel.substr(0, 8), nullptr, 2);
        int green = stoi(pixel.substr(8, 8), nullptr, 2);
        int blue = stoi(pixel.substr(16, 8), nullptr, 2);

        string closestColor;
        double minDistance = DBL_MAX;
        int closestCount = 0;  // 가장 가까운 색상의 개수

        for (auto& color : colors) {
            int r, g, b;
            string colorName;
            tie(r, g, b, colorName) = color;

            double distance = sqrt(pow(red - r, 2) + pow(green - g, 2) + pow(blue - b, 2));
            if (distance < minDistance) {
                minDistance = distance;
                closestColor = colorName;
                closestCount = 1;  // 새로운 최소 거리, 카운트 초기화
            } else if (distance == minDistance) {
                closestCount++;  // 같은 거리를 가진 색상의 개수 증가
            }
        }

        if (closestCount > 1) {
            closestColor = "Ambiguous";
        }

        ans.push_back(closestColor);
    }

    return ans;
}

  

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string pixels_count_temp;
    getline(cin, pixels_count_temp);

    int pixels_count = stoi(ltrim(rtrim(pixels_count_temp)));

    vector<string> pixels(pixels_count);

    for (int i = 0; i < pixels_count; i++) {
        string pixels_item;
        getline(cin, pixels_item);

        pixels[i] = pixels_item;
    }

    vector<string> result = closestColor(pixels);

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
