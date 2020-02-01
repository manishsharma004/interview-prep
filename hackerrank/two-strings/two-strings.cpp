#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {

    map<char, bool> char_map;

    for(string::iterator it = s1.begin(); it != s1.end(); ++it) {
        char c = *it;
        char_map[c] = true;
    }

    bool has_common_substring = false;

    for(string::iterator it = s2.begin(); it != s2.end(); ++it) {
        char c = *it;
        
        if (char_map.find(c) != char_map.end()) {
            has_common_substring = true;
            break;
        }
    }

    return has_common_substring? "YES": "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
