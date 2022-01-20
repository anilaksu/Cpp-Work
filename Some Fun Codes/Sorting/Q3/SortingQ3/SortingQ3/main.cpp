//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

vector<string> split_string(string);

int getMedian(vector<int> expen_nDays) {

    const int n = expen_nDays.size();                      /*Length of data*/
    int Dummy;                                      /* Number of days with potential fraud activity*/
    int Median;
    /* Simple Bubble Sort*/
    for (int i = 0; i < (n-1); i++) {
        for (int j = 0; j < (n - 1 - i); j++) {
            if (expen_nDays[j] < expen_nDays[j + 1]) {
                Dummy = expen_nDays[j];
                expen_nDays[j] = expen_nDays[j+1];
                expen_nDays[j] = Dummy;
            }
        }
    }
    /*Let's get 2 times median*/
    if (n % 2 == 1) {
        Median = 2*expen_nDays[(n + 1) / 2];
    }
    else {
        Median = expen_nDays[(n)/2]+ expen_nDays[(n)/ 2 + 1];
    }

    return Median;
}


// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {

    const int n = expenditure.size();                      /*Length of data*/
    vector<int> expen_nDays(d);                             /*Fraud calculation day number*/
    int FraudDays = 0;                                      /* Number of days with potential fraud activity*/
    int Median;
    for (int i = d; i < n; i++) {
        for (int j=0; j<d; j++)
            expen_nDays[j] = expenditure[(i - d +j)];
        
        /* Let's calculate the median and check if there is a potential fraud*/
        Median = getMedian(expen_nDays);
        if (expenditure[i] >= Median)
            FraudDays++;
    }
    return FraudDays;
}

int main()
{

    ofstream fout("FraudDaysNumber.dat");

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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