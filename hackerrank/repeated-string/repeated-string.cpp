#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    int a_count_in_s = 0, length_of_s = s.length();
    int count_till_last_remainer = 0, remainder_length = n % length_of_s;

    for(string::iterator it=s.begin(); it != s.end(); ++it) {
        if (*it == 'a') {
            a_count_in_s  += 1;
        }
    }

    for(int i=0; i<remainder_length; i++) {
        if (s[i] == 'a') {
            count_till_last_remainer  += 1;
        }
    }

    return a_count_in_s * (n / length_of_s) + count_till_last_remainer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
