#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

    int current_altitude = 0, valley_count = 0;

    for ( string::iterator it=s.begin(); it!=s.end(); ++it) {
        char c = *it;
        int height_change = c == 'U'? 1: -1;
        if (current_altitude == 0 && height_change < 0) {
            valley_count += 1;
        }

        current_altitude += height_change;
    }

    return valley_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
