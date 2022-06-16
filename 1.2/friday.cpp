/*
ID: jxu
PROG: friday
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int month_days[12] = 
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int t[7] = {}; // table with t[0] as Sunday
    int day = 1; // day counter, starts at Jan 1 1900
    int N;
    
    fin >> N;

    for(int year=1900; year<1900+N; year++)
    {
        bool is_leap = (year % 4 == 0) && 
            (year % 100 != 0 || year % 400 == 0);

        for (int m=0; m<12; m++)
        {
            t[(day+12)%7]++;
            day += month_days[m];
            if (m == 1 && is_leap) day++;
        }
    }
    
    // print table starting on Saturday
    for (int i=0; i<7; i++)
        fout << t[(i+6)%7] << ((i == 6) ? '\n' : ' ');

    return 0;
}
