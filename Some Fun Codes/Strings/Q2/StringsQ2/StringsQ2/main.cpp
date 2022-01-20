//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {

    const size_t n = s.size();
    int counter{ 0 };                   // Number of adjacent characters
    string s_modified;                  // 

    s_modified.push_back(s[0]);         // Let's store the first character 
    for (size_t i{ 1 }; i < n; ++i) {
        if (s[i] != s[i - 1])
            s_modified.push_back(s[i]);
        else
            counter++;
        cout << "Latest version of s is: " << s_modified << endl;
    }

    return counter;

}

// Complete the isValid function below.
string isValid(string s) {

    const size_t n = s.size();
    int location{0};                   // location of an element
    vector<int>  counter;
    string ans{"Yes"};                  // Answer to if a string is valid or not
    string s_unique{};
    
    s_unique.push_back(s[0]);          // Let's add the first element
    counter.push_back(0);              // Let's initiate the counter vector
    for (size_t i{ 0 }; i < n; i++) {
        location = s_unique.find(s[i]);
        //location = strchr(s_unique.c_str(), s[i]) - s_unique.c_str();
        //cout << "End postion is string is " << s_unique.npos << endl;
        //cout << "Location is " << location << endl;
       if (location == s_unique.npos) {
            s_unique.push_back(s[i]);      // append our unique character array
            counter.push_back(1);
        }
        else {
            counter[location]++;           // let's update our counter
        }

    }

    // Let's check how may times each unique charater is used 
    for (size_t i{ 1 }; i < counter.size(); i++) {
        if (counter[i - 1] != counter[i])
            ans = "No";
        //cout << "Number of unique is " << counter[i] << endl;
    }

    cout << "Unique string is " << s_unique << endl;
    return ans;
}

int main()
{

    ofstream fout("AdjacentChars.dat");

    string s;
    getline(cin, s);

    string result = isValid(s);

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