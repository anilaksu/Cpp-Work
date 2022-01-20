//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

vector<string> split_string(string);

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {

    size_t nRows = arr.size();
    int dummy;
    int i_l; // Lower limit
    vector<int> array(k);
    int dist{ *max_element(arr.begin(),arr.end()) };

    cout << "Initial Distance: " << dist << endl;

    // Let's sort the flower prices
    for (int i = 0; i < (nRows - 1); i++) {
        for (int j = 0; j < (nRows - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1]) {
                dummy = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = dummy;
            }
        }
    }

    // Let's sort the flower prices
    for (int i = 0; i < (nRows - k-1); i++) {
        if (dist > arr[k + i-1] - arr[i]) {
            dist = arr[k + i-1] - arr[i];
            i_l = i;
        }
            
    }

    /*for (int i = 0; i < k; i++)
        array[i] = arr[i_l + i];

    // Let's update the distance
    dist = array[k-1]-arr[0];*/

    return dist;
}

int main()
{

    ofstream fout("MaxMin.dat");

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

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