/*
ID: jxu
PROG: gift1
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int NP;
    fin >> NP;
    map <string, int> bank;
    vector<string> names(NP); // stores name order 
    
    
    for (int i=0; i<NP; i++)
    {
        string name;
        fin >> name;
        names[i] = name;
        bank[name] = 0;
    }

    for(int j=0; j<NP; j++)
    {
        string giver;
        int money, recievers;
        fin >> giver;
        fin >> money >> recievers;

        for (int i=0; i<recievers; i++)
        {
            string r;
            fin >> r;
            // giving process
            bank[r] += money / recievers;
            bank[giver] -= money / recievers;
        }
    }

    for (int i=0; i<NP; i++)
    {
        fout << names[i] << " " << bank[names[i]] << '\n';
    }

    return 0;
}
