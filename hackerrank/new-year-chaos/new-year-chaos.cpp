#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// // Complete the minimumBribes function below.
// void minimumBribes(vector<int> q) {

//     // vector<int> position_map(q.size());

//     // for(int i=0; i<q.size(); ++i) {
//     //     position_map[q[i]] = q[i];
//     // }

//     int num_bribes = 0;
//     bool impossible = false;

//     for(int i=0; i<q.size(); ++i) {
//         int position_difference = q[i] - (i+1);

//         if (position_difference > 2) {
//             impossible = true;
//             break;
//         }

//         if (position_difference > 0) {
//             num_bribes += position_difference;
//         }
//     }

//     if (impossible) {
//         cout << "Too chaotic" << endl;
//     } else {
//         cout << num_bribes << endl;
//     }
// }

int swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void print_array(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void print_vector(vector<int> vec) {
    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    // cout << "input: ";
    // print_vector(q);
    bool impossible = false;

    int displacement_count[q.size()] = {0};

    bool changed = true;

    while(changed && !impossible) {
        changed = false;
        for(int i=0; i<q.size() - 1  && !impossible; i++) {
            while (q[i] > q[i+1] && i<q.size() - 1 && !impossible) {
                int current = q[i];
                displacement_count[current-1] += 1;
                swap(q[i], q[i+1]);

                if (displacement_count[current-1] > 2) {
                    impossible = true;
                    // cout << "----IMPOSSIBLE CASE----" << endl;
                    break;
                }
                changed = true;
                ++i;
            }
        }
        // cout << "vector:             ";
        // print_vector(q);
        // cout << "displacement array: ";
        // print_array(displacement_count, q.size());
    }

    if (impossible) {
        cout << "Too chaotic" << endl;
    } else {
        int total_displacement_count = 0;
        for(int i=0; i<q.size(); i++) {
            total_displacement_count += displacement_count[i];
        }
        cout << total_displacement_count << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
