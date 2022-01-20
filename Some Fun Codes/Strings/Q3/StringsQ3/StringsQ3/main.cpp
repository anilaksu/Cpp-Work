//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the substrCount function below.
long substrCount(int n, string s) {

    int location{ 0 };                   // location of an element
    int j;                               // dummy index
    int  counter{0};
    string s_unique{};

    s_unique.push_back(s[0]);          // Let's add the first element
    for (size_t i{ 0 }; i < n; i++) {
        location = s_unique.find(s[i]);
        counter++;
        if (location == s_unique.npos) {
            s_unique.push_back(s[i]);      // append our unique character array
        }
        else if (i>1 && s[i] == s[i-2]){
            counter++;           // let's update our counter
            cout << "Substring is " << s.substr(i-2,3) << endl;
        }
        /*Longer than 3 characther palindromic substrings*/
        if (i> 0 && s[i] == s[i - 1]) {
            counter++;
            cout << "Substring is " << s.substr(i - 1, 2) << endl;
            j = i - 1;
            while (s[j] == s[i] && j > 0) {
                if (s[j - 1] == s[i + 1]) {
                    cout << "Substring is " << s.substr(j - 1, i + 2 - j) << endl;
                    counter++;           // let's update our counter
                    j--;
                } else
                        j=0;             // It is set to zero to break the loop
            }
        }

    }

    cout << "Unique string is " << s_unique << endl;
    return counter;
}

int main()
{

    ofstream fout("NumberSpecialString.dat");

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
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