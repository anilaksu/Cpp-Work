//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {

    const int n = q.size();      // Size of the order array
    unsigned int counter = 0;    // Minimum number of bribes
    bool Chaos{ false };         // Boolean variable to denote if it is chaotic or not
    //cout << "Third Element is: " << q[2] <<", Size of an array is: " << n<< endl;

    for (int i = 0; i < n; i++) {
        if (i - q[i] == 0) {     // If swapped once
            counter++;
        }
        else if (i - q[i] > 0) { // If swapped more than one time
            Chaos = true;
        }

        if (Chaos == true)
            break;           // If someone  swapped more than once, let's break 
    }

    if (Chaos == true) {
        cout << "Too chaotic " << endl;
    } else
        cout << counter << endl;
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