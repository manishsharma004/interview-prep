#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int gcd(int a, int b) {
    while (a % b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return b;
}

void print_vector(vector<int> v) {
    for(vector<int>::iterator it=v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void test_gcd() {
    int test_cases[][3] = {
        {12, 3, 3},
        {12, 4, 4},
        {12, 8, 4},
        {21, 7, 7},
        {28, 21, 7},
        {30, 21, 3}
    };
    int test_case_count = sizeof(test_cases) / sizeof(int) / 3;

    string check_sign = "\xE2\x9C\x94", cross_sign = "\xE2\x9C\x98";
    for(int i=0; i<test_case_count; i++) {
        int *row = test_cases[i];
        int n1 = row[0], n2 = row[1], expected = row[2];
        int actual = gcd(n1, n2);

        cout << "gcd(" << n1 << ", " << n2 << ") = " << actual << ", expected is " << expected << " "
             << (actual == expected ? check_sign: cross_sign) << endl;
    }
}

// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) {

    int sets = gcd(a.size(), d);

    for(int i=0; i<sets; ++i) {
        int temp = a[i];
        for(int j=i; j<a.size() - 1; j += sets) {
            a[j] = a[sets + j];
        }
        a[a.size() - sets + i] = temp;
    }

    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> result = rotLeft(a, d);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
