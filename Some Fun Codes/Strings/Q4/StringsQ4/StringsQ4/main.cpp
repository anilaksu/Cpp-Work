//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the commonChild function below.
int commonChild(string s1, string s2) {

    const size_t n1 = s1.size();
    const size_t n2 = s2.size();

    vector<int> length{};              // location of an element
    int j,k;                               // dummy index
    vector<int>  counterVector;
    int counter{ 1 };
    int location_current, location_next; // Location of the current and next charaters
    string s_store{}, s_substore{}, s_common{};

    length.push_back(0);
    // Common characters
    for (size_t i{ 0 }; i < n2; i++) {
        if (s1.find(s2[i]) != s1.npos) {
            s_common.push_back(s2[i]);      // append our unique character array
        }
    }
    cout << "Common String: " << s_common << endl;
    /*Let's update*/
    if (s_common.size() > 0) {
        length.push_back(counter);
        for (size_t i{ 0 }; i < (s_common.size() - 1); i++) {
            s_store = s1;
            location_current = s1.find(s_common[i]);
            for (size_t j{ i+1 }; j < s_common.size(); j++) {
                location_next = s_store.find(s_common[j]);
                if (location_next > location_current) {
                    counter++;

                    s_substore.clear();               // Let's reset the storage string
                    s_substore = s_store.substr(0, location_next);

                    for (int k{location_next+1}; k< s_store.size(); k++)
                         s_substore.push_back(s_store[k]);

                    s_store.clear();               // Let's reset the storage string
                    s_store = s_substore;           // Let's renew the storage string to avoid repeating character conflict
                    cout << "Substring is: " << s_store << endl;
                    length.push_back(counter);
                    location_current = location_next - 1;
                }

            }
            s_store.clear();               // Let's reset the storage string
            counter = 1;                       // Let's reset the counter
        }
    }

    return *max_element(length.begin(),length.end());
}

int main()
{

    ofstream fout("ChildLength.dat");

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

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