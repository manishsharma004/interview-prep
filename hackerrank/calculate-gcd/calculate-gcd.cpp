#include <iostream>
#include <cstring>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

vector<string> split_string(string);
string myfunction(string, string);
string join_vector_string(vector<string>);

void swap(int &first, int &second) {
  first = first ^ second;
  second = first ^ second;
  first = first ^ second;
}

int gcd(int first, int second) {
  if (first < second) {
    swap(first, second);
  }

  while (second % first != 0) {
    int remainder = second % first;
    second = first;
    first = remainder;
  }

  return first;
}

int gcd_multiple(vector<int> numbers) {
  int n = numbers.size();

  if (n < 1) {
    return 0;
  }
  if (n < 2) {
    return numbers[0];
  }
  int final_gcd = numbers[0];
  for(int i=1; i<n; i++) {
    final_gcd = gcd(final_gcd, numbers[i]);
  }

  return final_gcd;
}

int main() {
  cout << "Running in c++" << endl;
  int T;
  cin >> T;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t=0; t<T; t++) {
    string input_numbers_string;
    getline(cin, input_numbers_string);
    vector<string> numbers_string = split_string(input_numbers_string);
    vector<int> numbers(numbers_string.size());

    for(int i=0; i<numbers_string.size(); i++) {
      numbers[i] = stoi(numbers_string[i]);
    }
    cout << "gcd(" << join_vector_string(numbers_string) << ") = "
         << gcd_multiple(numbers) << endl;
  }
  return 0;
}

string join_vector_string(vector<string> strings) {
  if (strings.size() < 1) {
    return "";
  }
  if (strings.size() < 2) {
    return strings[0];
  }
  
  string output = strings[0];
  for(int i=1; i<strings.size(); i++) {
    output.append(", " + strings[i]);
  }

  return output;
}

string myfunction(string x, string y) {
  return x + ", " + y;
}

vector<string> split_string(string input_string) {
  vector<string> splits;

  std::string delimiter = " ";

  size_t pos = 0;
  string token;
  while ((pos = input_string.find(delimiter)) != std::string::npos) {
    token = input_string.substr(0, pos);
    splits.push_back(token);
    input_string.erase(0, pos + delimiter.length());
  }
  token = input_string.substr(0, pos);
  splits.push_back(token);

  return splits;
}
