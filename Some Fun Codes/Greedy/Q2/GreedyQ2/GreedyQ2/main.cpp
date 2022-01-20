//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

vector<string> split_string(string);

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    size_t nRows = contests.size();
    size_t nCols = contests[0].size();
    int points{0};
    vector<int> dummyContest (nCols);
    int allowable = k;

    // Let's sort the consests based on their luck points
    for (int i = 0; i < (nRows-1); i++) {
        for (int j = 0; j < (nRows - 1 -i ); j++)
        {
            if (contests[j][0] < contests[j + 1][0]) {
                dummyContest = contests[j];
                contests[j] = contests[j + 1];
                contests[j + 1] = dummyContest;
            }
        }
    }

    // Let's add luck points
    for (size_t i = 0; i < nRows; i++)
    {
        cout << contests[i][0] << " " << contests[i][1] << endl;
        if (contests[i][1] == 0) {
            points += contests[i][0];
        }
        else if (allowable > 0) {
            points += contests[i][0];
            allowable--;
        }else
            points -= contests[i][0];

    }
    return points;
}

// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {

    size_t nRows = c.size();
    int dummyFlower;
    vector<int> flowerAmount(nRows);
    int price{ 0 };

    // Let's sort the flower prices
    for (int i = 0; i < (nRows - 1); i++) {
        for (int j = 0; j < (nRows - 1 - i); j++)
        {
            if (c[j] < c[j + 1]) {
                dummyFlower = c[j];
                c[j] = c[j + 1];
                c[j + 1] = dummyFlower;
            }
        }
    }

    for (int i = 0; i < nRows; i++) {
        flowerAmount[i]= i / k + 1;
        cout << " Amount of Flower: " << flowerAmount[i] << endl;
        price += flowerAmount[i] * c[i];
    }

    return price;
}
int main()
{

    ofstream fout("FlowerPrice.dat");

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int minimumCost = getMinimumCost(k, c);

    fout << minimumCost << "\n";

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