//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

vector<string> split_string(string);

// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {

    int l;                            // Dummy indice
    const int n = prices.size();      // Size of toys
    int CurrentPrice = 0;              //
    int DummyPrices;                  
    int MaxUnit, NoUnits = 0;                      // Maximumm number of toys to be purchased with k budget
    vector<int> PriceCombination ;

    for (int i = 0; i < n; i++) {
        CurrentPrice = prices[i];
        if (CurrentPrice < k) {
            NoUnits++;

            for (int j = i+1; j< n; j++){
                l = j;                                              // Let's intiate the dummy indice for while loop
                while (l < n) {
                    CurrentPrice = CurrentPrice + prices[l];        // Let's update the current price 
                    NoUnits++;                                       // Let's update the number of units
                    if (CurrentPrice < k) {
                        PriceCombination.push_back(NoUnits);
                        cout << "Current Number of Units: " << NoUnits << endl;
                        cout << "Current Price: " << CurrentPrice << endl;
                    }
                    else {
                        CurrentPrice = CurrentPrice - prices[l];
                        NoUnits--;
                    }
                    l++;
                }
                NoUnits = 1;                                       // Let's reset it to the value in the begining of the second for loop
            }
        }
        NoUnits = 0;                                                // let's reset NoUnits to zero for upcoming combinations
    }

    cout << "Current Number of combinations: " << PriceCombination.size() << endl;

    return *max_element(PriceCombination.begin(), PriceCombination.end());
}


int main()
{

    ofstream fout("MaxNumber.dat");

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split_string(prices_temp_temp);

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

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