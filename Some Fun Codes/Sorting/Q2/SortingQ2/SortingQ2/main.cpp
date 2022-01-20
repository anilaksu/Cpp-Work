//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> 
#include "Competitor.h"
#include <array> 

using namespace std;

vector<string> split_string(string);

vector<int> getRanking(Competitor Competitors[], const int n) {

    vector<int> Rankings(n);
    int DummyRanking;
    Competitor DummyCompetitor;
    cout << "Number of Comptitors " << n << endl;
    for (int i = 0; i < n; i++) {
        Rankings[i] = i + 1;
    }

    for (int i = 0; i < (n-1); i++) {
        for (int j = 0; j < (n -1 - i); j++) {
            if (Competitors[j].getPoints() < Competitors[j + 1].getPoints()) {
                /*Let's swap competitor*/
                DummyCompetitor = Competitors[j];
                Competitors[j] = Competitors[j+1];
                Competitors[j+1] = DummyCompetitor;
                /*Let's swap competitor*/
                DummyRanking= Rankings[j];
                Rankings[j] = Rankings[j + 1];
                Rankings[j + 1] = DummyRanking;
            }
        }
    }

    return Rankings;
}


int main()
{

    ofstream fout("CompetitorRankings.dat");
    const int m = 5;
    Competitor Competitors[m];				            /*MyAccount object created by the definition in Competitor.h*/
    Competitor DummyCompetitor;
    vector<int> Rankings(m);                            /*Rankings */
    unsigned int competitorPoints;                      /* Dummy competitor points*/
    string competitorNames;

    /* Let's get Competitors */
    for (int i = 0; i < m; i++) {
        cout << "Please enter competitor's name" << endl;
        cin >> competitorNames;
        Competitors[i] = Competitor(competitorNames);
        cout << "Please enter " << Competitors[i].getName() << "'s points" << endl;
        cin >> competitorPoints;
        Competitors[i].setPoints(competitorPoints);
    }
    /* Let's get rankings*/
    Rankings = getRanking(Competitors, m);

    /*Let's output the rankings*/
    for (int i = 0; i < m; i++) {
        cout << "Competitor ID " << Rankings[i] << endl;
        fout << Competitors[i].getName() << " " << Competitors[i].getPoints() <<"\n";
    }
    
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